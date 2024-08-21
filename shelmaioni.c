#include "main.h"
/**
 *
 *
 *
 */
char main(void)
{
	char *input = NULL, **a_s = NULL;
	ssize_t read = 0;
	size_t len_buffer = 0;
	int isat = isatty(STDIN_FILENO);


	while(1)

	{	if(isat)
		printf("$ ");
		read = getline(&input, &len, stdin);
		if (read = - 1)
			break;
	}
	free(input);
}
