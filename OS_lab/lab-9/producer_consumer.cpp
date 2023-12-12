#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
using namespace std;

const int buffer_size = 5;
queue<int> buffer;
mutex mtx;
condition_variable buffer_not_full, buffer_not_empty;

void producer(int id)
{
    for (int i = 0; i < 5; ++i)
    {
        this_thread::sleep_for(chrono::milliseconds(100));
        int item = i;
        {
            unique_lock<mutex> lock(mtx);
            buffer_not_full.wait(lock, []{ return buffer.size() < buffer_size; });
            buffer.push(item);
            cout << "Producer produced item " << item << endl;
            buffer_not_empty.notify_all();
        }
    }
}

void consumer(int id)
{
    for (int i = 0; i < 5; ++i)
    {
        int item;

        {
            unique_lock<mutex> lock(mtx);
            buffer_not_empty.wait(lock, []
                                  { return !buffer.empty(); });
            item = buffer.front();
            buffer.pop();
            buffer_not_full.notify_all();
        }

        this_thread::sleep_for(chrono::milliseconds(200));
        cout << "Consumer consumed item " << item << endl;
    }
}

int main()
{
    thread producers;
    thread consumers;

    producers = thread(producer, 1);
    consumers = thread(consumer, 1);

    producers.join();
    consumers.join();

    return 0;
}