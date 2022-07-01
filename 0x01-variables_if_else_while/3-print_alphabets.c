#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase, then in uppercase.
 * Return: Always 0
 */
int main(void)
{
	char b = 'a';
	char c = 'A';

	while (b <= 'z')
	{
		putchar(b);
		b++;
	}
	while (c <= 'A')
	{
		putchar(c);
		c++;
	}
	return (0);
}

