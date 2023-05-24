#include "shell.h"
/**
 * _strlen - Calculate the length of a string.
 *
 * @input: The input string.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *input)
{
	size_t count = 0;

	while (*input)
	{
		count++;
		input++;
	}
	return (count);
}
/**
 * _strcmp - Compare two strings.
 *
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: 0 if the strings are equal, 1 otherwise.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}
/**
 * _strncmp - Compare two strings up to a specified number of characters.
 *
 * @s1: The first string.
 * @s2: The second string.
 * @n: The number of characters to compare.
 *
 * Return: 0 if the strings are equal up to 'n' characters, 1 otherwise.
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (1);
	}
	return (0);
}
/**
 * _print - Print a string followed by a newline character.
 *
 * @str: The string to print.
 */
void _print(char *str)
{
	int i = 0;
	char *dup;

	dup = _strdup(str);
	while (dup[i])
	{
		putchar(dup[i]);
		i++;
	}
	putchar('\n');
}
/**
 * _strcat -Concatenate two strings, with an optional '/' character in between.
 *
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: A pointer to the concatenated string.
 */
char *_strcat(char *str1, char *str2)
{
	char *buff;
	int i = 0;
	size_t path_len = 0;

	path_len = _strlen(str1) + _strlen(str2) + 1;
	if (*str2 != '/')
		path_len++;
	buff = malloc(sizeof(char) * path_len);
	while (*str1 != '\0')
	{
		buff[i] = *str1;
		str1++;
		i++;
	}
	if (*str2 != '/')
	{
		buff[i] = '/';
		i++;
	}
	while (*str2)
	{
		buff[i] = *str2;
		str2++;
		i++;
	}
	return (buff);
}
