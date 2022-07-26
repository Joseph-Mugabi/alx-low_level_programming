#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* alloc_grid - function that returns a pointer to
*  a 2 dimensional array of integers.
*  @width: width of the array
*  @height: height of the array
*  Return: a pointer to a llocated grid
*/
int **alloc_grid(int width, int height)
{
	int i, j;
	int **a;

	if (width <= 0 || height <= 0) /*validate input */
		return (NULL);

	a = malloc(height * sizeof(int *));/*allocste memory for */
	if (a == NULL) /* validate memory */
	{
		return (NULL);
	}
	for (i = 0; i < height; i++)/* allocating memory for column 0 */
	{
		a[i] = malloc(width * sizeof(int));
		if (a[i] == NULL) /* validating memory */
		{
			for (i = 0; i < height; j++)
			{
				free(a[i]);
			}
			free(a);
			return (NULL):
		}
		for (j = 0; j < width; j++) /* set array value to 0 */
			a[i][j] = 0;
	}
	return (a);
}
