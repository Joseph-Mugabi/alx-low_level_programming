#include <stdio.h>
#include <stdlib.h>

void free_grid(int **grid, int height);
void print_grid(int **grid, int width, int height);

/**
* free_grid - frees a 2 dimensional grid
* previously created by your alloc_grid function
* @grid: pointer to 2D array
* @height: height of array
*/

void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
		free(grid);

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
/**
 * print_grid - prints a grid of integers
 * @grid: the address of the two dimensional grid
 * @width: width of the grid
 *  @height: height of the grid
 *
 *  Return: Nothing.
 */
void print_grid(int **grid, int width, int height)
{
	int w;
	int h;
	h = 0;
	while (h < height)
	{
		w = 0;
		while (w < width)
		{
			printf("%d", grid[h][w]);
			w++;
		}
		printf("\n");
		h++;
	}
}
/**
 * main - check the code for ALX School students.
 *
 *  Return: Always 0.
 */
int main(void)
{
	int **grid;

	grid = alloc_grid(6, 4);
	if (grid == NULL)
	{
		return (1);
	}
	print_grid(grid, 6, 4);
	printf("\n");
	grid[0][3] = 98;
	grid[3][4] = 402;
	print_grid(grid, 6, 4);
	free_grid(grid, 4);
	return (0);
}
