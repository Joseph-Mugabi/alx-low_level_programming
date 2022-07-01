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
printf("%s %d is %d and is ", "Last digit of ", n, n % 10);
if (n % 10 > 5)
{
	printf("greater than 5\n");
}
else if (n % 10 == 0)
{
	printf("0\n");
}
else 
{
	printf("lesss than 6 and not 0\n");
}

ireturn (0);
}

