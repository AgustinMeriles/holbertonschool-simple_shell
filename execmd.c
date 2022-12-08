#include "main.h"
/**
 *
 *
 *
 **/
void execmd(char **argv)
{

	pid_t processId;
        char *command = NULL;
	int st;
	extern char** environ;

	processId = fork();
	command = argv[0];
	if (strcmp(command, "exit")== 0)
	{
		exit(EXIT_SUCCESS);
	}
	if (processId == 0)
	{
		if (execve(command, argv, environ) == -1)
			perror("Error: ");
		exit(EXIT_FAILURE);
	}
	else if (processId < 0)
		perror("Error: ");
	else
	{
		do {
			processId = waitpid(processId, &st, WUNTRACED);
		} while (!WIFEXITED(st) && !WIFSIGNALED(st));
	}
}
