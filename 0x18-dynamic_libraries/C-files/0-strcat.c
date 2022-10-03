#include "main.h"
#include <string.h>

/**
* _strcat - function that concatenates two strings
* @dest: parameter1
* @src: parameter2
*
* Return: string
*/
char *_strcat(char *dest, char *src)
{
	int len = 0;
	int i = 0;

	while (dest[len] != '\0')
		len++;
	while (src[i] != '\0')
	{
		dest[len] = src[i];
		len++;
		i++;
	}
	dest[len] = '\0';
	return (dest);
}
