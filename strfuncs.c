#include "shell.h"

/**
*_strlen - returns the length of a string, like the actual command
*@s: char type variable
*Return: length of the string
*/

int _strlen(char *s)
{
int length;

for (length = 0; s[length] != '\0'; length++)
{}
return (length);
}

/**
*_strcmp - compares two strings
*@s1: string 1
*@s2: string 2
*Return: s1 - s2
*/

int _strcmp(char *s1, char *s2)
{
int num = 0;

while (s1[num] - s2[num] == 0 && s1[num] != '\0')
{
num++;
}
return (s1[num] - s2[num]);
}

/**
*_strcpy - copies a string
*@dest: destination string
*@src: source string
*Return: pointer to the copied string
*/

char *_strcpy(char *dest, char *src)
{
int times;

for (times = 0; times <= _strlen(src); times++)
{
dest[times] = src[times];
}
return (dest);
}
