#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdio.h>
#include	<stdlib.h>

int
main(void)
{
	pid_t	pid;
	int	status;

	if ( (pid = fork()) < 0)
		perror("fork hiba");
	else if (pid == 0)
		exit(7);
	if (wait(&status) != pid)
		perror("wait hiba");
	printf("Normalis befejezodes,visszaadott ertek = %d\n", WEXITSTATUS(status));

	if ( (pid = fork()) < 0)
		perror("fork hiba");
	else if (pid == 0)
		abort();
	if (wait(&status) != pid)
		perror("wait hiba");
	printf("Abnormalis befejezodes,a szignal sorszam = %d\n", WTERMSIG(status));


	if ( (pid = fork()) < 0)
		perror("fork hiba");
	else if (pid == 0)
		status /= 0;
	if (wait(&status) != pid)
		perror("wait hiba");
	printf("Abnormalis befejezodes,a szignal sorszam = %d\n", WTERMSIG(status));

	exit(0);
}
