#include "main.h"
/**
 *
 *
 *
 */
int main(void)
{
	char *path, *input = NULL, *s = "sh", *a;
	size_t len = 0;
	ssize_t read = 0;
	struct stat sb;
	int count = 0;
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
		as = spellarray(input);
		if (as == NULL)
			continue;
		if (strcmp(as[0], "exit") == 0)
		{
			free(input);
			free_array(as);
			exit(EXIT_SUCCESS);
		}
		if (stat(as[0], &sb) != -1)
			power_fwe(as[0], as, NULL);
		else
		{
			path = wand_path(as[0]);
			if (path == NULL)
			{
				a = _perror(s, count, input);
				free(a);
			}
			else
				power_fwe(path, as, NULL);
			free(path);
		}
		free_array(as);
	}
	free(input);
	return (0);
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
