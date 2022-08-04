#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * print_numbers - function that prints numbers
 * @separator: delimiter
 * @n: amount of arguments in list
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list list;
	unsigned int j;

	va_start(list, n);

	if (n > 0)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d", va_arg(list, int));
			if (j != n && separator != NULL)
				printf("%s", separator);
		}
		va_end(list);
	}
	printf("\n");
}

