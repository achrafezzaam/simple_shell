#include "shell.h"

void check_input(char *cmd)
{
	if (!_strcmp(cmd, "exit"))
	{
		exit(54);
	}
	else if (!_strcmp(cmd, "env"))
	{
		while(*environ)
		{
			_print(*environ);
			environ++;
		}
	}
}
void exec_child(char *argv[])
{
	int status;
	pid_t child_pid;

	check_input(argv[0]);
	if ((argv[0] = file_exist(argv[0])))
	{
		printf("%s\n", argv[0]);
		child_pid = fork();
		if(child_pid == 0)
			execve(argv[0], argv, environ);
		else
			wait(&status);
	}
}
