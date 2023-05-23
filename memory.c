#include "shell.h"
/**
 * getspaces - Counts the number of spaces in a string.
 *
 * @str: The input string.
 *
 * Return: The number of spaces in the string.
 */
int getspaces(char *str)
{
	int spaces = 0;

	while (*str)
	{
		if (*str == ' ')
			spaces++;
		str++;
	}
	return (spaces);
}

/**
 * getdirnum - Counts the number of colons in a string.
 *
 * @str: The input string.
 *
 * Return: The number of colons in the string.
 */

int getdirnum(char *str)
{
	int num = 0;

	while (*str)
	{
		if (*str == ':')
			num++;
		str++;
	}
	return (num);
}

/**
 * cmdarr - Tokenizes a command line string into an array of strings.
 *
 * @cmdline: The command line string.
 *
 * Return: An array of tokens.
 */

char **cmdarr(char *cmdline)
{
	int spaces, i = 0;
	char *dup = _strdup(cmdline);
	char **output;

	spaces = getspaces(dup);
	output = malloc(sizeof(char *) * (spaces + 2));
	output[0] = strtok(dup, " ");
	while (output[i] != NULL)
	{
		i++;
		output[i] = strtok(NULL, " ");
	}
	return (output);
}
/**
 * patharr - Tokenizes a string of directory paths into an array of strings.
 *
 * @cmdline: The string of directory paths.
 *
 * Return: An array of directory paths.
 */
char **patharr(char *cmdline)
{
	int dirs, i = 0;
	char **output;
	char *dup = _strdup(cmdline);

	dirs = getdirnum(dup);
	output = malloc(sizeof(char *) * (dirs + 2));
	output[0] = strtok(dup, ":");
	while (output[i] != NULL)
	{
		i++;
		output[i] = strtok(NULL, ":");
	}
	return (output);
}
