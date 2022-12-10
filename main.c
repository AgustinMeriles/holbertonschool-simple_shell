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
			return (-1);
		}
		lineptr_copy = malloc(sizeof(char) * nchars_read);
		strcpy(lineptr_copy, lineptr);
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
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		} argv[i] = NULL;
		command = argv[0];
		if (strcmp(command, "exit") == 0)
		{
			printf("bye-bye!\n");
			freeMul(argv, lineptr, lineptr_copy, i);
			exit(EXIT_SUCCESS);
		}
		exe = exect(command, argv);
		if (exe == -1)
		{
			freeMul(argv, lineptr, lineptr_copy, i);
			exit(EXIT_FAILURE);
		}
		else if (exe == 0)
			freeMul2(argv, lineptr_copy, i);
	}
	return (0);
}

/**
 * exect - placeholder
 *
 * @command: placeholder
 * @argvx: placeholder
 *
 * Return: placeholder
 */

int exect(char *command, char **argvx)
{
	pid_t myPID;
	int st;

	myPID = fork();

	if (myPID == 0)
	{
		if (execve(command, argvx, environ) == -1)
		{
			perror("Error");
			return (-1);
		}
	}
	else
		wait(&st);
	return (0);
}
