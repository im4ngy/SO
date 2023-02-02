/*Implemente dos programas que pidiendo un número de procesos totales N por línea de
argumentos cree las siguientes jerarquías de procesos:
Programa a) Cree un abanico de procesos como el que se refleja en la primera figura.
Programa b) Lo mismo, pero recreando lo que representa la segunda figura.*/
#include <stdio.h>
#include <stdlib.h> //exit_failure
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

void childProcess(){
    printf("Soy el proceso hijo %d y mi padre es %d\n", getpid(), getppid());
    exit(EXIT_SUCCESS); //recuerda que el hijo debe terminar
};

void ParentProcess(){
    printf("Soy el proceso padre %d y he tenido un hijo\n", getpid());
};

int main (int argc, char** argv){
    if(argc!=2){
        printf("Error línea de comandos\n");
        exit(EXIT_FAILURE); //1
    }
    int x=atoi(argv[1]), status;
    pid_t pid, childpid;
    for(int i=0; i<x; i++){
        pid=fork();
        if(pid<0){
            printf("Error creación proceso\n");
            exit(EXIT_FAILURE);
        }
        else if(pid==0){
            childProcess(); //llevo mi hijto al cole a hacer cosas
        }
        else{
            ParentProcess();
        }
    }

    //recogida del cole
    while((childpid=waitpid(-1, &status, WUNTRACED|WCONTINUED))>0){
        if(WIFEXITED(status)){
            printf("Soy el proceso padre %d y he recogido mi hijo %d\n", getpid(), childpid); 
        }
        if(WIFSIGNALED(status)){
            printf("Soy el proceso padre %d y mi hijo %d ha terminado por una senial %d\n", getpid(), childpid, errno);
        }      
    }

    if(childpid==(-1)){
        printf("Soy el proceso padre y he termiando de recoger a mis hijos\n");
    }  
    else{
        printf("Error waitpid\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}