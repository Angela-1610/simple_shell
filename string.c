#include "shell.h"
#include <string.h>

/**
 * _strdup - function return pointer to newly allocated space in memory
 * @str: string given as a parameter
 *
 * Return: pointer or null if fail
 */

char *_strdup(char *str)
{
	char *z;
	int i, j;

	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
		;

	z = (char *) malloc(i * sizeof(*z) + 1);  /* +1 as the end of string '\0' */

	if (z == NULL)
		return (NULL);

	for (j = 0; j < i; j++)
	{
		z[j] = str[j];
	}

	return (z);
}


/**
 * _strlen - function that returns the length of a string
 * @s: the character
 *
 * Return: length of string
*/

int _strlen(char *s)
{
	int i;

	for (i = 0; *s != '\0'; s++)
	{
		i++;
	}

	return (i);
}


/**
 * _strcmp - function that compares two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: result of compare both
*/

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*s1)
	{
		if (*s1 != *s2)
		{
			i = ((int)*s1 - '0') - ((int)*s2 - '0');
			break;
		}
		s1++;
		s2++;
	}

	return (i);
}


/**
 * *_strcat -  function that concatenates two strings
 * @dest: the first string
 * @src: the second string
 *
 * Return: a pointer to the resulting string dest
*/

char *_strcat(char *dest, char *src)
{
	int x, y;

	x = 0;
	while (dest[x])
	{
		x++;
	}
	for (y = 0; src[y]; y++)
	{
		dest[x] = src[y];
		x++;
	}

	return (dest);
}


/**
 * *_strcpy - function that copies the string pointed
 * @src: the string
 * @dest: the copy of the srting
 *
 * Return: the pointer to dest
*/

char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');

	return (dest);
}
