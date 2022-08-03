#include <stdio.h>

/**
 * print_name - function that prints a name.
 * @name: parameter that func ptr needs
 * @f: func to execute
 *
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}
