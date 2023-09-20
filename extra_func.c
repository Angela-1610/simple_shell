#include "shell.h"

/**
 * rev_help - function help in reverse string
 * @n: size od my word
 *
 * Return: new string
 */

char *rev_help(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	rev_string(buffer, i);

	return (_strdup(buffer));
}

/**
 * atoi - changing function
 * @str: char to check
 *
 * Return: result of type int
 */

int atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}

/**
 * rev_string - function that reverses a string
 * @s: the string
 * @i: string's size
 *
 * Return: nothing
*/

void rev_string(char *s, int i)
{
	char x;
	int start = 0;
	int end = i - 1;

	while (start < end)
	{
		x = s[start];
		s[start] = s[end];
		s[end] = x;
		start++;
		end++;
	}
}


/**
 * print_error - prints an error message
 * @name: the first pointer to test
 * @tmp: the second pointer to test
 * @j: will be given length
 *
 * Return: nothing
 */

void print_error(char *name, char *tmp, int j)
{
	char *index;
	char message[] = ": not found\n";

	index = rev_help(j);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, tmp, _strlen(tmp));
	write(STDERR_FILENO, message, _strlen(message));

	free(index);
}
