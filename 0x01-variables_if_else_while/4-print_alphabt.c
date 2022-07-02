#include <stdio.h>

/**
 * main -  prints the alphabet in lowercase, followed by a new line.
 * Print all the letters except q and e
 * Return: Always 0
 */
int manin(void)
{
	int ch;

	ch = 'a';
		;
        while (ch <= 'z' )
	{
		if (ch == 'q' || ch == 'e')
		{
			ch;
			continue;
		}
		putchar(ch);
		ch++;
	}
	putchar('\n');
	return (0);
}
