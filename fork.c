#include "shell.h"

void exec_child(char *argv[])
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if(child_pid == 0)
		execve(argv[0], argv, environ);
	wait(&status);
}
