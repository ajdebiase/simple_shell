#include "holberton.h"

char *combind(char *str1, char *str2)
{
	char *full, *strmover = str1;
	int a = _strlen(str1), b = _strlen(str2), index = 0, index2 = 0;

	while(*strmover != '\0')
		strmover++;
	if (*strmover-- != '/')
		*strmover++ = '/';
	full = malloc(sizeof(char) * (a + b + 2));
	for (;str1[index] != '\0'; index++)
		full[index] = str1[index];
	index2 = index + 1;
	for (index = 0; str2[index] != '\0'; index++)
	{
		full[index2] = str2[index];
	}
	index2++;
	full[index2] = '\0';
	return (full);
}
