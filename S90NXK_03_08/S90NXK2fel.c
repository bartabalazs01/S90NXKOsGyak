#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>

int main(void){
	do{
		printf("Irjon be egy parancsot!\n");
		char parancs[100];
		scanf("%s",parancs);
		execl(parancs);
	}while(strcmp(parancs,"Q")!=0);
	exit(0);
}