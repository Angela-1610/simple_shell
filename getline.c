#include "shell.h"

/**
 * _getline - act as getline function
 *
 * Return: pointer with result
 */

char *_getline(void)
{
	char *buf = NULL;
	size_t buf_size = 0;
	ssize_t index;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#cisfun$ ", 9);

	index = getline(&buf, &buf_size, stdin);

	if (index == -1)
	{
		free(buf);
		return (NULL);
	}

	return (buf);
}
