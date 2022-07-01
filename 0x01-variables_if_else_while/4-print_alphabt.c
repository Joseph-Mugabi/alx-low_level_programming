#include <stdio.h>

/**
 * main -  prints the alphabet in lowercase, followed by a new line.
 * Print all the letters except q and e
 * Return: Always 0
 */
int manin(void)
{
	char c;
       for (c = 'a'; c <= 'z'; c++)
	{
		if (c != 'q' && c != 'e')
		{
			putchar(c);
		}
	}
	putchar(10);
	return (0);
}
