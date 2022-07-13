#include "main.h"

/**
* reverse_array - function that reverses the content of an array of integers.
* @a: array parameter
* @n: integer or number of elem'nt of array
*
*/
void reverse_array(int *a, int n)
{
	int i, j = 0;
	int k = n - 1;

	while (j < k)
	{
		i = *(a + j);
		*(a + j) = *(a + k);
		*(a + k) = i;
		j++, k--;
	}
}
