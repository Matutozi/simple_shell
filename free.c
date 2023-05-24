#include "main.h"
/**
 * free_argv - function that frees memory
 * @argv: parameter 1
 *
*/
void free_argv(char **argv)
{
	int i;

	if (argv == NULL)
		return;
	for (i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
	free(argv);
}
