#include "main.h"

/**
 * print_environment - function that prints the environment variables
 *
 * Return: return void
*/

void print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
