#include "shell.h"

/**
 * main - prints all arguments given without accounting for variable ac
 * @ac: argument count. unused
 * @av: pointer to an array with all arguments given
 * Return: 0 if success, 1 if no arguments were given
 */

int main(__attribute__((unused))int ac, char **av)
{
	int i = 1;

	if (av[i] == NULL)
	{
		printf("No arguments received\n");
		return (1);
	}

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
