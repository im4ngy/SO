//reciba un numero por linea de comandos. Debe calcularse su factorial. compilar y comparar.
//reciba 2 nuemros enteros como parametros. Cree dos hijos de manera que cada hijo calcule el factorial de algun enteros . (./a.out 3 5 ). Poner a dormir el 2º proceso con un sleep (1)
#include<iostream>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<wait.h>
#include<unistd.h>
#include<stdio.h>


int main(int argc, char const *argv [])
{
    int value=atoi(argv[1]);
    int fact=1;
    if (argc!=2)
    {
        printf("ERROR EN LA LINEA DE COMANDOS \n");
        exit(EXIT_FAILURE);
    }


    for(int i =1 ;i<=value;i++ )
    {   
        sleep(1);
        fact=fact*i;
        printf("%d\n",fact);
    }
    sleep(1);
    printf("EL FACTORIAL DE %d ES %d\n", value, fact);
    exit(EXIT_SUCCESS);
}
