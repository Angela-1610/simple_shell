#include "shell.h"

/**
 * bultin - give some commands to program
 * @command: the input line
 *
 * Return: 1 if success or 0 if fail
 */

int bultin(char *command)
{
	char *x[] = {"exit", "env", "setenv", "cd"};
	int i;

	for (i = 0; x[i]; i++)
	{
		if (_strcmp(command, x[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handling - handle this commands
 * @command: comparing command
 * @av: pointer argument
 * @status: status to return
 * @idx: parameter of type int
 *
 * Return: nothing
 */

void handling(char **command, char **av, int *status, int idx)
{
	(void) av;
	(void) idx;

	if (_strcmp(command[0], "exit") == 0)
		exit_func(command, status);

	else if (_strcmp(command[0], "env") == 0)
		env_func(command, status);
}

/**
 * exit_func - to exit shell
 * @command: the command i want
 * @status: to return
 *
 * Return: nothing
 */

void exit_func(char **command, int *status)
{
	free(command);
	exit((*status));
}

/**
 * env_func - to print current enviroment
 * @command: wii write it
 * @status: the status to return
 *
 * Return: nothing
 */

void env_func(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	free(command);
	(*status) = 0;
}
