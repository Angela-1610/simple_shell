#include "shell.h"

/**
 * get_env - handle path in simple shell
 * @name: enviroment variable
 *
 * Return: pointer with result of path
 */

char *get_env(char *name)
{
	char *token, *tmp, *val, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		token = strtok(tmp, "=");
		if (_strcmp(token, name) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			return (env);
		}
	}

	free(tmp);
	return (NULL);
}
