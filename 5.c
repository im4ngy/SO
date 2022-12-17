/*comprobar que no varia el valor de una variable modificada por un hijo, pues son procesos paralelos e independientes
*/
#include<iostream>
#include<wait.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>



    
int main()
{

    int global=0;
    int status;
    pid_t child;
    
    printf("SOY EL PADRE \n");
    
    printf("COMENZAMOS LA COMPROBACION DE LA VARIABLE GLOBAL == %d \n", global);


        switch(fork())
        {
            case -1:
            	printf("ERROR A LA HORA DE CREAR UN HIJO \n");
            	exit(EXIT_FAILURE);
        
            case 0:
            printf("HIJO CON ID %d PROCEDE A AUMENTAR EL VALOR DE LA VARIABLE GLOBAL \n",getpid() );
            global++;
            printf("SOY EL HIJO Y AHORA MISMO LA VARIABLE GLOBAL TIENE VALOR== %d	\n",global);
      	    exit(EXIT_SUCCESS);
        
            default:
            printf("ESPERANDO A QUE SE CREE MI HIJO \n ");
    wait(&status);
    printf("LA VARIABLE DE MI HIJO TINE UN VALOR FINAL DE %d \n", global);
    printf("EL HIJO A FINALIZADO CON UN VALOR DE SALIDA DE: %d \n", WEXITSTATUS(status));



        }
}
