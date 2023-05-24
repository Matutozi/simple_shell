#include "main.h"

/**
 * assign_line - assigns the line var for _getline
 * @lineptr: Buffer that store the input str
 * @buffer: str that is been called to line
 * @n: size of line
 * @j: size of buffer
 */
void assign_line(char **lineptr, size_t *n, char *buffer, size_t j)
{

	if (*lineptr == NULL)
	{
		if  (j > BUFFERSIZE)
			*n = j;

		else
			*n = BUFFERSIZE;

		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFFERSIZE)
			*n = j;
		else
			*n = BUFFERSIZE;

		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}
/**
 * _getline - Read input from stream
 * @lineptr: buffer that stores the input
 * @n: size of lineptr
 * @stream: stream to be read from
 *
 * Return: The number of bytes
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t val;
	char *buffer, c = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFFERSIZE);

	if (buffer == 0)
		return (-1);
	while (c != '\n')
	{
		i = read(STDIN_FILENO, &c, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFFERSIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';
	assign_line(lineptr, n, buffer, input);
	val = input;
	if (i != 0)
		input = 0;

	return (val);
}
