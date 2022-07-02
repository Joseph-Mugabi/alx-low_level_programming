#include <stdio.h>

/**
 * main -  prints the alphabet in lowercase, followed by a new line.
 * Print all the letters except q and e
 * Return: Always 0
 */
int main(void)
{
	int alphabets;

	alphabets = 'a';

        while (alphabets <= 'z' )
	{
		if (alphabets == 'q' || alphabets == 'e')
		{
			alphabets;
			continue;
		}
		putchar(alphabets);
		alphabets++;
	}
	putchar('\n');
	return (0);
}
