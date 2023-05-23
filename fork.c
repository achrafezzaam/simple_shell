#include "shell.h"

void check_input(char *cmd)
{
	int i = 0;

	if (!_strcmp(cmd, "exit"))
	{
		exit(98);
	}
	else if (!_strcmp(cmd, "env"))
	{
		while(environ[i])
		{
			_print(environ[i]);
			i++;
		}
	}
}
void exec_child(char *argv[])
{
	int status;
	pid_t child_pid;

	check_input(argv[0]);
	if (file_exist(argv[0]))
	{
		argv[0] = file_exist(argv[0]);
		child_pid = fork();
		if(child_pid == 0)
			execve(argv[0], argv, environ);
		else
			wait(&status);
	}
	else
	{
		_print(argv[0]);
		_print(": Not Found");
	}
}
