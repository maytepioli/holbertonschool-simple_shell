#include "main.h"

/**
 * mi_getenv - Retrieves the value of an environment variable.
 * @name: The name of the environment variable to find.
 * Return: NULL
 */
char *mi_getenv(const char *name)
{
	char **env = environ, *delimiter;
	size_t len_name = strlen(name), len_namenv;

	while (*env)
	{
		delimiter = strchr(*env, '=');
		if (delimiter)
			len_namenv = delimiter - *env;
		if (len_name == len_namenv && strncmp(*env, name, len_name) == 0)
			return (delimiter + 1);
		env++;
	}
	return (NULL);
}
