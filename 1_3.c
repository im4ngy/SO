/*Implemente un programa donde se creen dos hijos. Uno de ellos que abra la calculadora de su
distribución de Linux (busque como se llama ese ejecutable) y el otro que abra un editor de textos
con N ficheros pasados como argumentos (recuerde hacer que el padre espere a los hijos). Use para
ello la familia de funciones exec().
Un ejemplo de invocación sería:
./miPrograma gnome-calculator gedit fichero1.txt fichero2.txt ficheroN.txt*/
#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>



int main(int argc, char**argv){
    pid_t pid, childpid;
    int status;
    for(int i=0; i<2; i++){
        pid=fork();
        if(pid<0){
            printf("Error fork\n");
            exit(EXIT_FAILURE);
        }
        if(pid==0){
            if(i==0){
                
                int x=execlp(argv[1], argv[1], NULL);
                if(x==(-1)){
                    printf("Error execl\n");
                    exit(EXIT_FAILURE);
                }
                exit(EXIT_SUCCESS);
            }
            else if(i==1){
                int y=execvp(argv[2], &argv[2]);
                exit(EXIT_SUCCESS);
            }
        }
        else{ printf("Soy el proceso padre %d, no hago nada\n", getpid());}
    }

    while((childpid=wait(&status))>0){
        if(WIFEXITED(status)){
            printf("He recogido a mi hijo %d\n", childpid);
        }
        if(WIFSIGNALED(status)){
            printf("He recogido a mi hijo %d terminado por la senial %d\n", childpid, errno);
        }
    }
    if(childpid==(-1)){printf("He recogido todos los procesos\n"); exit(EXIT_SUCCESS);}
    else{printf("error wait\n"); exit(EXIT_FAILURE);}

    return 0;
}