/*

Create a function that takes a number a and finds the missing exponent x so that a when raised to the power of x is equal to b.

Notes

a is raised to the power of what in order to equal b?

*/

#include <stdio.h>
#include <math.h>

double
solveforexp(unsigned long a, unsigned long b)
{
	return log10(b) / log10(a);
}

int
main(void)
{
	printf("%lf\n", solveforexp(4ul, 1024ul));
	printf("%lf\n", solveforexp(2ul, 1024ul));
	printf("%lf\n", solveforexp(9ul, 3486784401ul));
	printf("%lf\n", solveforexp(4ul, 4294967296ul));
	printf("%lf\n", solveforexp(8ul, 134217728ul));
	printf("%lf\n", solveforexp(19ul, 47045881ul));
	printf("%lf\n", solveforexp(10ul, 100000000ul));
	return 0;
}
