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

	if (argv[0] == NULL)
		return (0);
	if (_strcmp(argv[0], "exit") == 0)
	{
		if (argc > 1)
			status = atoi(argv[1]);
		free(cmd_cpy), free(argv);
		argv = NULL, cmd_cpy = NULL;
		exit(status);
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		print_env();
		free(cmd_cpy), free(argv);
		cmd_cpy = NULL, argv = NULL;
		return (0);
	}

	if (fork() == 0)
		execute_child(argv);
	else
		wait(&status);
	free(argv), free(cmd_cpy);
	argv = NULL, cmd_cpy = NULL;
	return (0);
}

/**
 * execute_child - function that executes the child process
 * @input: parameter
 *
 * Return: void
 *
*/

void execute_child(char **input)
{
	char *full_path = find_path(input[0]);

	if (full_path != NULL)
	{
		int count = 0;
		int i;
		char **argv = malloc(sizeof(char *) * 2);

		while (input[count] != NULL)
			count++;

		if (argv == NULL)
		{
			perror("Error: memory allocation");
		}
		for (i = 0; i < count; i++)
		{
			argv[i] = input[i];
		}
		argv[count] = NULL;

		if (execve(full_path, argv, NULL) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
		free(full_path);
		full_path = NULL;
	}
	else
	{
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
}
