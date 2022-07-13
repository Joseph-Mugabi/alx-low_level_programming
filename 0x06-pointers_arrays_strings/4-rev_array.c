#include "main.h"

/**
* reverse_array - function that reverses the content of an array of integers.
* @a: array parameter
* @n: integer or number of elem'nt of array
*
*/
void reverse_array(int *a, int n)
{
	int *p, i, aux, k;

	p =  a;
	for (i = 0; i < n; i++)
		i++;
	for (k = 0; k <= n; k++)
	{
		aux = a[k];
		a[k] = *p;
		*p = aux;
		p--;
	}
}
