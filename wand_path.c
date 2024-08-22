#include "main.h"
/**
 * wand_path - Searches for an executable file
 * in the directories listed in PATH.
 * @input: The name of the executable file to search for.
 *Return: A pointer to the full path of the executable file.
 *or NULL if not found.
 */
char *wand_path(const char *input)
{
	const char *path = mi_getenv("PATH");
	size_t input_len, path_len, full_len;
	char *cp_path, *full_path, *directory;
	struct stat sb;

	if (!path)
		return (NULL);
	cp_path = strdup(path);

	if (!cp_path)
		return (NULL);

	directory = strtok(cp_path, ":");
	while (directory)
	{
		path_len = strlen(directory);
		input_len = strlen(input);
		full_len = path_len + input_len + 2;
		full_path = malloc(full_len);

		if (!full_path)
		{
			free(cp_path);
			return (NULL);
		}
		snprintf(full_path, full_len, "%s/%s", directory, input);
		if (stat(full_path, &sb) == 0)
		{
			free(cp_path);
			return (full_path);
		}
		free(full_path);
		directory = strtok(NULL, ":");
	}
	free(cp_path);
	return (NULL);
}
