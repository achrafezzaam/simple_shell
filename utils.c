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
