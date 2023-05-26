#include "shell.h"
/**
 * _strlen - Calculate the length of a string.
 *
 * @str: The input string.
 *
 * Return: The length of the string.
 */
int _strlen(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}
/**
 * _strdup - Create a duplicate of a string.
 *
 * @str: The string to duplicate.
 *
 * Return: A pointer to the newly allocated duplicate string.
 */
char *_strdup(char *str)
{
	int len;
	char *dup;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	dup = malloc((sizeof(char) * len) + 1);
	if (dup == NULL)
		return (NULL);
	dup[len] = '\0';
	while (len--)
		dup[len] = str[len];
	return (dup);
}
/**
 * _strcpy - Create a copy of a string.
 * @dest: The string to copy to
 * @src: The string to copy from.
 *
 * Return: A pointer to @dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
