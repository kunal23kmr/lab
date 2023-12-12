#include <iostream>
#include <thread>
#include <pthread.h>
#include <cstdio> // Include the C standard I/O library for printf

using namespace std;

// Mutexes and a semaphore for readers count
pthread_mutex_t mutex;
pthread_mutex_t wrt;
int readCnt = 0;

void reader(int id)
{
    printf("Reader %d enter\n", id); // Use printf
    pthread_mutex_lock(&mutex);
    readCnt++;

    if (readCnt == 1)
    {
        pthread_mutex_lock(&wrt);
    }
    pthread_mutex_unlock(&mutex);

    printf("Reader: %d reading\n", id); // Use printf
    this_thread::sleep_for(chrono::milliseconds(1000));

    pthread_mutex_lock(&mutex);
    printf("Reader: %d leaving\n", id); // Use printf
    readCnt--;
    if (readCnt == 0)
    {
        pthread_mutex_unlock(&wrt);
    }
    pthread_mutex_unlock(&mutex);
}

void writer(int id)
{
    printf("Writer %d enter\n", id); // Use printf
    pthread_mutex_lock(&wrt);
    printf("Writer %d is writing\n", id); // Use printf
    this_thread::sleep_for(chrono::milliseconds(1000));
    printf("Writer %d is leaving\n", id); // Use printf
    pthread_mutex_unlock(&wrt);
}

int main()
{
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&wrt, NULL);

    thread writers(writer, 1);

    thread reader1(reader, 1);
    thread reader2(reader, 2);
    thread reader3(reader, 3);
    thread reader4(reader, 4);

    writers.join();
    reader1.join();
    reader2.join();
    reader3.join();
    reader4.join();

    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&wrt);

    return 0;
}
