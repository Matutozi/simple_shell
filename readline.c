#include "main.h"

/**
 * read_cmd - Reads a command from standard input.
 * @cmd: Pointer to a buffer where the command will be stored.
 * @len: Pointer to the size of the buffer.
 *
 * Return: Number of characters read, or -1 on failure.
 */
ssize_t read_cmd(char **cmd, size_t *len)
{
	prompt("#cisfun$ ");
	return (getline(cmd, len, stdin));
}
