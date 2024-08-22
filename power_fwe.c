#include "main.h"
/**
 * power_fwe - Creates a new process to execute a program.
 *
 * @phatname: The path to the program to be executed.
 * @argv: An array of arguments passed to the program.
 * @envp: An array of environment variables.
 *Return: 0 on success, -1 on failure.
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
		wait(&status);
	else
		return (-1);

	return (0);
}
