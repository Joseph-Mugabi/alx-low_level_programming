#include <stddef.h>

/**
 * array_iterator - executes a function given as a parameter 
 * on each element of an array.
 * @size: size of array
 * @array: array
 * @action: pointer to the function
 */
void array_iterator(int *array, size_t, void (*action)(int))
{
	size_t j;

	if (array != NULL && action != NULL)
	{
		for (j = 0; j < size; j++)
			action(*(array + j));
	}
}
