#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    pid=fork();
    if(pid==-1){
        ("Error fork");
        exit(EXIT_FAILURE);
    }
    else if(pid==0){
        printf("Soy %d", getpid());
        exit(EXIT_SUCCESS);
    }
    else{
        sleep(20);
    }
    return 0;
}