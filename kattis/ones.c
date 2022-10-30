/*

Given any integer 1≤n≤100000 not divisible by 2 or 5, some multiple of n is a number which in decimal notation is a sequence of 1’s.
How many digits are in the smallest such a multiple of n? There are at most 1000 test cases.

*/

#include <assert.h>
#include <stdio.h>

int
digits(int n)
{
	int c, r;

	c = 1;
	for (r = 1; r % n; c++)
		r = (10 * r + 1) % n;
	return c;
}

int
main(void)
{
	assert(digits(3) == 3);
	assert(digits(7) == 6);
	assert(digits(9901) == 12);

	return 0;
}
