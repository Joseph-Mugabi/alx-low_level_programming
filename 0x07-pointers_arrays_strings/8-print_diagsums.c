#include "main.h"

/**
* print_diagsums - function that prints the sum of the
* two diagonals of a square matrix of integers.
* @a: the matrix
* @size: the size
*
* Return: nothing
*/
void print_diagsums(int *a, int size)
{
	int b;
	int sum1 = 0;
	int sum2 = 0;

	for (b = 0; b < size; b++)
	{
		sum1 += a[(size + 1) * b];
		sum2 += a[(size - 1) * (b + 1)];
	}
	printf("%d, %d\n", sum1, sum2);
}
