#include "main.h"

/**
 * _strcmp - function that compares two strings
 * @string1: first parameter
 * @string2: second parameter
 * Return: returns an int
 *
*/

int _strcmp(const char *string1, const char *string2)
{
	while (*string1 != '\0' && *string1 == *string2)
	{
		string1++;
		string2++;
	}

	if (*string1 < *string2)
	{
		return (-1);
	}
	else if (*string1 > *string2)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
