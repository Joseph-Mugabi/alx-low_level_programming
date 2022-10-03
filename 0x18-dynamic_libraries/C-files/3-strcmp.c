#include "main.h"

/**
* _strcmp - function that compares two strings.
* @s1: parameter1
* @s2: parameter2
* Return: integer
*/
int _strcmp(char *s1, char *s2)
{
	int i;
	int R;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	R = s1[i] - s2[i];
	return (R);
}
