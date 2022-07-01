#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
* main - assign a random number to the variable n each time it is executed.
* print the last digit of the number stored in the variable n.
* Retun: Always 0(success)
*/
int main(void)
{
int n;

srand(time(0));
n = rand() - RAND_MAX / 2;
printf("Last digit of %d is\n", n);
if (n > 5)
{
	printf("is greater than 5");
}
if (n == 0)
{
	printf("is 0");
}
if (n < 6 && n != 0)
	printf("is less than 6 and not 0");
printf("\n");
return (0);
}
