#ifndef MAIN_H
#define MAIN_H
#define PROMPT "$ "
#define PROPERTY_SEPARATROR '='
#define PATH_SEPARATROR ':'
#define COMMAND_LINE_SEPARATROR "\n\t\r "
#define END_STRING_CHAR '\0'

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

void execmd(char **argv);
char *get_location(char *command);
int fexit(char **argv);

#endif
