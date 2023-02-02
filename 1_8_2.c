/*Creo otro programa aparte que reciba por línea de argumentos un PID de un proceso, y su cometido
sea enviar una señal SIGUSR1 al proceso cuyo PID ha recibido por dicha línea de argumentos. Una
vez enviada la señal SIGUSR1 esperará durante 1 segundo y enviará al mismo proceso al que envió
la señal SIGUSR1 la señal de KILL. Compruebe por consola si el proceso al que ha enviado ambas
señales existe ya en el sistema*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include <unistd.h>

void main(int argc, char** argv){
    if(argc!=2){
        printf("Error linea de argumentos\n");
        exit(EXIT_FAILURE);
    }
    int long x=atoi(argv[1]);
    sleep(3);
    kill(x, SIGUSR1);
    sleep(5);
    kill(x, SIGKILL);

}