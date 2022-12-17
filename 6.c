//programa que capture una señal de alarma. IMPRIME RING a los 5 seg, luego 3 seg y por ultimo cada seg, en un bucle infinito
//que imprima el numero de tonos. a los 4 timbrazos la alarma se para con una funcion kill()

#include <sys/types.h>

#include <stdlib.h>

#include <stdio.h>

#include <unistd.h>

#include <errno.h>

#include <sys/wait.h>

#include <signal.h>

void sig_alarm(int signo)
{

	printf(" RING");

	printf(" Valor señal: %d\n", signo);

	return; 

}



int temporizador(int time)
{

    alarm(time);
    pause();

}

int main()
{
    int n=0;

    if(signal(SIGALRM, sig_alarm) == SIG_ERR)
	{

		perror("sig error");

		printf(" Errno value: %d\n", errno);

		exit(EXIT_FAILURE);

	}


    printf("ALARMA EN 5 SEG \n");
    
    kill(getpid(),temporizador(5));

    printf("ALARMA EN 3 SEG\n");
    
    kill(getpid(),temporizador(3));
    
    while(n>=0)
    {
        printf("ALARMA EN 1 SEG \n");   
        kill(getpid(),temporizador(1));
        
        n++;

        if(n==5) kill(getpid(),SIGKILL);

    } 

    exit(EXIT_SUCCESS);
        
    return 0;

}