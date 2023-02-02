/*Use por ejemplo el ejercicio 1a) y cree una variable global de tipo entero inicializada a 0. Haga que
cada hijo aumente en uno el valor de esa variable global y que el padre imprima el resultado final.
¿Qué ocurre? Correcto, su valor no se modifica porque los hijos son procesos nuevos que no
comparten memoria. Para ello, y concretamente en sistemas basados en POSIX, se utilizan métodos
de intercomunicación de procesos como son memoria compartida y semáforos, los cuales se
estudiarán en otra práctica de la asignatura.*/

#include <stdio.h>
#include <stdlib.h> //exit_failure
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <pthread.h>

pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;
int global=0;

void childProcess(){
    pthread_mutex_lock(&mtx); //entrada
    global++;
    pthread_mutex_unlock(&mtx); //salgo
    printf(" %d \n", global);
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
            printf("audhewu\n");
            childProcess(); //llevo mi hijto al cole a hacer cosas
            printf("audhewu\n");
        }
        else{
            ParentProcess();
        }
    }

    //recogida del cole
    while((childpid = waitpid(-1, &status, WUNTRACED |WCONTINUED))>0){
        if (childpid == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }


        if (WIFEXITED(status)) {
            printf("child exited, status=%d\n", WEXITSTATUS(status));


        } else if (WIFSIGNALED(status)) {
            printf("child killed (signal %d)\n", WTERMSIG(status));


        } else if (WIFSTOPPED(status)) {
            printf("child stopped (signal %d)\n", WSTOPSIG(status));


#ifdef WIFCONTINUED     /* Not all implementations support this */
        } else if (WIFCONTINUED(status)) {
            printf("child continued\n");
#endif
        } else {    /* Non-standard case -- may never happen */
            printf("Unexpected status (0x%x)\n", status);
        }
    } 


    if(childpid==(pid_t)-1 && errno==ECHILD){
        printf("Soy el proceso padre y he termiando de recoger a mis hijos\n");
        printf("La variable global vale %d\n", global);
    }  
    else{
        printf("Error waitpid\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}