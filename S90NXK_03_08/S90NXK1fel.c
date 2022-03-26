#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
//pico 1_system.c
//cc 1_system.c -o 1_system.out
// ./1_system.out
int main(void){
    int status;

    if( (status = system("date"))<0 )
        perror("system() error");


    if(WIFEXITED(status))
        printf("Normalis befejezodes, visszaadott ertek = %d\n",WEXITSTATUS(status));

    if( (status = system("THDWDR"))<0 )
		perror("system() errpr");

    if(WIFEXITED(status))
        printf("Normalis befejezodes, visszaadott ertek = %d\n",WEXITSTATUS(status));
    exit(0);
}