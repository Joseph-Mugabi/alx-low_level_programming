#include <unistd.h>

/**
 * _putchar - write a character c to the stdout
 *
 * Return: char
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
