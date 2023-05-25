#include "shell.h"

char **cmdarr(char *str)
{
	char **output;
	int i = 0, elems = 0;

	/*dup = _strdup(str);*/
	elems = get_count(str, ' ');
	output = malloc(sizeof(char *) * (elems + 1));
	output[0] = strtok(str, " \n");
	for (i = 1; i < elems; i++)
	{
		output[i] = strtok(NULL, " \n");
	}
	output[elems] = NULL;
	return (output);
}
