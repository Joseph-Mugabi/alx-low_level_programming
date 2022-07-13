#include "main.h"

/**
* _strcmp - function that compares two strings.
* @s1: parameter1
* @s2: parameter2
* Return: integer
*/
int _strcmp(char *s1, char *s2)
{
	int result1, result2;

	result1 = 0;
	while (s1[result1] = s2[result1] && s1[result1] != '\0')
	{
		result1++;
	}
	result2 = s1[result1] - s2[result1];
	return (result2);
}
