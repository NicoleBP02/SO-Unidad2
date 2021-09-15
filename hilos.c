#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* imprime_x(void *param){
    for (int i = 0; i < 1000; i++) printf("x");
    return NULL;
}

int main(int argc, char *argv[]){
    pthread_t threadID;
    pthread_create(&threadID,NULL,&imprime_x,NULL);
    for (int j = 0; j < 1000; j++) printf("y");
    exit(EXIT_SUCCESS);
}