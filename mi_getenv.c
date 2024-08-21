#include "main.h"

/**
 *
 *
 */
char *mi_getenv(const char *name)
{
	extern char **environ;
	char **env = environ, *delimiter;
	size_t len_name = strlen(name), len_namenv;

	while (*env)
	{
		delimiter = strchr(*env, '=');
		if (delimiter)
		{
			len_namenv = delimiter - *env;
		}
		if (len_name == len_namenv && strncmp(*env, name, len_name) == 0)
		{
				return(delimiter + 1);
		}
		env++;
	}
	return (NULL);
}
