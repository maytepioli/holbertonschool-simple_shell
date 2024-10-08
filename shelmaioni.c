#include "main.h"
/**
 * main - Entry point of the program.
 *
 * Return: 0 in the best case, -1 in fail case
 */
int main(__attribute__((unused))int ac,
		__attribute__((unused))char **av,
		char **env)
{
	char *path, *input = NULL, *s = "sh", *a;
	size_t len = 0;
	ssize_t read = 0;
	struct stat sb;
	int count = 0;
	char **as = NULL;
	int status = 0;

	while (1)
	{
		count++;
		if (isatty(STDIN_FILENO) == 1)
			printf("$ ");
		read = getline(&input, &len, stdin);
		if (read == -1)
			break;
		as = spellarray(input);
		if (as == NULL)
			continue;
		if (strcmp(as[0], "exit") == 0)
		{
			free(input), free_array(as);
			exit(status);
		}
		if (strcmp(as[0], "env") == 0)
		{
			print_arr(env);
		}
		if (stat(as[0], &sb) != -1)
			status = power_fwe(as[0], as, NULL);
		else
		{
			path = wand_path(as[0]);
			if (path == NULL)
				a = _perror(s, count, input), free(a);
			else
				status = power_fwe(path, as, NULL), free(path);
			
			
		}
		free_array(as);
	}
	free(input);
	return(status);
}
/**
 *_perror - Prints an error message with a custom format.
 *@s: The first string input, typically the name of the program or command
 *@in: The second string input, usually the specific error message or argument.
 * @count: The integer to be included in the error message,
 * typically an error code or count.
 * Return: a
 */
char *_perror(char *s, int count, char *in)
{
	char *a;

	in[strcspn(in, "\n")] = 0;
	a = malloc(sizeof(char *) * strlen(s) + strlen(in) + sizeof(int) + 5);
	sprintf(a, "%s: %i: %s ", s, count, in);
	perror(a);
	return (a);
}
/**
 *free_array - Frees a dynamically allocated array of strings.
 * @array: A pointer to the array of strings to be freed.
 *Return: Void. This function does not return a value.
 */
void free_array(char **array)
{
	int i = 0;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/**
 *
 */

char **print_arr(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
	{
		printf("%s\n", arr[i]);
		i++;
	}
	return(arr);
}
