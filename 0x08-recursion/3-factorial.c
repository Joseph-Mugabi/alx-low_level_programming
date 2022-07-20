#include "main.h"

/**
* factorial - function that rturns the factorial of a given number.
* @n: integer
*
* Return: factorial of a given number.
*/
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n <= 1)
		return (1);
	return (n * factorial(n - 1));
}
