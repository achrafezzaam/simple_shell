#include "shell.h"

void exec_child(char *cmd, char *argv[])
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if(child_pid == 0)
		execve(cmd, argv, environ);
	wait(&status);
}
