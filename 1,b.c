//PEDIR UN NUMERO DE PROCESOS TOTALES . PROGRAMA A--> UN PADRE CON N HIJOS. PROGRAMA B--> N HIJOS CON 1 PADRE

//CADA HIJO DEBE MOSTRAR SU PID Y EL DE SU PADRE, Y DEBE TENER UNA SALIDA CON CODIGO 0--> (EXIT_SUCCESS)

//B)

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int n, status;
    
    
    printf("INTRODUZCA LA CANTIDAD DE HIJOS QUE DESEA : \n");
    scanf("%d",&n);

	        
    printf("SOY EL PRIMER PADRE Y MI PID ES %d \n ", getpid());

    for(int i=0;i<n;i++)
    {
        switch (fork())
    
        {
            case -1:
            
            printf("ERROR A LA HORA DE CREAR EL HIJO \n");
            exit(EXIT_FAILURE);
            

            case 0:
            
                printf("SOY EL HIJO NUMERO %d CON ID %d Y MI PADRE ES %d \n", i+1 ,getpid() ,getppid() );
                break;
            

            default:
                printf("ESPERANDO A QUE EL  HIJO %d ACABE \n", i+1);
		wait(&status);
		printf("EL HIJO CON ID %d HA FINALIZADO CON CODIGO DE SALIDA %d \n", getpid(), WEXITSTATUS(status));
            exit(EXIT_SUCCESS);
        }
    }
}
