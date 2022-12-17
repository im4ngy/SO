#include <signal.h>
#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>

void sig_alarm(int sig){
    printf("RING");
}

int temporizador(int time){
    alarm(time);
    pause();
}

int main(){    
    if(signal(SIGALRM, sig_alarm)){
        exit(EXIT_FAILURE);
    }
    kill(getpid(), temporizador(5));
    return 0;
}