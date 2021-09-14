#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//función que calcula el promedio
int main(int argc, char** argv){
    int suma = 0;
    for(int i=0;i<argc;i++){
        suma += atoi(argv[i]);
        //printf(" %d\n",suma);
    }

    float prom = suma/argc;
    printf("PROMEDIO: %f\n",prom);
}