#include "main.h"

/**
 * more_numbers - function that prints 10 times the numbers, from 0 to 14
 */

void more_numbers(void)
{
int x, y;

for (x = 0; x < 10; x++)
{
for (y = 0; y < 15; y++)
{
_putchar(y + '0');
}
_putchar('\n');
}

}
