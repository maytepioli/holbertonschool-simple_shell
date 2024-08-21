#include "main.h"
#define delimity " \t\n"
/**
 *
 *
 */
char countstr(char *iinput)
{
	int count = 0;
	char *tokens, *cp_input = strdup(iinput);

	if (iinput == NULL)
		return(0);

	cp_input = strdup(iinput);
	if (cp_input == NULL)
		return (0);

	tokens = strtok(cp_input, delimity);
	while(tokens)
	{	
		count++;
		tokens = strtok(NULL, delimity);
	}
	free(cp_input);
	return(count);

}
/**
 *
 *
 *
 */
char **spellarray(char *input)
{
	int i = 0, countoks = 0;
	char *token, *cp_input;
	char **args;
	
	if (input == NULL)
		return (NULL);
	cp_input = strdup(input);
	if (cp_input == NULL)
		return (NULL);
	countoks = countstr(input);
	if (countoks <= 0)
	{
		free(cp_input);
		return (NULL);
	}

	args = malloc(sizeof(char *) * (countoks + 1));
	if (!args)
	{
		free(cp_input);
		return(NULL);
	}

	token = strtok(cp_input, delimity);
	while(token)
	{
		args[i] = strdup(token);
		if(!args[i])
		{
			while(i > 0)
			{
				i--;
				free(args[i]);
			}
			free(args);
			free(cp_input);
			return (NULL);
		}
		i++;
		token = strtok(NULL, delimity);
	}
	args[i] = NULL;
	free(cp_input);
	return(args);
}
	
