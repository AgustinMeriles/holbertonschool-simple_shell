#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

int freeMul(char **argvz, char *lineptr2, char *lineptr_copy2, int n);
int freeMul2(char **argvz, char *lineptr_copy2, int n);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);

#endif
