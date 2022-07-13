#include "main.h"

/**
* string_toupper - function that changes all 
* lowercase letters of a string to uppercase.
* @x: string parameter
* Return: *s
*/
char *string_toupper(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
	}
	return (s);
}
