#include "shell.h"
/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(int argc, __attribute__((unused)) char *argv[])
{
	ssize_t count;
	size_t len = 0;
	char *line = NULL;
	char **input;

	if (argc > 2)
		prompt();
	while ((count = getline(&line, &len, stdin)) != -1)
	{
		if (line[count - 1] == '\n')
			line[count - 1] = '\0';
		input = cmdarr(line);
		exec_child(input);
		if (argc > 2)
			prompt();
	}
	if (argc > 2 && count == -1)
		_putchar('\n');
	free(line);
	return (0);
}
