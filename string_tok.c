#include "shell.h"

/**
 * string_token - to split string to tokens
 * @buffer: pointer of string
 *
 * Return: pointer of tokens
 */

char **string_token(char *buffer)
{
	char *token = NULL, *tmp = NULL;
	char **array = NULL;
	int i = 0, count = 0;

	if (buffer == NULL)
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
	array = malloc(sizeof(char *) * (count + 1));
	if (array == NULL)
	{
		free(buffer);
		return (NULL);
	}
	token = strtok(buffer, delimeter);
	while (token)
	{
		array[i] = _strdup(token);
		token = strtok(NULL, delimeter);
		i++;
	}
	free(buffer), buffer = NULL;
	array[i] = NULL;
	return (array);
}
