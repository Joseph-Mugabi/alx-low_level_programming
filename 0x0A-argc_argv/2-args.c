#include <stdio.h>
#include "main.h"

/**
* main - program that prints all arguments it receives.
* @argc: counter arg
* @argv: vector arg
*
* Return: 0
*/
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", arg[i]);
	}
	return (0);
}
