//crear 2 hijos. Uno de ellos que abra la calculadora y el otro un editor de texto 
//Que el padre espere a sus hijos 

#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>


int main(int argc,char const *argv[])
{     
    int status;
    pid_t child_1,child_2;
    int n;
    
    for (int i=1;i<=n;i++)
    {
        switch(fork())
        {
            case -1:
           
            printf("ERROR EN LA CREACION DEL HIJO\n");
            exit(EXIT_FAILURE);
            

            case 0:
            
                printf("CREACION DE EL HIJO %d CON PID %d \n", i+1,getpid());
                if (i==1)
                {
                    execlp(argv[i], argv[i], NULL);
                    i++;
                }
                else 
                {
                    execlp(argv[1], argv[1], NULL);
                }
            exit(EXIT_SUCCESS);

            default:
                printf("ESPERANDO A QUE SE CREE MI HIJO NUMERO %d \n", i+1);
            
        }
    }
    child_1=wait(&status);
    printf("MI HIJO %d CON CODIGO DE SALIDA %d HA ACABADO \n",child_1, WEXITSTATUS(status) );
    
    child_2=wait(&status);
    printf("MI HIJO %d CON CODIGO DE SALIDA %d HA ACABADO \n",child_2, WEXITSTATUS(status) );

    exit(EXIT_SUCCESS);

}



//     ./miPrograma gnome-calculator gedit fichero1.txt fichero2.txt ficheroN.txt

