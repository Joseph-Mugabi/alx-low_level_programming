#include "main.h"

/**
* _sqrt - square root of n, starting from the smallest possible, 0.
* @n: n
* @i: test this i.
* Return: natural square root, or -1 if not natural root
*/
int _sqrt(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (_sqrt(n, i + 1));
}
/**
* _sqrt_recursion - functoin that returns the natural square root of a number.
* @n: integer
*
* Return: square root of a number n.
*/
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt(n, 0));
}
