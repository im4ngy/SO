/*Implemente dos programas que pidiendo un número de procesos totales N por línea de
argumentos cree las siguientes jerarquías de procesos:
Programa b) Lo mismo, pero recreando lo que representa la segunda figura.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include<errno.h>


int main(int argc, char** argv){
    if(argc!=2){
        printf("Error en linea de argumentos\n");
        exit(EXIT_FAILURE);
    }
    int x=atoi(argv[1]), status;
    pid_t pid, childpid;
    for(int i=0; i<x; i++){
        pid=fork(); //con fork creo un proceso y al igualarlo a pid hago que su num de proceso se guarde en pid
        if(pid<0){
            printf("Error fork\n");
            exit(EXIT_FAILURE);
        }
        if(pid==0){
            printf("Soy el proceso hijo %d, mi padre es el proceso %d\n", getpid(), getppid());
        }
        else{
            printf("Soy el proceso padre %d\n", getpid());
            while((childpid=wait(&status))>0){
                if(WIFEXITED(status)){
                    printf("Yo %d he recogido a mi hijo %d\n", getpid(), childpid);
                }
                if(WIFSIGNALED(status)){
                    printf("Yo %d he recogido a mi hijo %d que ha terminado por la siguiente señal%d \n", getpid(), childpid, errno);
                }
            }
            if(childpid==(-1)){
                printf("Hijos recogidos\n");
                exit(EXIT_SUCCESS);
            }
            else{printf("gsdggf"); exit(EXIT_FAILURE);}
        }
    }

    return 0;
}