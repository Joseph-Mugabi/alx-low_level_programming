#include "main.h"

/**
 * get_endianness - checks the endianness.
 *
 * 4 byte int to hold some hexadecimal number 0x00000001
 * test if first byte stored is 00 or 01
 * big endian would store 00 and little stores 01
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int x = 0x00000001;
	char *c = (char *)&x;

	return (c[0]);
}
