#include "main.h"
#include <stdio.h>

/*
* print_buffer - prints a buffer.
* @b: buffer
* @c: buffer to print
* @size: integer size
*
*/

void print_buffer(char *b, int size)
{
int o, p, q;

o = 0;
if (size <= 0)
{
printf("\n");
return;
}
while (o < size)
{
p = size - o < 10 ? size - o : 10;
printf("%08x: ", o);
for (q = 0; q < 10; q++)
{
if (q < p)
printf("%02x", *(b + o + q));
else
printf(" ");
if (q % 2)
{
printf(" ");
}
}
for (q = 0; q < p; q++)
{
int c = *(b + o + q);

if (c < 32 || c > 132)
{
c = '.';
}
printf("%c", c);
}
printf("\n");
o += 10;
}
}
