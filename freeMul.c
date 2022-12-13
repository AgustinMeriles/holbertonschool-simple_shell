#include "shell.h"

/**
 * freeMul - frees multiple slots of memory at once
 *
 * @argvz: argument vector passed to main
 * @lineptr2: pointer to an array of strings passed from stdin
 * @lineptr_copy2: copy of lineptr
 * @n: int set to the number of elements in the argv array
 *
 * Return: Always 0 for success
 */

int freeMul(char **argvz, char *lineptr2, char *lineptr_copy2, int n)
{
	int fred;

	free(lineptr2);
	free(lineptr_copy2);
	for (fred = 0; fred <= n; fred++)
		free(argvz[fred]);
	free(argvz);
	return (0);
}
