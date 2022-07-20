#include "main.h"

/**
* _puts_recursion - function that prints a string.
* @s: string parameter
*
*/
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}
	_putchar(*s);
	s++;
	_putchar(s);
}
