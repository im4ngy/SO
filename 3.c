#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include<errno.h>

int main(int argc, char** argv){
   if(argc<3){
        printf("Error linea de comandos\n");
        exit(-1);
    }
    int i, status;
    pid_t pid, childpid;
    for(i=0; i<2; i++){
        pid=fork();
        if(pid==-1){
            printf("Error fork");
            exit(EXIT_FAILURE);
        }
        else if(pid==0){
            if(i==0){
                execlp(argv[1], argv[1], NULL);
                exit(EXIT_SUCCESS);
            }
            else{
                execvp(argv[2], &argv[2]);
                exit(EXIT_SUCCESS);
            }
        }
    }

    while((childpid=waitpid(-1, &status, WUNTRACED|WCONTINUED))>0){
        if(WIFEXITED(status)){
            printf("Hijo %d recogido\n", childpid);
        }
        if(WIFSIGNALED(status)){
            printf("Hijo %d terminado por señal\n", childpid);
        }
    }
    if(childpid==(pid_t)-1 && errno==ECHILD){
        printf("No mas hijos\n");
    }
    else{
        printf("Error waitpid\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
    return 0;
}