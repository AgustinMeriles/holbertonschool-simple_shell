#include "shell.h"

/**
 * main - executes ls via a forked child process 5 times specifically
 *
 * Return: 0 on success, 1 on error
 */

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	char *envp[] = {"/proc/6884/environ", NULL};
	pid_t fatherOfFive;
	int stat, loop;

	for (loop = 0; loop <= 4; loop++)
	{
		fatherOfFive = fork();

		if (fatherOfFive == -1)
		{
			perror("Error:");
			return (1);
		}
		else if (fatherOfFive == 0)
		{
			execve(argv[0], argv, envp);
		}
		else
		{
			wait(&stat);
			printf("All done!\n");
		}
	}
	return (0);
}
