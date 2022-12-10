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

/**
*_strdup - duplicates a string essentially
*@str: the string
*Return: pointer
*/

char *_strdup(char *str)
{
int a;
int b;
char *cpy;

if (str == NULL)
{
return (NULL);
}
for (a = 0; str[a]; a++)
{
;
}
a++;
cpy = malloc(a *sizeof(char));
if (cpy == NULL)
{
return (NULL);
}
for (b = 0; b < a; b++)
{
cpy[b] = str[b];
}
return (cpy);
}

/**
*_strcat - concatenate
* @dest: concatinated destination
* @src: concatenated source
*Return: pointer to the concatenated string
*/

char *_strcat(char *dest, char *src)
{
int arr1;
int arr2;

for (arr2 = 0; dest[arr2] != '\0'; arr2++)
{}
for (arr1 = 0; src[arr1] != '\0'; arr1++)
{
dest[arr2 + arr1] = src[arr1];
}
dest[arr2 + arr1] = '\0';
return (dest);
}
