#include "main.h"
/**
 * main - Entry point of the program.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char *cmd = NULL;
	size_t len = 0;
	ssize_t chars_read;

	while (1)
	{
		chars_read = read_cmd(&cmd, &len);
		if (chars_read == -1)
		{
			free(cmd);
			exit(EXIT_FAILURE);
		}
		execute_cmd(cmd);
	}

	return (0);
}
