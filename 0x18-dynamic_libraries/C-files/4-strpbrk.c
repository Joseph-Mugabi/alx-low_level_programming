#include "main.h"

/**
* _strpbrk - function that searches a sting for any of a set of bytes.
* @s: source string
* @accept: accepted characters
* Return: the string
*/
char *_strpbrk(char *s, char *accept)
{
	int a = 0, b;

	while (s[a])
	{
		b = 0;
		while (accept[b])
		{
			if (s[a] == accept[b])
			{
				s += a;
				return (s);
			}
			b++;
		}
		a++;
	}
	return ('\0');
}
