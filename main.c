#include "shell.h"

void exec_child(char *argv[])
{
        int status;
        pid_t child_pid;

        child_pid = fork();
        if (child_pid == 0)
                execve(argv[0], argv, environ);
	else        
		wait(&status);
}

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t count = 0;
	char **argv;

	while (1)
	{
		if ((count = getline(&line, &len, stdin)) == -1)
			break;
		argv = cmdarr(line);
		exec_child(argv);
	}
	free(argv);
	free(line);
	return (0);
}
