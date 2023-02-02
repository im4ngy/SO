/*Realizar un programa que capture la señal de alarma, de manera que imprima la cadena “RING”
pasados 5 segundos, después pasados otros 3 segundos y por último cada segundo. Implementar
esto último, utilizando un bucle infinito que vaya imprimiendo el número de timbrazos. Pasados 4*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void func(int i){
    printf("RING\n");
}

int temporizador(int time){
    alarm(time);
    pause();

}

void main(){
    if(signal(SIGALRM, func)){
        exit(EXIT_FAILURE);
    }
    for(int i=5; i<6; i=i-2){
        if(i<1){ i=1;}
        kill(getpid(), temporizador(i));
    }
}