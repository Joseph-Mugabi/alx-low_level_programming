#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_strings - print varying amount of strings
 * @n: amount of arguments in list
 * @separator: delimiter
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int j;
	char *s;

	va_start(args, n);

	if (n > 0)
	{
		for (j = 1; j <= n; j++)
		{
			s = va_arg(args, char *);
			if (s == NULL)
			{
				printf("(nil)");
			}
			else
			{
				printf("%s", s);
			}
			if (j != n && separator != NULL)
			{
				printf("%s", separator);
			}
		}
		va_end(args);
	}
	printf("\n");
}
