#include "holberton.h"

/**
 * vector - Tokenizes input string "str" and returns tokens in an array.
 * @str: String being tokenized and packaged.
 * @charCount: Length of string.
 * @delim: string of seperating chars
 * Return: Vector array with tokenized string.
 */

char **vector(char *str, ssize_t charCount, char *delim)
{
	char **args;
	char *buffer, *token, *buffPtr;
	int index = 0, tok = 1;

	buffer = malloc(charCount + 1);
	if (buffer == NULL)
		return (NULL);
	_strncpy(buffer, str, charCount + 1);
	buffPtr = buffer;
	while (*buffPtr == ' ')
		buffPtr++;
	for (; *buffPtr != '\0'; buffPtr++)
	{
		if (buffPtr[0] == ' ' && (
			    buffPtr[1] != ' ' &&
			    buffPtr[1] != '\n' &&
			    buffPtr[1] != '\0'
		))
			tok++;
		if (buffPtr[0] == ':' && buffPtr[1] == '/')
			tok++;
	}
	args = malloc(sizeof(char *) * (tok + 1));
	if (args == NULL)
		return (NULL);
	token = strtok(buffer, delim);
	for (index = 0; token != NULL; index++)
	{
		args[index] = malloc(_strlen(token) + 1);
		if (args[index] == NULL)
			return (NULL);
		_strncpy(args[index], token, _strlen(token) + 1);
		token = strtok(NULL, delim);
	}
	args[index] = NULL;
	free(buffer);
	return (args);
}
