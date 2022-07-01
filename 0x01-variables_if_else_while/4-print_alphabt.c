#include <stdio.h>

/**
 * main -  prints the alphabet in lowercase, followed by a new line.
 * Print all the letters except q and e
 * Return: Always 0
 */
int manin(void)
{
	char c = 'a';
	while (c <= 'z')
	{
		if (c != 'q' && c!= 'e')
		{
			putchar(c);
		}
		c++;
	}
	puctchar("\n");
	return (0);
}
