//reciba un numero por linea de comandos. Debe calcularse su factorial. compilar y comparar. 
//reciba 2 nuemros enteros como parametros. Cree dos hijos de manera que cada hijo calcule el factorial de algun enteros . (./a.out 3 5 ). Poner a dormir el 2º proceso con un sleep (1)

#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<wait.h>
#include<unistd.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int status;
    pid_t hijo1,hijo2;
    int sum=1;
    if(argc!=3)
    {
        printf("ERROR EN LA LINEA DE COMANDOS\n");
        exit(EXIT_FAILURE);
    }

    for(int i=0;i<2;i++)
    {
        switch(fork())
        {
            case -1:
            
                printf("ERROR A LA HORA DE CREAR EL HIJO %d\n", i+1);
            exit(EXIT_FAILURE);

            

            case 0:
            
                if(i==0)
                {
                    execlp("./4.a","./4.a ", argv[1], NULL);
                }
                else 
                {
                    execlp("./4.a","./4.a ", argv[2], NULL);
                }
            exit(EXIT_SUCCESS);
            

            default:
            
                printf("ESPERANDO A QUE MI HIJO %d ACABE \n", i+1);
        }
    }
    hijo1=wait(&status);
    printf("HIJO 1 ACABADO CON CODIGO DE SALIDA %d \n", WEXITSTATUS(status));

    hijo2=wait(&status);
    printf("HIJO 2 ACABADO CON CODIGO DE SALIDA %d \n", WEXITSTATUS(status));
    
    exit(EXIT_SUCCESS);

}
