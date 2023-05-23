#include "shell.h"
char *getpath(void)
{
	char *path;
	char *dup;
	int i = 0;

	while (environ[i] != NULL)
	{
		if (!_strncmp(environ[i], "PATH", 4))
		{
			dup = _strdup(environ[i]);
			path = strtok(dup, "=");
			path = strtok(NULL, "=");
			return (path);
		}
		i++;
	}
	return (NULL);
}

int file_found(char *path)
{
	struct stat st;
	char *dup = _strdup(path);

	if (stat(dup, &st) == 0)
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
