#include "main.h"

/**
 * swap_int -  function that swaps the values of two integers
 * @a: parametr1
 * @b: parametr2
 *
 */
void swap_int(int *a, int *b)
{
	int n;

	n = *a;
	*a = *b;
	*b = n;
}
