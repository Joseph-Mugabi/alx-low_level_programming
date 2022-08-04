#include <stdio.h>
#include <stdarg.h>

/**
 * sum_them_all - function that returns the sum of all its parameters
 * @n: total number of parameter
 *
 * Return: sum or if n == 0, returns 0
 */
int sum_them_all(const unsigned int n, ...)
{
	int sum = 0;
	unsigned int i; /* for looping through */

	va_list args;

	if (n == 0)
		return (0);
	va_start(args, n);
	for (i = 0; i < n; i++)
		sum = sum + va_arg(args, int);

	va_end(args);

	return (sum);
}
