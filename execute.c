#include "shell.h"

/**
 * exec -act as execve function
 * @ptr1: the first pointer
 * @ptr2: the second pointer
 * @idx: index of type int
 *
 * Return: status as integer
 */

int exec(char **ptr1, char **ptr2, int idx)
{
	pid_t id;
	int status;
	char *tmp;

	tmp = get_path(ptr1[0]);
	if (tmp == NULL)
	{
		print_error(ptr2[0], ptr1[0], idx);
		return (127);
	}

	id = fork();

	if (id == 0)
	{
		if (execve(tmp, ptr1, environ) == -1)
		{
			print_error(ptr2[0], ptr1[0], idx);
			free(ptr1);
			return (127);
		}
	}
	else
	{
		wait(&status);
	}

	return (WEXITSTATUS(status));
}
