#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * main - Entry point
 *
 * @ac: var of type int
 * @av: double pointer of char
 *
 * Return: Always zero
 */

int main(int ac, char **av)
{
	char *read = NULL, **token = NULL;
	int status = 0, idx = 0;
	(void) ac;

	while (1)
	{
		read = _getline();

		if (read == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		idx++;

		token = string_token(read);

		if (bultin(token[0]))
			handling(token, av, &status, idx);
		else
			status = exec(token, av, idx);

	}

	return (0);
}
