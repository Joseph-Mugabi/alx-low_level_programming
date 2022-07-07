#include "main.h"
/**
 * print_most_numbers - prints numbers except 2 and 4
 *
 * Return: returns nothing
 */
void print_most_numbers(void)
{
	int a;

	while (a <= 9)
	{
		if ((a != 2) && (a != 4))
		{
			_putchar(a + '0');
		}
		a++;
	}
	_putchar('\n');
}
