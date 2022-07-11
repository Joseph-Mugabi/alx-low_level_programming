#include "main.h"

/**
 * _strcpy - update value.
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @dest: value
 * @src: value
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	est[l] = '\0';
	return (dest);
}
