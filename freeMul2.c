#include "shell.h"

int freeMul2(char **argvz, char *lineptr_copy2, int n)
{
        int fred;

        free(lineptr_copy2);
        for (fred = 0; fred <= n; fred++)
                free(argvz[fred]);
        free(argvz);
        return (0);
}