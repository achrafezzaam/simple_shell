#include "shell.h"

/**
 * check_input - Title
 * @cmd: argument 1
 * @str: argument 2
 */
void check_input(char **cmd, char *str)
{
int i = 0;

	if (!_strcmp(cmd[0], "exit"))
	{
		free(str);
		free(cmd);
		exit(98);
	}
	else if (!_strcmp(cmd[0], "env"))
	{
		while (environ[i])
		{
			_print(environ[i]);
			i++;
		}
	}
}
/**
 * exec_child - Title
 * @argv: argument 1
 * @str: argument 2
 */
void exec_child(char *argv[], char *str)
{
	int status;
	pid_t child_pid;

	check_input(argv, str);
	child_pid = fork();
	if (child_pid == 0)
		execve(argv[0], argv, environ);
	else
		wait(&status);
}
/**
 * main - Main function of the program
 *
 * Return: On succes return the value 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t count = 0;
	char **argv;

	while (1)
	{
		count = getline(&line, &len, stdin);
		if (count == -1)
			break;
		argv = cmdarr(line);
		exec_child(argv, line);
	}
	free(argv);
	free(line);
	return (0);
}
