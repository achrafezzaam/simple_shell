#include "shell.h"

char *getpath(void)
{
	char *path;

	while (*environ)
	{
		if (!_strncmp(*environ, "PATH", 4))
		{
			path = strtok(*environ, "=");
			path = strtok(NULL, "=");
			return (path);
		}
		environ++;
	}
	return (NULL);
}

int file_found(char *path)
{
	struct stat st;

	if (stat(path, &st) == 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

char *file_exist(char *cmd)
{
	char *path = getpath();
	char *filepath;
	char **dirarr;

	dirarr = patharr(path);
	if (!file_found(cmd))
		return (cmd);
	while (*dirarr)
	{
		filepath = _strcat(*dirarr, cmd);
		if (!file_found(filepath))
		{
			return (filepath);
		}
		dirarr++;
	}
	return (NULL);
}
