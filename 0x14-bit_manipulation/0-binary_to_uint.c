#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: binary(pointing to a string of 0 nd 1 chars
 *
 * Return: converted number, or 0 if one or more chars in the string
 * b that is not 0 or 1, b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int uint = 0;
	int len = 0, j;

	if (!b)
		return (0);

	uint = 0;
	for (len = 0; b[len] != '\0'; len++)
		;
	for (len--, j = 1; len >= 0; len--, j *= 2)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
		if (b[len] & 1)
			uint += j;
	}

	return (uint);
}
