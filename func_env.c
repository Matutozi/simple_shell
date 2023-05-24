#include "main.h"
/**
 * execute_command - function that takes in command from the command line
 * @argv: parameter 1
 * @argc: parameter 2
 * Return: return 0 when successful
 *
*/
int execute_command(char **argv, int argc)
{
	int status;

	if (argv[0] == NULL)
		return (0);
	if (_strcmp(argv[0], "exit") == 0)
	{
		if (argc > 1)
			status = atoi(argv[1]);
		exit(status);
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		print_env();
		return (0);
	}
	else if (_strcmp(argv[0], "setenv") == 0)
	{
		if (argc != 3)
		{
			write(STDERR_FILENO, "Error: Invalid setenv command\n", 30);
			return (-1);
		}
		return (set_environment_variable(argv[1], argv[2]));
	}
	else if (_strcmp(argv[0], "unsetenv") == 0)
	{
		if (argc != 2)
		{
			write(STDERR_FILENO, "Error: Invalid unsetenv command\n", 32);
			return (-1);
		}
		return (unset_environment_variable(argv[1]));
	}
	if (fork() == 0)
		execute_child(argv);
	else
		wait(&status);
	return (0);
}
/**
 * set_environment_variable - function that sets the environment variable
 * @name: parameter 1
 * @value: parameter 2
 * Return: returns an int
*/
int set_environment_variable(const char *name, const char *value)
{
	int result = set_env_variable(name, value);

	if (result == 0)
	{
		write(STDOUT_FILENO, "Environment variable set successfully\n", 39);
	}
	return (result);
}

/**
 * unset_environment_variable - function that sets the environment variable
 * @name: parameter 1
 * Return: return int
 *
*/
int unset_environment_variable(const char *name)
{
	int result = unset_env_variable(name);

	if (result == 0)
	{
		write(STDOUT_FILENO, "Environment variable unset successfully\n", 39);
	}
	return (result);
}
