/*
Charlie and Johnny play a game. For every integer X Charlie gives, Johnny has to find the smallest positive integer Y,
such that X * Y contains only 4's and 0's and starts with one or more 4's followed by zero or more 0's.
(i.e.), 404 is an invalid number but 400 is a valid number.

If a is the number of 4's and b is the number of 0's, can you print the value of 2 * a + b.
*/
#include <stdio.h>
#include <math.h>
#include <limits.h>

unsigned long
ipow(unsigned long x, unsigned long p)
{
	unsigned long i, v;

	v = 1;
	for (i = 0; i < p; i++)
		v *= x;
	return v;
}

unsigned long
gen(unsigned long f, unsigned z)
{
	unsigned long i, p, v;

	p = z;
	v = 0;
	for (i = 0; i < f; i++)
		v += 4 * ipow(10, p++);
	return v;
}

unsigned long
calc(unsigned long x)
{
	unsigned long a, b, n, l;

	if (x == 0)
		return 0;

	l = log10(ULONG_MAX);
	for (a = 1; a <= l; a++) {
		for (b = a - 1;; b--) {
			n = gen(a - b, b);
			if (n % x == 0)
				return 2 * (a - b) + b;

			if (b == 0)
				break;
		}
	}
	return 0;
}

int
main(void)
{
	printf("%lu\n", calc(4));
	printf("%lu\n", calc(5));
	printf("%lu\n", calc(80));
	return 0;
}
