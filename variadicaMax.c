#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//función que encuentra el máximo
int main(int argc, char** argv){
    int max= 0;
    for(int i=1;i<argc;i++){
        if(atoi(argv[i]) > max){
            max = atoi(argv[i]);
        }
    }
    
    printf("MÁXIMO: %d\n",max);
}