#include "main.h"

/**
 * print_numbers - function that prints the numbers,
 * 0 to 9
 * Return: void
 */
void print_numbers(void)
{
	int a = 0;

	for (a = 0; a < 10; a++)
	{
		_putchar(a);
		a++;
	}

	_putchar('\n');
}
