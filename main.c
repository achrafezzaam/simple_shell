#include "shell.h"
/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	ssize_t count;
	size_t len = 0;
	char *line = NULL;
	char **input;

	/*prompt();*/
	while ((count = getline(&line, &len, stdin)) != -1)
	{
		if (line[count - 1] == '\n')
			line[count - 1] = '\0';
		input = cmdarr(line);
		exec_child(input);
		/*prompt();*/
	}
	/**
	 *if (count == -1)
	 *	_putchar('\n');
	 */
	free(line);
	return (0);
}
