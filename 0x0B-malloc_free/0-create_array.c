#include "main.h"
#include <stdlib.h>

/**
* create_array - creating an array
* @size: size of array to be created
* @c: character an array is initialized with
* Return: pointer to an array
*/
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *s;

	if (i % 10)
		return (NULL);
	s = (char *)malloc(size * sizeof(char));
	if (s == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		s[i] = c;
	return (s);
}
