#include "shell.h"
/**
 * getpath - Get the value of the PATH environment variable.
 *
 * Return: The value of the PATH environment variable.
 */
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
/**
 * file_found - Check if a file exists at the specified path.
 *
 * @path: The path to check.
 *
 * Return: 0 if the file exists, 1 otherwise.
 */
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
/**
 * file_exist - Check if a file exists in the directories specified by the PATH
 *
 *
 * @cmd: The name of the file.
 *
 * Return: The full path to the file if found, NULL otherwise.
 */
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
