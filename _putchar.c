#include "shell.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * prompt - write the character c to stdout
 *
 * Return: On success 1.
 */
void prompt(void)
{
	_putchar('$');
	_putchar(' ');
}
