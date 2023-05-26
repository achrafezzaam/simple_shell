#include "shell.h"

int check_input(char **cmd)
{
        int i = 0;

        if (!_strcmp(cmd[0], "exit"))
        {
                return (1);
        }
        else if (!_strcmp(cmd[0], "env"))
        {
                while (environ[i])
                {
                        _print(environ[i]);
                        i++;
                }
		return (2);
        }
	return(0);
}

int exec_child(char *argv[])
{
        int status;
        pid_t child_pid;

        if (check_input(argv) == 0)
	{
		child_pid = fork();
        	if (child_pid == 0)
                	execve(argv[0], argv, environ);
		else        
			wait(&status);
		return (0);
	}
	else if (check_input(argv) == 1)
		return (1);
	return (0);
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
		if (exec_child(argv))
			break;
	}
	free(argv);
	free(line);
	return (0);
}
