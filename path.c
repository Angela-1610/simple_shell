#include "shell.h"

/**
 * get_path - use get_env to handle path
 * @name: the path
 *
 * Return: pointer with value
 */

char *get_path(char *name)
{
	char *path;
	char *token, *tmp;
	struct stat st;
	int i;

	for (i = 0; name[i]; i++)
	{
		if (name[i] == '/')
		{
			if (stat(name, &st) == 0)
				return (_strdup(name));
			return (NULL);
		}
	}

	path = get_env("PATH");
	if (path == NULL)
		return (NULL);

	token = strtok(path, ":");
	while (token)
	{
		tmp = malloc(_strlen(token) + _strlen(name) + 2);
		if (tmp == NULL)
			return (NULL);
		if (tmp)
		{
			_strcpy(tmp, token);
			_strcat(tmp, "/");
			_strcat(tmp, name);

			if (stat(tmp, &st) == 0)
			{
				return (tmp);
			}
			token = strtok(NULL, ":");
		}
	}
	free(path);
	return (NULL);
}
