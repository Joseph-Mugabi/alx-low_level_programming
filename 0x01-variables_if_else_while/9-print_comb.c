#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main -  prints all possible combinations of single-digit numbers.
 * Numbers must be separated by ,, followed by a spac
 * Numbers should be printed in ascending order
 * Return: always 0
 */
int main(void)
{
	int i = '0';

	while (i <= '9')
	{
		putchar(i);
		if (i != '9')
		{
																				putchar(',');
																				putchar(' ');
																			}
		   ++i;
	}
	putchar('\n');
	return (0);

}
