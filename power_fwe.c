#include "main.h"
/**
 *
 *
 */
int power_fwe(char *phatname, char *argv[], char *envp[])
{

	pid_t child;
	int status;


	child = fork();
	if (child == 0)
	{
		execve(phatname, argv, envp);
		perror("execve fallo");
		return (-1);
	}
	else if (child > 0)
	{
		wait(&status);

	}
	else
	{
		return (-1);
	}
	return (0);
}
