#include "main.h"

/**
 * print_square - prints squares
 * @size: parameter
 * Return:returns nothing
 */
void print_square(int size)
{
	int x, y;

	if (size <= 0)
		_putchar('\n')
	else
	{
		for (x = 0; x < size; x++)
		{
			for (y = 0; y < size ; y++)
			{
				_putchar(35);
			}
			_putchar('\n');
		}
	}
}
