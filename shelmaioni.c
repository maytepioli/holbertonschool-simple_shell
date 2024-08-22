#include "main.h"
/**
 *
 *
 *
 */
int main(void)
{
	char *path, *input = NULL, *s = "sh";
	size_t len = 0;
	ssize_t read = 0;
	struct stat sb;
	int i = 0, count = 0;
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
			power_fwe(as[0], as, NULL);
		else
		{
			path = wand_path(as[0]);
			if (path == NULL)
				_perror(s, input, count);
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
 */
void _perror(char *s, char *in, int count)
{
	char *i;

	i = malloc(sizeof(char *) * strlen(s) + strlen(in) + sizeof(int) + 5);
	perror(i);
	free(i);
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
