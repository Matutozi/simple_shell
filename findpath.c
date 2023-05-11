#include "main.h"
/**
 * find_path - Finds the full path of a command.
 * @cmd: Pointer to the command string.
 *
 * Return: Pointer to the full path of the command, or NULL if not found.
 */

char *find_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = _strdup(path);
	char *token = _strtok(path_copy, ":");

	while (token != NULL)
	{
		size_t dir_len = _strlen(token);
		size_t cmd_len = _strlen(command);
		char *full_path = malloc(dir_len + 1 + cmd_len + 1);

		if (full_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		_strcpy(full_path, token);
		full_path[dir_len] = '/';
		_strcpy(full_path + dir_len + 1, command);

		if (access(full_path, X_OK) == 0)
		{
			return full_path;
		}

		free(full_path);
		token = _strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
