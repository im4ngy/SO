/*Cree un programa que reciba por la linea de argumentos un número y calcule el factorial de ese
número. Compílelo y compruebe su funcionamiento. 

A partir de ahí cree otro programa aparte que reciba dos números enteros como parámetros en la linea de argumentos y cree dos procesos hijos,
de manera que cada uno calcule el factorial de uno de los números usando el ejecutable creado
anteriormente (“./a.out 3 5”), use para ello la familia de funciones exec(). En el programa que
calcula el factorial ponga un sleep(1) entre los cálculos parciales para poder observar en consola
como se van ejecutando los dos procesos que se lanzarán en paralelo.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

void main(int argc, char** argv){
    if(argc!=3){
        printf("Error línea de argumentos\n");
        exit(EXIT_FAILURE);
    }
    int status;
    pid_t pid, childpid;
    for(int i=0; i<2; i++){
        pid=fork();
        if(pid==0){
            if(i==0){
                execlp("./fac", "./fac", (argv[1]), NULL);
                exit(EXIT_SUCCESS);
            }
            if(i==1){
                execlp("./fac", "./fac", (argv[2]), NULL);
                exit(EXIT_SUCCESS);
            }
        }
        else{
            printf("Soy el padre %d\n", getpid());
        }
        
    }
    while((childpid=wait(&status))>0){
        if(WIFEXITED(status)){
            printf("Yo %d he recogido a mi hijo %d\n", getpid(), childpid);
        }
        else if(WIFSIGNALED(status)){
            printf("Yo %d he recogido a mi hijo %d que termino por la senial %d", getpid(), childpid, errno);
        }
    }
    if(childpid==(-1)){
        printf("Se han recogido todos los hijos\n");
        exit(EXIT_SUCCESS);
    }
    else{
        printf("Error wait\n");
        exit(EXIT_FAILURE);
    }
}