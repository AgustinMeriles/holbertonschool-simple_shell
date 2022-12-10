#include "shell.h"

/**
 * pathfinder - finds a command within the PATH
 *
 * @command: file to look for
 *
 * Return: NULL if command does not exist within PATH.
 * Otherwise, returns pointer to its location
 */

char *pathfinder(char *command)
{
	char *path, *pathcpy, *pathtkn, *filepath;
	int comlen, dirlen;
	struct stat buffer;

	path = getenv("PATH");

	pathcpy = _strdup(path);

	comlen = _strlen(command);

	pathtkn = strtok(pathcpy, ":");
	while (pathtkn != NULL)
	{
		dirlen = _strlen(pathtkn);
		filepath = malloc(comlen + dirlen + 2);

		_strcpy(filepath, pathtkn);
		_strcat(filepath, "/");
		_strcat(filepath, command);
		_strcat(filepath, "\0");

		if (stat(filepath, &buffer) == 0)
		{
			free(pathcpy);
			return (filepath);
		}
		else
		{
			free(filepath);
			pathtkn = strtok(NULL, ":");
		}
	}
	free(pathcpy);

	if (stat(command, &buffer) == 0)
	{
		return (command);
	}

	return (NULL);
}
