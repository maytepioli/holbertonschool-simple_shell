#include "main.h"
#define delimity " \t\n"
/**
 * countstr - Counts the number of words in a string.
 * @iinput: The input string to be analyzed.
 * Return: The number of words in the input string, or 0 if the input is NULL
 * or memory allocation fails.
 */
char countstr(char *iinput)
{
	int count = 0;
	char *tokens, *cp_input;

	if (iinput == NULL)
		return (0);

	cp_input = strdup(iinput);
	if (cp_input == NULL)
		return (0);

	tokens = strtok(cp_input, delimity);
	while (tokens)
	{
		count++;
		tokens = strtok(NULL, delimity);
	}
	free(cp_input);
	return (count);

}
/**
 * spellarray - Splits a string into an array of words.
 * @input: The input string to be split into words.
 * Return: A pointer to the array of words, or NULL if an error occurs.
 */
char **spellarray(char *input)
{
	int i = 0, countoks = 0;
	char *token, *cp_input = strdup(input), **args;

	if (input == NULL || cp_input == NULL)
	{
		free(cp_input);
		return (NULL);
	}
	countoks = countstr(input);
	args = malloc(sizeof(char *) * (countoks + 1));
	if (!args)
	{
		free(cp_input);
		return (NULLi);
	}
	if (countoks <= 0)
	{
		free(args), free(cp_input);
		return (NULL);
	}
	token = strtok(cp_input, delimity);
	while (token)
	{
		args[i] = strdup(token);
		if (!args[i])
		{
			while (i >= 0)
			{
				i--;
				free(args[i]);
			}
			free(args), free(cp_input);
			return (NULL);
		}
		i++;
		token = strtok(NULL, delimity);
	}
	args[i] = NULL;
	free(cp_input);
	return (args);
}
