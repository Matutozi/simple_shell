#include "main.h"

/**
 * readline - function that reads the input from the user
 * Return: returns a pointer to a string
 *
*/

char* readline(void)
{
	int buffer_size;
	int i; /* for the position */
	char *buffer;

	buffer_size = 
