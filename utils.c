#include "shell.h"

int get_count(char *str, char delim)
{
	int count = 0;

	while (*str != '\0')
	{
		if (*str != delim && *(str + 1) == delim)
			count++;
		str++;
	}
	return (count + 1);
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
