#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <stdbool.h>

/**
* is_num - iterate throu each argv to test if its a numbr
* @argvv: a argv
*
* Return: true only if the entire string is a numbr, false if not.
*/
bool is_num(char *argvv)
{
	int a = 0;

	for (a = 0; argvv[a]; a++)
	{
		if (!(argvv[a] >= '0' && argvv[a] <= '9'))
			return (0);
	}
	return (1);
}
/**
* main -  program that adds positive numbers.
* @argc: argument counter
* @argv: arguments
*
*  Return: 0 or 1 if an argument wasn't a number
*/
int main(int argc, char *argv[])
{
	int i = 1;
	int sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	while (i < argc)
	{
		if (is_num(argv[i]))
			sum += atoi(argv[i]);
		else
		{
			printf("Error\n");
			return (1);
		}
		i++;
	}
	printf("%d\n", sum);
	return (0);
}
