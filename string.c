#include "shell.h"

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
