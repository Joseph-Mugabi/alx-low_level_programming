#include "main.h"

/**
* is_prime_number - function that returns 1 if the input is a prime
* number, otherwise return 0.
* @n: integer or prime number
*
* Return: 1 if the input is a prime nuber or 0 ortherwise
*/
int is_prime_number(int n)
{
	int divisor = 3;

	if (n % 2 == 0 || n < 2)
		return (0);
	if (n == 2)
		return (1);
	return (is_prime(n, divisor));
}
