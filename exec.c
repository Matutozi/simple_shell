#include "main.h"
/**
 * execute_cmd - Executes a command.
 * @cmd: Pointer to the command string.
 *
 * Return: Always returns 0.
 */

int execute_cmd(char *cmd)
{
	char *cmd_cpy = _strdup(cmd);
	char *token = NULL;
	char *delim = " \n";
	int status;
	int argc = 0;
	char **argv = malloc(256 * sizeof(char *));

	token = _strtok(cmd_cpy, delim);
	while (token)
	{
		argv[argc] = token;
		token = _strtok(NULL, delim);
		argc++;
	}
	argv[argc] = NULL;

	if (_strcmp(argv[0], "exit") == 0)
	{
		free(cmd_cpy), free(argv);
		exit(0);
	}
	if (fork() == 0)
	{
		char *full_path = find_path(argv[0]);
		if (full_path)
		{
			if (execve(full_path, argv, NULL) == -1)
			{
				perror("./shell");
				exit(1);
			}
			free(full_path), free(argv);
		}
		else
		{
			perror("./shell");
			exit(1);
		}
	}
	else
	{
		wait(&status);
		free(argv);
	}
	return (0);
}
