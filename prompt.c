#include "shell.h"

/**
 * main - prints "$ ", waits for input, then prints said input
 * Return: 0 on success, 1 on edge case.
 */

int main(void)
{
	char *buffer;
	size_t bufsize = 1024; 

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (!buffer)
	{
		printf("Unable to allocate buffer");
		return(1);
	}

	printf("$ ");
	fgets(buffer,bufsize,stdin);
	printf("%s",buffer);

	free(buffer);
	return(0);
}
