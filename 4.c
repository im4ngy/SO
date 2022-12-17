#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<errno.h>

int main(int argc, char**argv){
    //control linea argmuentos
    int i, status;
    pid_t pid, childpid;


        for (i=0; i<2; i++){
            pid=fork();
            if(pid==-1){
                printf("Error fork");
                exit(EXIT_FAILURE);
            }
            else if(pid==0){
                if(i==0){
                    execlp("./f","./f", argv[1], NULL);
                    exit(EXIT_SUCCESS);
                }
                else if(i==1){
                    execlp("./f", "./f", argv[2], NULL);
                    exit(EXIT_SUCCESS);
                }
            }
        }


    while((childpid=waitpid(-1, &status, WUNTRACED|WCONTINUED))>0){
        if (WIFEXITED(status))
        {
            printf("Hijo %d recogido", childpid);
        }
        if (WIFSIGNALED(status)){
            printf("Hijo %d terminado por señal", childpid);
        }
    }
    if(childpid==(pid_t)-1 && errno==ECHILD){
        printf("Todods los hijos recogidos");
    }
    else{
        printf("Error waitpid");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
    return 0;
}