#include "shell.h"

/**
 * freeMul2 - Frees multiple slots of memory at once
 *
 * @argvz: argument vector passed to main
 * @lineptr_copy2: pointer to an array of strings
 * @n: int set to the number of chars in the argv array
 *
 * Return: Always 0 for success
 */

int freeMul2(char **argvz, char *lineptr_copy2, int n)
{
	int fred;

	free(lineptr_copy2);
	for (fred = 0; fred <= n; fred++)
		free(argvz[fred]);
	free(argvz);
	return (0);
}
