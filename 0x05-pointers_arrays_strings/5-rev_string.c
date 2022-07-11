#include "main.h"

/**
 * rev_string -  function that reverses a string.
 * @s: string
 *
 */
void rev_string(char *s)
{
	int i, n;

	n = strlen(s);
	for (i = n - 1; i >= 0; i--)
	{
		_putchar(s[i]);

	}
	_putchar('\n');
}
