//PEDIR UN NUMERO DE PROCESOS TOTALES . PROGRAMA A--> UN PADRE CON N HIJOS. PROGRAMA B--> N HIJOS CON 1 PADRE

//CADA HIJO DEBE MOSTRAR SU PID Y EL DE SU PADRE, Y DEBE TENER UNA SALIDA CON CODIGO 0--> (EXIT_SUCCESS)

//A)

#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
    int n, status;
    pid_t childpid;

    printf("INTUDUZCA EL NUMERO DE HIJOS\n");
    scanf( "%d",&n);
    printf("SOY EL PADRE Y MI PID ES %d \n", getpid());

    for(int i=0;i<n;i++)
    {
        switch(fork())
        {
            case -1:
            
                printf("ERROR AL CREAR AL HIJO  \n");
            	exit(EXIT_FAILURE);
            

            case 0:
            
                printf("SOY EL HIJO NUMERO ES %d Y MI PID ES %d \n" , i+1 ,getpid());
            	exit(EXIT_SUCCESS);
            

            default:
            
                printf("SOY EL PADRE Y MI PID ES %d. ESPERO A MI HIJO %d     \n", getpid(), i+1 );
            

        }
    }
    while((childpid=waitpid(-1, &status, WUNTRACED|WCONTINUED)) >0 )
    {
        if(WIFEXITED(status))
        {
            {
                printf("SOY EL PADRE Y MI PID ES %d, EL PID DE MI HIJO FINALIZADO ES %ld,STATUS %d     \n" , getpid(), (long int)childpid,WEXITSTATUS(status));
            }
        }
        else if (WIFSIGNALED(status))
        {
            {
                printf("SOY EL PADRE Y MI PID ES %d, EL PID DE MI HIJO %ld FINALIDO AL RECIBIR LA SEÑAL %d      \n", getpid(), (long int)childpid, WTERMSIG(status));
            }
        }
    }
    if (childpid==(pid_t)-1 && errno==ECHILD)
    {
        printf("PROCESO PADRE %d,no hay mas hijos a los que esperar.Valor errno = %d ,definido como %s      \n", getpid() ,errno,strerror(errno));
    }
    else
    {
        printf("ERROR EN LA INVOCACION DE WAIT O DEL WAITPAID. VALOR ERRNO = %d, DEFINIDO COMO %s       \n",errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);

}
