
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
  
pthread_t tid[2];
int counter;
pthread_mutex_t lock;
  
void* trythis(void* arg)
{
    pthread_mutex_lock(&lock);
  
    unsigned long i = 0;
    counter += 1;
    printf("Job %d has started\n", counter);
  
    for (i = 0; i < (0x20000000); i++)
        ;
  
    printf("Job %d has finished\n", counter);
  
    pthread_mutex_unlock(&lock);
  
    return NULL;
}
  
int main(void)
{
    int i = 0;
    int error;

    printf("Start init mutex\n");
  
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("mutex init has failed\n");
        return 1;
    }

    while (i < 2) {
        printf(" -- create thread %i\n",i);
        error = pthread_create(&(tid[i]),
                               NULL,
                               &trythis, NULL);
        if (error != 0)
            printf("Thread can't be created :[%s]",
                   strerror(error));
        i++;
    }

    printf(" -- thread 1 join\n");
    pthread_join(tid[0], NULL);
    printf(" -- thread 2 join\n");
    pthread_join(tid[1], NULL);

    printf(" -- mutex done destroy\n");

    pthread_mutex_destroy(&lock);
  
    return 0;
}