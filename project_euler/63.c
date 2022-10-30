/*

The 5-digit number, 16807=75, is also a fifth power.
Similarly, the 9-digit number, 134217728=89, is a ninth power.

How many n-digit positive integers exist which are also an nth power?

*/

#include <stdio.h>
#include <math.h>

// https://www.mathblog.dk/project-euler-63-n-digit-nth-power/
unsigned long
solve(void)
{
	unsigned long i, n, r;

	r = 0;
	n = 1;
	for (i = 0; i < 10; n++) {
		i = ceil(pow(10, (n - 1.0) / n));
		r += 10 - i;
	}
	return r;
}

int
main(void)
{
	printf("%lu\n", solve());
	return 0;
}
