#include "simple_shell.h"

/**
 *_strdup - returns a pointer to a newly allocated space in memory,
 *which contains a copy of the string given as a parameter.
 *
 *@str: string original.
 *Return: strd string with the copy of the string original.
 */
char *_strdup(char *str)
{
	char *strd;

	if (str == NULL)
	{
		return (NULL);
	}
	strd = malloc(_strlen(str) + 1);
	if (strd == NULL)
	{
		return (NULL);
	}
	_strcpy(strd, str);
	return (strd);
}

/**
 *_strcat - function that concatenates two strings.
 *@dest: char "Hello "
 *@src: char "World!\n";
 *Return: dest <= '\0'
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * char *_strcpy- Copies a string
 *@dest: The new, coppied string
 *@src: The original string to copy
 *
 * Return: Always 0.
 */
char *_strcpy(char *dest, char *src)
{
	int length, i;

	length = _strlen(src);

	for (i = 0; i < length; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 *_strlen - returns the length of a string.
 *@s: char
 *Return: string length
 */
int _strlen(char *s)
{
	int count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

/**
 *_strcmp - compares two strings.
 *@s1: First string.
 *@s2: Second string.
 *Return: return an integer less than (negative value),
 *equal to (0), or greater than (positive value).
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0; /* ver si esta funcion funciona */

	while ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]))
	{
		i++;
	}
	if (s1[i] == s2[i])
	{
		return (0);
	}
	else
	{
		return (s1[i] - s2[i]);
	}
}
