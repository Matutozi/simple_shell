#include "main.h"
/**
 * set_env_variable - function that calls the set_env environment variable
 * @variable: parameter 1
 * @value: parameter 2
 * Return: returns 0 if sucessfull and -1 otherwise
*/

int set_env_variable(const char *variable, const char *value)
{
	if (variable == NULL || value == NULL)
	{
		char *error_message = "Error: Invalid arguments\n";

		write(STDERR_FILENO, error_message, _strlen(error_message));

		return (-1);
	}
	if (setenv(variable, value, 1) != 0)
	{
		char *error_message = "Error: Failed to set environment variable\n";

		write(STDERR_FILENO, error_message, _strlen(error_message));

		return (-1);
	}
	return (0);
}
/**
 * _parse_cmd - function that takes a string cmd representing a command
 * line input and parses it into individual arguments
 * @cmd: parameter represents the command string that needs to be parsed
 * @argv: pointer to a double pointer argv.
 * Return: return the number of argument passed
 *
*/
int _parse_cmd(char *cmd, char ***argv)
{
	char *cmd_cpy = _strdup(cmd);
	char *token = NULL, *delim = " \n";
	int argc = 0;

	token = _strtok(cmd_cpy, delim);
	while (token)
	{
		(*argv)[argc] = _strdup(token);
		token = _strtok(NULL, delim);
		argc++;
	}
	(*argv)[argc] = NULL;

	free(cmd_cpy);
	return (argc);
}

/**
 * unset_env_variable - function that implements the unset_env function
 * @variable: parameter 1
 * Return: return 0 when successful
*/

int unset_env_variable(const char *variable)
{
	if (variable == NULL)
	{
		write(STDERR_FILENO, "Error: Invalid argument\n", 24);
		return (-1);
	}
	if (unsetenv(variable) != 0)
	{
		perror("Error: Failed to unset environment variable");
		return -1;
	}
	return (0);
}
