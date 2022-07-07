#include "main.h"

/**
* main - function that checks for uppercase character.
* @c: single string input
* return: 1 if c is uppercase
* Return: 0
*/

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
