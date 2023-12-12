#include <iostream>
#include <thread>
#include <pthread.h>

// semaphores
int readCnt = 0;
pthread_mutex_t mutex ;
pthread_mutex_t wrt ;
void reader(int id)
{
    pthread_mutex_lock(&mutex); // wait(mutex);
    readCnt++;

    if (readCnt == 1)
    {
        pthread_mutex_lock(&wrt);// wait(wrt);
    }
    printf("Reader: %d reading\n",id);
    pthread_mutex_unlock(&mutex); //signal(mutex)

    this_thread::sleep_for(chrono::milliseconds(1));

    pthread_mutex_lock(&mutex); // wait(mutex);
    printf("Reader: %d leaving\n", id);

    readCnt--;
    if (readCnt == 0)
    {
        pthread_mutex_unlock(&wrt);//signal(wrt)
    }
    pthread_mutex_unlock(&mutex); // signal(mutex)
}

void writer(int id)
{
    pthread_mutex_lock (&wrt);// wait(wrt);
    printf("Writer: %d writing\n", id);

    this_thread::sleep_for(chrono::milliseconds(1));

    printf("Writer: %d leaving\n", id);

    pthread_mutex_unlock(&wrt); // signal(wrt)
}
int main()
{
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&wrt, NULL);

    thread reader1(reader, 1);
    thread reader2(reader, 2);
    thread reader3(reader, 3);
    thread reader4(reader, 4);

    thread writers(writer, 1);

    reader1.join();
    writers.join();
    reader2.join();
    reader3.join();
    reader4.join();

    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&wrt);

    return 0;
}

