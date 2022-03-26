#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
char	*env_init[] = {"USER=ismeretlen","PATH=/tmp","ENV=v�ge\n", NULL };

int
main(void)
{
	pid_t	pid;


	if ( (pid = fork()) < 0)
		perror("fork error");
	else if (pid == 0) {
		if (execlp("echoall","echoall", "only 1 arg", (char *) 0)<0)
			perror("execlp error");
	}
	exit(0);
}