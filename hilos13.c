#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct threadParam_t
{
    char character;
    int counter;
};

void* imprime(void *parg){
    struct threadParam_t *pargTmp = (struct threadParam_t *)parg;
    for(int i = 0; i < pargTmp->counter;i++){
        printf("%c",pargTmp->character);
    }
    return NULL;
}

int main(int argc, char *argv[]){
    pthread_t threadID1;
    pthread_t threadID2;

    struct threadParam_t threadParam1 = {'a',3000};
    struct threadParam_t threadParam2 = {'b',2000};

    pthread_create(&threadID1,NULL,&imprime, &threadParam1);
    pthread_create(&threadID2,NULL,&imprime, &threadParam2);

    //será necesario que el hilo principal espere a que los dos 
    //hilos creados terminen antes de que el terminar.
    pthread_join(threadID1,NULL); 
    pthread_join(threadID2,NULL);

    exit(EXIT_SUCCESS);
}