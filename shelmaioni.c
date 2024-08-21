#include "main.h"
/**
 *
 *
 *
 */
int main(void)
{
	char *path, *input = NULL;
	size_t len = 0;
	ssize_t read = 0;
	struct stat sb;
	int args, i = 0, count = 0;
	char **as = NULL;

	while (1)
	{
		count++;
		if (isatty(STDIN_FILENO) == 1)
			printf("$ ");
		read = getline(&input, &len, stdin);
		if (read == -1)
			break;
		input[strcspn(input, "\n")] = 0;
		if (strcmp(input, "exit") == 0)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		as = spellarray(input);
		if (as == NULL)
			continue;
		if (stat(as[0], &sb) != -1)
		{
			args = power_fwe(as[0], as, NULL);
			if (args == -1)
				continue;
		}
		else
		{
			path = wand_path(as[0]);
			if (path == NULL)
				perror("execve");
			else
				power_fwe(path, as, NULL);
		free(path);
		}
		while (as[i] != NULL)
		{
			free(as[i]);
			i++;
		}
		free(as);
	}
	free(input);
	return (0);
}

