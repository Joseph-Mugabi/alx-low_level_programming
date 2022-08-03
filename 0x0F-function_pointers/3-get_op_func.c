#include <stdlib.h>
#include "3-calc.h"
#include <stdio.h>

/**
 * get_op_func - function to select correct operation func.
 * @s: operation gvn (+,/,*,%,-)
 *
 * Return: pointer to correct op func.
 */
int (*get_op_func(char *s))(int a, int b)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int j = 0;

	while (ops[j].op != NULL)
	{
		if (*s == *ops[j].op)
			return (ops[j].f);
		j++;
	}
	return (NULL);
}
