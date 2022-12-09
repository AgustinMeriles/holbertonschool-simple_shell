#include "shell.h"
/**
 *
 *
 *
 *
 **/
int main(int ac, char **argv)
{
	char *prompt = "(S_shell) $ ", *command;
	char *lineptr = NULL, *lineptr_copy = NULL, *token;
	size_t n = 0;
	ssize_t nchars_read; /* number of characters the users types */
	const char *delim = " \n";
	int num_tokens = 0, i, fre, st;
	pid_t myPID;
	extern char **environ;

	/*declaring void variables*/
	(void)ac;

	/*loop cration for the shell prompt */
	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		/* check if the getline function failed or reached EOF or user use CTRL + D */ 
		if (nchars_read == -1)
		{
			printf("\nEOF reached.\n");
			free(lineptr);
			return (-1);
		}

		/* allocate space for a copy of the lineptr */
		lineptr_copy = malloc(sizeof(char) * nchars_read);
		if (lineptr_copy == NULL)
		{
			perror("Unable to allocate memory.");
			free(lineptr);
			return (-1);
		}
		/* copy lineptr to lineptr_copy */
		strcpy(lineptr_copy, lineptr);

		/* split the string (lineptr) into an array of words */
		/* calculate the total number of tokens */
		token = strtok(lineptr, delim);

		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;

		/* Allocate space to hold the array of strings */
		argv = malloc(sizeof(char *) * num_tokens);

		/* Store each token in the argv array */
		token = strtok(lineptr_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		};
		argv[i] = NULL;

		command = argv[0];

		if (strcmp(command, "exit") == 0)
		{
			printf("bye-bye!\n");
			free(lineptr);
			free(lineptr_copy);
			for (fre = 0; fre <= i; fre++)
				free(argv[fre]);
			free(argv);
			exit(EXIT_SUCCESS);
		}

        	/* execute the command */
        	myPID = fork();

		if (myPID == 0)
		{
			if (execve(command, argv, environ) == -1)
				perror("Error");
			exit(EXIT_FAILURE);
		}
		else if (myPID == -1)
			perror("Error");
		else
		{
			do {
				myPID = waitpid(myPID, &st, WUNTRACED);
			} while (!WIFEXITED(st) && !WIFSIGNALED(st));
		}

		for (fre = 0; fre <= i; fre++)
			free(argv[fre]);
		free(argv);
	}

	/* free up allocated memory */
	free(lineptr_copy);
	free(lineptr);

	return (0);
}
