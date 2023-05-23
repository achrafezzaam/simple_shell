#include "shell.h"

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

void _print(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}

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
