#include "shell.h"

int getspaces(char *str)
{
	int spaces = 0;

	while (*str)
	{
		if (*str == ' ')
			spaces++;
		str++;
	}
	return spaces;
}

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

char **cmdarr(char *cmdline)
{
	int spaces, i = 0;
	char *dup = _strdup(cmdline);
	char **output;

	spaces = getspaces(dup);
	output = malloc(sizeof(char *) * (spaces + 2));
	output[0] = strtok(dup, " ");
	while(output[i] != NULL)
	{
		i++;
		output[i] = strtok(NULL, " ");
	}
	return (output); 
}

char **patharr(char *cmdline)
{
        int dirs, i = 0;
        char **output;
	char *dup = _strdup(cmdline);

        dirs = getdirnum(dup);
        output = malloc(sizeof(char *) * (dirs + 2));
        output[0] = strtok(dup, ":");
        while(output[i] != NULL)
        {
                i++;
                output[i] = strtok(NULL, ":");
        }
        return (output);
}
