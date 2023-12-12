#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t lock;
void *thread1_function(void *arg)
{
    for (int i = 0; i < 6; i++)
    {
        pthread_mutex_lock(&lock);
        printf("T1: OK %d\n", i);
        pthread_mutex_unlock(&lock);
        // Sleep briefly to yield the CPU
        usleep(1);
    }
    return NULL;
}
void *thread2_function(void *arg)
{
    for (int i = 0; i < 6; i++)
    {
        pthread_mutex_lock(&lock);
        printf("T2:NOT OK %d\n", i);
        pthread_mutex_unlock(&lock);
        usleep(1);
    }
    return NULL;
}
int main()
{
    pthread_t thread1, thread2;
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        fprintf(stderr, "Mutex initialization failed\n");
        return 1;
    }
    if (pthread_create(&thread1, NULL, thread1_function, NULL))
    {
        fprintf(stderr, "Error creating thread 1\n");
        return 1;
    }
    if (pthread_create(&thread2, NULL, thread2_function, NULL))
    {
        fprintf(stderr, "Error creating thread 2\n");
        return 1;
    }
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_mutex_destroy(&lock);
    printf("Main thread: Both threads have finished\n");
    return 0;
}
