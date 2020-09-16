#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int pSleep = 0; //flag to set producer sleep
int cSleep = 0; //flag to set consumer sleep
int buffer [20]; //imitating buffer
int pos = 0;     //keeping track of how full our buffer is
int timer = 0;   //counting number of threads

void *Producer(void *vargp){
    while(1){
        if (pSleep)
            continue;
        else if(pos == 20){ //if pos = 20, the buffer is full
            pSleep = 1; //setting producer sleep
            cSleep = 0; //waking up consumer
            printf("time spend = %d\n", timer);
            timer++;    //incrementing timer
            continue;
        }
        buffer[pos] = 1;
        pos++;  //incrementing pos (fulling up buffer)
    }
    pthread_exit(NULL);
    return 0;

}

void *Consumer(void *vargp){
    while(1){
        if(cSleep)
            continue;
        else if(pos == 0){  //if pos is 0, we the buffer is empty
            cSleep = 1;  //setting consumer sleep
            pSleep = 0;  //waking up producer
            printf("Entered consumer at t = %d\n", timer);
            timer++; //incrementing timer
            continue;
        }
        buffer[pos] = 0;
        pos --; //decrementing pos (emptying buffer)
    }
    pthread_exit(NULL);
    return 0;

}



int main() {
    pthread_t producer, consumer;
    pthread_create(&producer, NULL,Producer, NULL);
    pthread_create(&consumer, NULL, Consumer, NULL);
    while(1);
    return 0;
    //stopped at timer = 8456501


}
