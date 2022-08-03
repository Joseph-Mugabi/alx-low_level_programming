#include <stddef.h>

/**
 * int_index - function that searches for an integer.
 * @size: size of array
 * @array: array
 * @cmp: pointer to search/compare function
 * Return: index 1 or -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int j;

	if (array == NULL && cmp == NULL && size <= 0)
		return (-1);
	for (j = 0; j < size; j++)
	{
		if (cmp(*(array + j)))
			return (j);
	}
	return (-1);
}
