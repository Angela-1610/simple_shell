#include "shell.h"

/**
 * string_token - to split string to tokens
 * @buffer: pointer of string
 * Return: pointer of tokens
 */

char **string_token(char *buffer)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int i = 0, count = 0;

	if (!buffer)
		return (NULL);

	tmp = _strdup(buffer);
	token = strtok(tmp, delimeter);
	if (token == NULL)
	{
		free(buffer), buffer = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		count++;
		token = strtok(NULL, delimeter);
	}
	free(tmp), tmp = NULL;
	command = malloc(sizeof(char *) * (count + 1));
	if (!command)
	{
		free(buffer), buffer = NULL;
		return (NULL);
	}
	token = strtok(buffer, delimeter);
	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, delimeter);
		i++;
	}
	free(buffer), buffer = NULL;
	command[i] = NULL;
	return (command);
}
