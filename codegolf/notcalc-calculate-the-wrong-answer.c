/*

Goal:

Given two natural numbers (integers from 0 to infinity), output a number that is not the sum of those numbers, but is a natural number.

Example solutions (TI-Basic):

    A+B+1

    not(A+B)

Invalid solutions:

    A+B-1 (for inputs 0,0, it returns -1, which is not natural)

    "ABC" (ABC is not a number)

Notes:

    The output must always be a sum of two natural numbers (which is actually just a natural number)

    -1, undefined, infinity, NaN and Error messages are not natural numbers. For our purposes, 0 is natural (although not all mathematicians agree).

*/

#include <assert.h>
#include <limits.h>

unsigned
nocalc(unsigned a, unsigned b)
{
	return ~(a ^ b);
}

int
main(void)
{
	unsigned N;
	unsigned a, b;

	N = 10000;
	for (a = 0; a <= N; a++) {
		for (b = 0; b <= N; b++) {
			assert(nocalc(a, b) != (a + b));
		}
	}
	a = b = UINT_MAX;
	assert(nocalc(a, b) != (a + b));

	return 0;
}
