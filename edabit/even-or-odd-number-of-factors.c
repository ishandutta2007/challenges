/*

Create a function that returns "even" if a number has an even number of factors and "odd" if a number has an odd number of factors.
Examples

factorGroup(33) ➞ "even"

factorGroup(36) ➞ "odd"

factorGroup(7) ➞ "even"

Notes

    You don't need to actually calculate the factors to solve this problem.
    Think about why a number would have an odd number of factors.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// https://www.geeksforgeeks.org/number-elements-odd-factors-given-range/
// a number has an odd number of factor if it is a perfect square
// can count number of perfect squares in a range [n, m] using the formula
// sqrt(m) - sqrt(n-1)
const char *
factorgroup(unsigned n)
{
	unsigned x;

	x = sqrt(n);
	return (x * x == n) ? "odd" : "even";
}

void
test(unsigned n, const char *r)
{
	assert(!strcmp(factorgroup(n), r));
}

int
main(void)
{
	test(33, "even");
	test(36, "odd");
	test(7, "even");
	test(1, "odd");
	test(19, "even");
	test(27, "even");
	test(100, "odd");
	test(18, "even");
	test(16, "odd");
	test(0, "odd");
	test(2, "even");

	return 0;
}
