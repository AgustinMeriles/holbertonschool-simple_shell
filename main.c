#include "shell.h"

int exect(char *command, char **argvx);

/**
 * main - extremely basic interpretation of a standard UNIX shell
 *
 * @ac: argument count. Well, would be anyway.
 * @argv: array of arguments passed to the function. tokenized.
 *
 * Return: 0 on success. -1 on edge case.
 **/

int main(__attribute__((unused))int ac, char **argv)
{
	char *prompt = "(S_shell) $ ", *command;
	char *lineptr = NULL, *lineptr_copy = NULL, *token;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_tokens = 0, i, exe;

	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
		{
			free(lineptr);
			printf("\nEOF Reached. Shutting down.\n");
			return (-1);
		}

		lineptr_copy = malloc(sizeof(char) * nchars_read);
		_strcpy(lineptr_copy, lineptr);

		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		} num_tokens++;

		argv = malloc(sizeof(char *) * num_tokens);
		token = strtok(lineptr_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			_strcpy(argv[i], token);
			token = strtok(NULL, delim);
		} argv[i] = NULL;

		command = argv[0];
		if (_strcmp(command, "exit") == 0)
		{
			printf("bye-bye!\n");
			freeMul(argv, lineptr, lineptr_copy, i);
			exit(EXIT_SUCCESS);
		}

		exe = exect(command, argv);
		if (exe == -1)
		{
			perror(command);
			freeMul(argv, lineptr, lineptr_copy, i);
			exit(EXIT_FAILURE);
		}
		else if (exe == 0)
		{
			freeMul2(argv, lineptr_copy, i);
		}
		else if (exe == 1)
		{
			perror(command);
			freeMul2(argv, lineptr_copy, i);
		}
	}
	return (0);
}

/**
 * exect - Executes the command passed to main
 *
 * @command: pointer to the string holding the concept
 * @argvx: argv passed to execve
 *
 * Return: -1 if execve does not work, 0 from parent for success, 
 * 1 if command does not exist
 */

int exect(char *command, char **argvx)
{
	char *ret = NULL;
	pid_t myPID;
	int st;

	ret = pathfinder(command);

	if (ret != NULL)
	{
		if (_strcmp(ret, command) == 0)
		{
			myPID = fork();

			if (myPID == 0)
			{
				if (execve(ret, argvx, environ) == -1)
				{
					return (-1);
				}
			}
			else
			{
				wait(&st);
			}
			return (0);
		}
		else
		{
			myPID = fork();

			if (myPID == 0)
			{
				if (execve(ret, argvx, environ) == -1)
				{
					return (-1);
				}
			}
			else
			{
				wait(&st);
				free(ret);
			}
			return (0);
		}
	}
	return (1);
}
