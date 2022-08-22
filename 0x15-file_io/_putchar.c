#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: character to print
 * Return: 1 or -1, errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
