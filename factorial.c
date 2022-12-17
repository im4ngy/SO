#include <stdio.h>
#include <stdlib.h>
int main(int argc, char**argv){
    //control linea argmuentos
    int i, fact=1, num=atoi(argv[1]);
    for(i=2; i<=num; i++){
        fact=fact*i;
    }
    printf("%d",fact);
    return 0;
}