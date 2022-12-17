//programa que mande una señal a cada hijo cada 5 seg.

#include <sys/types.h>

#include <sys/wait.h>

#include <signal.h>

#include <stdio.h>

#include <stdlib.h>

#include <errno.h>

#include <unistd.h>


void tratarSennal(int n){
  printf("Mensaje para mi papá \n");
}

int main(int argc, char* argv[])
{
    int status;
    pid_t child;
    int n=0;

    switch(fork())
    {
        case -1:
            printf("ERROR AL CREAR AL HIJO \n");
            exit(EXIT_FAILURE);

        case 0:
            signal(SIGUSR1, tratarSennal);
            for(int i =0;i<5;i++)
            {
                pause();
            }
            sleep(1);
            exit(EXIT_SUCCESS);

        default:
            printf("ESPERANDO A QUE MI HIJO ACABE \n");
            for (int i = 0; i<5; i++)
            {
            sleep(1);
            kill(child, SIGUSR1); 
            }

            sleep(1);
            kill(child, SIGKILL); 
            wait(&status);
            printf("Hijo finalizado con código de salida %d \n", WEXITSTATUS(status));
    }

}



