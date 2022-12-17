#include<sys/types.h>
#include<errno.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>

int main(int argc, char**argv){
    if(argc!=2){
        printf("Error linea comandos");
        return 1;
    }
    int i, status, a=atoi(argv[1]);
    pid_t pid, childpid;
    for(i=0; i<a; i++){
        pid=fork();

        if(pid==-1){
            printf("Error en el fork\n");
            exit(EXIT_FAILURE);
        }

        else if(pid==0){
            printf("Soy el hijo %d de mi padre %d\n", getpid(), getppid());
            exit(EXIT_SUCCESS);
        }

        else{
            printf("Soy el padre %d\n",  getpid());
        }        
    }
    while((childpid=waitpid(-1, &status, WUNTRACED|WCONTINUED))>0){
        if(WIFEXITED(status)){
            printf("Yo %d he recoigo a mi hijo %d", getpid(), childpid);
        }
        else if(WIFSIGNALED(status)){
            printf("yo soy %d, mi hijo %d ha terminado por una señal", getpid(), childpid);
        }
    }
    if (childpid==(pid_t)-1 && errno==ECHILD)
    {
        printf("PROCESO PADRE %d,no hay mas hijos a los que esperar.Valor errno = %d ,definido como %s      \n", getpid() ,errno,strerror(errno));
    }
        else{
            ("Error en el waitpid");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    
    return 0;
}