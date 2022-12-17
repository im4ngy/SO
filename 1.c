#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>

int main(int argc, char **argv){
    if(argc!=2){
        printf("Error línea de argumentos");
        exit(-1);
    }
    pid_t pid, childpid;
    int i, status, a=atoi(argv[1]);
    printf("Se van a crear %i procesos\n", a);
    for(i=0; i<a; i++){
        pid=fork();
        if(pid==-1){
            printf("Error en el fork\n");
            exit(EXIT_FAILURE);
        }
        else if(pid==0){
            printf("Soy el hijo %d de mi padre %d\n", getpid(), getppid());
        }
        else{
            printf("Soy el padre %d\n",  getpid());
            while(childpid=wait(&status)){
            if(childpid>0){
                if (WIFEXITED(status)) //si es distinto de 0 es vdd
                {
                    printf("Hijo %d recogido, status=%d\n",childpid, WEXITSTATUS(status));
                } 
                else if (WIFSIGNALED(status)) 
                {
                    printf("Hijo %d matado (signal %d)\n", childpid, WTERMSIG(status));
                } 
            }
            else 
            {
                printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una señal.\n");
                exit(EXIT_FAILURE);
            }
            exit(EXIT_FAILURE);
            }
        }        
    }
    
    printf("Llega al final\n");
    return 0;
}