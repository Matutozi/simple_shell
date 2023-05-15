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
	char *token = NULL, *delim = " \n";
	int status, argc = 0;
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
	else if (_strcmp(argv[0], "env") == 0)
	{
		print_env();
		free(cmd_cpy);
		free(argv);
		return (0);
	}

	if (fork() == 0)
	{
		execute_child(argv[0]);
	}
	else
	{
		wait(&status);
		free(argv);
	}
	return (0);
}

/**
 * execute_child_process - function that executes the child process
 * @input: parameter
 *
 * Return: void
 *
*/

void execute_child(char *input)
{
	char *full_path = find_path(input);

	if (full_path != NULL)
	{
		char **argv = malloc(sizeof(char *) * 2);

		argv[0] = full_path;
		argv[1] = NULL;

		if (execve(full_path, argv, NULL) == -1)
		{
			perror("./shell");
			exit(1);
		}
		free(full_path);
	}
	else
	{
		perror("./shell");
		exit(1);
	}
}
