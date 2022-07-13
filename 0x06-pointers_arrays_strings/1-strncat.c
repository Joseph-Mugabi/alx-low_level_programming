#include "main.h"

/**
* _strncat - function that concatenates two strings.
* @dest: parameter1
* @src: parameter2
* @n: integer
* Return: string
*/
char *_strncat(char *dest, char *src, int n)
{
	int len = 0;
	int i = 0;

	while (dest[len] != '\0') /* indexing null terminator */
		len++;
	while (src[i] != src[n]) /* appending */
	{
		dest[len] = src[i];
		len++;
		i++;
	}
	dest[len] = '\0';
	return (dest);
}
