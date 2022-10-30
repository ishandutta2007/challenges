/*

Create a function that returns the nth catalan number.
In combinatorial mathematics, the Catalan numbers form a sequence of natural numbers that occur in various counting problems, often involving recursively-defined objects.
They are named after the Belgian mathematician Eugène Charles Catalan (1814–1894). For more info, check out the resource tab.

Examples

getCatalanNumber(0) ➞ 1

getCatalanNumber(6) ➞ 132

getCatalanNumber(8) ➞ 1430

Notes

Inputs are zero and positive integers.

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

long
binomial(long n, long k)
{
	long i, c;

	if (k < 0 || k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;

	k = min(k, n - k);
	c = 1;
	for (i = 0; i < k; i++)
		c = c * (n - i) / (i + 1);
	return c;
}

long
catalan(long n)
{
	if (n < 0)
		return 0;
	return binomial(2 * n, n) / (n + 1);
}

int
main(void)
{
	assert(catalan(0) == 1);
	assert(catalan(3) == 5);
	assert(catalan(7) == 429);
	assert(catalan(8) == 1430);
	assert(catalan(9) == 4862);
	assert(catalan(1) == 1);
	assert(catalan(4) == 14);
	assert(catalan(11) == 58786l);
	assert(catalan(17) == 129644790l);

	return 0;
}
