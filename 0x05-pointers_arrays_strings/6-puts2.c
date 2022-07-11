#include "main.h"

/**
 * puts2 - print pair values.
 * @str: value to be evaluate.
 * function that prints every other character of a string
 *
 */
void puts2(char *str)
{
	int len = 0;
	int l = 0;
	int z;
	char *y = str;

	while (*y != '\0')
	{
		y++;
		len++;
	}
	l = len - 1;
	for (z = 0; z <= l ; z++)
	{
		if (z % 2 == 0)
		{
			_putchar(str[z]);
		}
	}
	_putchar('\n');
}
