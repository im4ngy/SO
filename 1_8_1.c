/*Realizar un programa que este permanentemente a la espera de capturar una señal SIGUSR1 (en un
bucle while(1) infinito por ejemplo), de forma que cuando la capture imprima su PID. Compílelo y
láncelo por consola.

Creo otro programa aparte que reciba por línea de argumentos un PID de un proceso, y su cometido
sea enviar una señal SIGUSR1 al proceso cuyo PID ha recibido por dicha línea de argumentos. Una
vez enviada la señal SIGUSR1 esperará durante 1 segundo y enviará al mismo proceso al que envió
la señal SIGUSR1 la señal de KILL. Compruebe por consola si el proceso al que ha enviado ambas
señales existe ya en el sistema*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void fun(){
    printf("He capturado la senial y mi pid es %d\n", getpid());
}

void main(){
    if(signal(SIGUSR1, fun)){
        printf("Error \n");
        exit(EXIT_FAILURE);
    }
    while(1);
}