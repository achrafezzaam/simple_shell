#include "shell.h"
/**
 * _strdup - Create a duplicate of a string.
 *
 * @str: The string to duplicate.
 *
 * Return: A pointer to the newly allocated duplicate string.
 */
char *_strdup(char *str)
{
	char *dup;
	int i = 0;
	size_t len = _strlen(str);

	dup = malloc(sizeof(char *) * len);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}
