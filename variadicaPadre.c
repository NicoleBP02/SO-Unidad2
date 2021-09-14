#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//función Padre 
int main(int argc, char** argv){
    pid_t pid_hijo;
    pid_t pid_hijo2;

    pid_hijo = fork();
    int ans = 1;
    int status;

    switch (pid_hijo)
    {
    case -1: /* Error */
        printf("Error al crear el proceso");
        return -1;
    case 0: /* Código ejecutado por el hijo */
        for (int i = 1; i < 11; i++)
        {
            ans *= i;
            printf("HIJO1: fact (%d): %d\n", i, ans);
        }
    break;
    default: {/* Código ejecutado por el padre */

            pid_hijo2 = fork();
            int ans2 = 1;
            switch (pid_hijo2)
            {
            case -1: /* Error */
                printf("Error al crear el proceso");
                return -1;
            case 0: /* Código ejecutado por el hijo */
                for (int i = 1; i < 11; i++)
                {
                    ans2 *= i;
                    printf("HIJO2: fact (%d): %d\n", i, ans2);
                }
            break;
            default: /* Código ejecutado por el padre */
                wait(&status); //espera que el acta de defunción de los hijos zombies
                wait(&status);
                printf("El padre terminó\n");
            }
        }
    }

}