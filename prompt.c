#include "main.h"
/**
 * display - prints content to the standard output.
 * @chr: character of string to be displayed on the stdout.
 *
 * Return: returns string
 */

ssize_t prompt(char *chr)
{
	ssize_t wrt;
	size_t i;

	for (i = 0; chr[i] != '\0'; i++)
		wrt = write(1, &chr[i], 1);

	return (wrt);
}
