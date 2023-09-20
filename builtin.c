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
		exit_func(command, av, status, idx);

	else if (_strcmp(command[0], "env") == 0)
		env_func(command, status);
}
/**
 * positive - check positivity
 * @str: char to check
 *
 * Return: 1 if success or 0 if fail
 */

void positive(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * exit_func - to exit shell
 * @command: the command i want
 * @av: arguments
 * @status: to return
 * @idx: index of type int
 *
 * Return: nothing
 */

void exit_func(char **command, char **av, int *status, int idx)
{
	int value = (*status);
	char *index, message[] = ":exit";

	if (command[1])
	{
		if (positive(command[1]))
		{
			value = atoi(command[1]);
		}
		else
		{
			index = rev_help(idx);

			write(STDERR_FILENO, av[0], _strlen(av[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, message, _strlen(message));
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			return;
		}
	}
	free(command);
	exit(value);
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
