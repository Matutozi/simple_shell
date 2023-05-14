#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @s: parameter that stores the input string
 * Return: length of a string.
 *
*/

size_t _strlen(char *s)
{
	size_t count = 0;

	while (*(s + count) != '\0')
	{
		count++;
	}
	return (count);
}
