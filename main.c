#include"shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
 * main - Entry point
 *
 * @ac: var of type int
 * @av: double pointer of char
 *
 * Return: Always zero
 */

char *get_path(char *name)
{
	char *path;
	char *token, *tmp = NULL;
	struct stat stx;
	int i;

	for (i = 0; name[i]; i++)
	{
		if (name[i] == '/')
		{
			 if (stat(name, &stx) == 0)
			 return (_strdup(name));
			return (NULL);
		 }
	}

	path = _strdup(get_env("PATH"));
	if (path == NULL)
		return (NULL);

	token = strtok(path, ":");

		while (token)
	{
		tmp = malloc(_strlen(token) + _strlen(name) + 2);
		if (tmp == NULL)
		{
			free(path);
			return (NULL);
		}

		_strcpy(tmp, token);
		_strcat(tmp, "/");
		_strcat(tmp, name);

		if (stat(tmp, &stx) == 0)
		{
			free(path);
			return (tmp);
		}

		free(tmp);
		tmp = NULL;
		token = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}
