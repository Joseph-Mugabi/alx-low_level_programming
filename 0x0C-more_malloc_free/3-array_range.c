#include "main.h"
#include <stdlib.h>
/**
 * array_range - function that creates an array of integers
 * @max: end range
 * @min: start range 
 *
 * Return: pointer to array
 */
int *array_range(int min, int max)
{
	int *p;
	int j;
	int num = (max -min + 1);

	if (min > max)
		return (NULL);
	p = malloc(sizeof(int) * num);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < num; i++)
		p[i] = min++;
	return (p);
}
