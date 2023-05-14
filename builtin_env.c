#include "main.h"

/**
 * print_environment - function that prints the environment variables
 *
 * Return: return void
*/

void print_environment()
{
	extern char **environ;
	char **env = environ;

	while (*env)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

