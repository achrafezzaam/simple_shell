#include "shell.h"

int main(void)
{
	ssize_t count;
	size_t len = 0;
	char *line = NULL;
	char *argv[] = {"", NULL};

	prompt();
	while ((count = getline(&line, &len, stdin)) != -1)
	{
		line[count - 1] = '\0';
		argv[0] = line;
		if (!_strcmp(line, "exit"))
		{
			break;
		}
		exec_child(argv[0], argv);
		prompt();
	}
	if (count == -1)
		_putchar('\n');
	free(line);
	return (0);
}
