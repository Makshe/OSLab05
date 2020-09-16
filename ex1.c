#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int n = 1;
void *threadGambino(void *vargp){
    sleep(1);
    printf("And its text message\n");
    n++;
    return NULL;

}
int main() {
    pthread_t threadID;
    for(int i = 0; i < 10; i++){
        printf("Thread created\n");
        printf("Thread #%d\n", n);
        pthread_create(&threadID, NULL, threadGambino, NULL);
        pthread_join(threadID, NULL);
        printf("Exiting thread\n\n");
    }
    exit(0);

}
