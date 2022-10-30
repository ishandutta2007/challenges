/*

A number is said to be Disarium if the sum of its digits raised to their respective positions is the number itself.

Create a function that determines whether a number is a Disarium or not.

Examples

is_disarium(75) ➞ False
# 7^1 + 5^2 = 7 + 25 = 32

is_disarium(135) ➞ True
# 1^1 + 3^2 + 5^3 = 1 + 9 + 125 = 135

is_disarium(544) ➞ False

is_disarium(518) ➞ True

is_disarium(466) ➞ False

is_disarium(8) ➞ True

Notes

    Position of the digit is 1-indexed.
    A recursive version of this challenge can be found via this link.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned long
ipow(unsigned long x, unsigned long n)
{
	unsigned long p;

	if (n == 0)
		return 1;

	while ((n & 1) == 0) {
		x *= x;
		n >>= 1;
	}
	p = x;
	for (n >>= 1; n > 0; n >>= 1) {
		x *= x;
		if ((n & 1) != 0)
			p *= x;
	}

	return p;
}

bool
disarium(unsigned long n)
{
	unsigned long d[sizeof(n) * 10], x, v;
	int i, j;

	x = n;
	i = 0;
	do {
		d[i++] = x % 10;
	} while ((x /= 10));

	v = 0;
	for (j = 0; j < i; j++) {
		v += ipow(d[i - j - 1], j + 1);
		if (v > n)
			return false;
	}
	return v == n;
}

int
main(void)
{
	static const unsigned long itab[] = {
	    6,
	    75,
	    135,
	    466,
	    372,
	    175,
	    1,
	    696,
	    876,
	    89,
	    518,
	    598,
	    0,
	};
	static const bool btab[] = {
	    true,
	    false,
	    true,
	    false,
	    false,
	    true,
	    true,
	    false,
	    false,
	    true,
	    true,
	    true,
	    true,
	};
	size_t i;

	for (i = 0; i < nelem(itab); i++)
		assert(disarium(itab[i]) == btab[i]);

	return 0;
}
