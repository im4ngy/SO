// proceso que tenga un hijo y que acabe inmediatamente (imprima su id y acabe). deje dormir al padre con sleep() durante 20 seg {sleep(20)}
//y acabe con un exit(EXIT_SUCCESS) sin recojer al hijo.
#include<iostream>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<wait.h>
#include<unistd.h>
#include<stdio.h>

int main ()
{
    int status;
    pid_t childpid;

    switch(fork())
    {
        case -1:
            printf("ERROR A LA HORA DE CEARSE UN HIJO\n");
        exit(EXIT_FAILURE);

        case 0:
            printf("SOY EL PADRE Y MI PID ES %d, Y EL PID DE MI HIJO ES %d\n", getppid(), getpid());
        exit(EXIT_SUCCESS);

        default:
        
            printf("SOY EL PADRE CON PID %d Y PROCEDO A ESPERAR A MI HIJO DURANTE 20 SEGUNDOS, DESPUES DE ESO ME VOY\n", getpid());
            sleep(20);
            wait(&status);
            printf("PROCESO FINALIZADO CON CODIGO DE SALIDA %d \n", WEXITSTATUS(status));
            sleep(20);
        exit(EXIT_SUCCESS);
        

    }
    exit(EXIT_SUCCESS);
}
