/*Realizar un programa padre que expanda un hijo y al cual le envíe cada 1 segundo una señal
personalizada de usuario SIGUSR1. El hijo debe imprimir un mensaje en pantalla cada vez que
recibe la señal del padre, tratándola en una función aparte llamada tratarSennal(). Enviados 5
mensajes los procesos deben salir. Utiliza las funciones signal() y kill().*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

void fun(){
    printf("Mi padre me mando una senial\n");
}

void main(){
    int status;

    pid_t pid;
    pid=fork();

    switch(pid){
        case -1:
            printf("error fork\n");
            exit(EXIT_FAILURE);
        case 0:
            if(signal(SIGUSR1, fun)){
                printf("Error\n");
                exit(EXIT_FAILURE);
            }
            for(int i=0; i<5; i++){
                pause();
            }
            printf("Aqui pid vale %d y mi pid es %d\n", pid, getpid());
            exit(EXIT_SUCCESS);
            
        default:
            printf("Soy el papa %d, de %d\n", getpid(), pid);
            for(int i=0; i<5; i++){
                sleep(1);
                kill(pid, SIGUSR1);
            }
            sleep(2);
            kill(pid, SIGKILL);
            sleep(2);
            pid=wait(&status);
            printf("Hijo %d recogido\n", pid);
    }

}