#include "shell.h"

int freeMul(char **argvz, char *lineptr2, char *lineptr_copy2, int n)
{
        int fred;

        free(lineptr2);
        free(lineptr_copy2);
        for (fred = 0; fred <= n; fred++)
                free(argvz[fred]);
        free(argvz);
        return (0);
}
