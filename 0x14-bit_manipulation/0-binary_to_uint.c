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

	if (b == NULL)
		return (uint);

	/* this is to find the length */
	while (b[len] !='\0')
		len++;
	len -= 1;

	/* iterate through the string  and if '1' then multiply by powr of 2 */
	/* get powr of 2 via binary e.g 1<<3 = 1000 in binary = 8 */
	j = 0;
	while (b[j])
	{
		if ((b[len] != '0') && (b[j] != '1'))
			return (uint);
		if (b[j] == '1')
			uint += (1 * (1 << len));
		j++;
		len--;
	}
	return (uint);
}
