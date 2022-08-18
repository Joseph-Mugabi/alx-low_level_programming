#include "main.h"

/**
 * flip_bits - returns the number of bits you would
 * need to flip to get from one number to another.
 * @n: unsigned long int1
 * #m: unsigned long int2
 * Return: bits difference
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int nbits = 0;
	unsigned long int differ;

	differ = n ^ m;

	do {
		nbits += (differ & 1);
		differ >>= 1;
	} while
		(differ > 0);

	return (nbits);
}
