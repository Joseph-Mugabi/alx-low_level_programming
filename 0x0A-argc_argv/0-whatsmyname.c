#include <stdio.h>
#include "main.h"

/**
* main - function prints its name
* @argc: argc counter
* @argv: pointer to array of argument parametr
*
* Return: 0
*/
int main(int argc, char *argv[])
{
	if (argc > 0)
	{
		printf("%s\n", argv[0]);
	}
	return (0);
}
