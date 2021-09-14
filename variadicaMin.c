#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//función que encuentra el mínimo
int main(int argc, char** argv){
    int min = 1000000;
    for(int i=1;i<argc;i++){
        if(atoi(argv[i]) < min){
            min = atoi(argv[i]);
        }
    }

    printf("MINIMO: %d\n",min);
}