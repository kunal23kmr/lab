#include <iostream>
#include <thread>
using namespace std;
void t1(int *value)
{
    this_thread::sleep_for(chrono::milliseconds(100));
    *value = 2 * (*value);
    cout << "In thread 1, value:(value*2) = " << *value << endl;
}

void t2(int *value)
{
    *value = (*value) / 2;
    cout << "In thread 2, value:(value/2) = " << *value << endl;
}

int main()
{
    thread thread1;
    thread thread2;

    int *value = new int(5);
    cout << "Value before thread executed:" << *value << endl;

    thread1 = thread(t1, value);
    thread2 = thread(t2, value);

    thread1.join();
    thread2.join();

    cout << "Value after thread executed:" << *value << endl;

    return 0;
}