/*

Task

Take the (integer) number of human years that the dog has lived, n, as input and return its age in dog years, d, to two decimal places.
The number of human years, n, will be between 1 and 122 inclusive: n∈[1,122],n∈N.

According to BBC's Science Focus Magazine, the correct function for determining your dog's age is:
n=16×ln(d)+31

Where

n

is the age in human years

d

is the age in dog years
Rules

The final output in dog years must be a decimal, rounded to 2 decimal places.

*/

#include <stdio.h>
#include <math.h>

double
dogage(int n)
{
	return exp((n - 31) / 16.0);
}

int
main(void)
{
	int i;

	for (i = 1; i <= 122; i++)
		printf("%d %.2f\n", i, dogage(i));
	return 0;
}
