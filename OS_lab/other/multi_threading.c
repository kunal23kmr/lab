#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *thread1_function(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        printf("T1: OK %d\n", i);
    }
    return NULL;
}
void *thread2_function(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        printf("T2: NOT OK %d\n", i);
    }
    return NULL;
}
int main()
{
    pthread_t thread1, thread2;
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
    printf("Main thread: Both threads have finished\n");
    return 0;
}
