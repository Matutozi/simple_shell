#include "main.h"
/**
 * main - Entry point of the program.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char *cmd;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			prompt("($) ");

		cmd = read_cmd();
		execute_cmd(cmd);
		free(cmd);
		cmd = NULL;
	}

	return (0);
}
