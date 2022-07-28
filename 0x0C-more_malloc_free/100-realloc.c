#include "main.h"
#include <stdlib.h>
/**
 * _realloc - allocate memory and set all values to 0
 * @ptr: pointer to the memory previously allocated
 * @old_size: size previously allocated
 * @new_size: new size to reallocate
 *
 * Return: pointer to reallocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	unsigned int j;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		else
			return (p);
	}
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	for (j = 0; j < old_size && j < new_size; j++)
		*((char *)p + j) = *((char *)ptr + j);
	free(ptr);
	return (p);
}
