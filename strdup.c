#include "main.h"
/**
 * _strdup - returns a pointer to a newly allocated space in memory.
 * @str: string.
 *
 * Return: pointer of an array of chars
 */
char *_strdup(char *str)
{
	unsigned int length;
	char *str_cpy;
	unsigned int j;

	if (str == NULL)
		return (NULL);
	length = _strlen(str);
	str_cpy = malloc(sizeof(char) * (length + 1));

	if (str_cpy == NULL)
		return (NULL);

	for (j = 0; j <= length; j++)
		str_cpy[j] = str[j];
	return (str_cpy);
}
