#include "main.h"

/**
* print_alphabet_x10 - prints 10 times the alphabet, in lowercase.
*
* Return: 0
*/
void print_alphabet_x10(void)
{
	int m, count;

	count = 0;

	while (count < 10)
	{
		for (m = 'a'; m <= 'z'; m++)
		{
			_putchar(m);
		}
		count++;
		_putchar('\n');
	}
}
