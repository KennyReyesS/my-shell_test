#include "simple_shell.h"

/**
 *_strdup - duplicates a string
 *@str: string to dupplicate
 *Return: NULL on error or empty, return duplicated string.
 */
char *_strdup(char *str)
{
	int i;
	int j;
	char *c;

	if (str == 0)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		;
	}
	c = malloc(sizeof(char) * (i + 1));
	if (c == 0)
	{
		return (NULL);
	}
	for (j = 0; str[j] != '\0'; j++)
	{
		c[j] = str[j];
	}
	c[j] = '\0';
	return (c);
}

/**
 * _strcat - function
 * @dest: string to add to
 * @src: string to add
 *
 * Description: functions to concat two strings
 * Return: string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	for (i = 0 ; dest[i] != '\0' ; i++)
	{
	}
	for (j = 0 ; src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';
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
 * _strlen - function
 * @s: first operand & pointer
 *
 * Description: function that returns the length of a string
 * Return: Always 0
 */
int _strlen(char *s)
{
	int index = 0;

	while (*s != '\0')
	{
		index++;
		s++;
	}
	return (index);
}

/**
 * _strcmp - function
 * @s1: string to compare to
 * @s2: string to compare
 * @n: # of characters to compare to s1
 *
 * Description: function to compare to strings up to the nth character
 * Return: 0 Success
 */
int _strcmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1++ != *s2++)
			return (*(unsigned char *)(s1 - 1) - *(unsigned char *)(s2 - 1));
	}
	return (0);
}
