/*

Create a function that returns the count of all possible paths from top left to bottom right of an m * n matrix with the constraints that from each cell you can either move to the right or down.

Examples

calc(2, 2) ➞ 2

calc(3, 3) ➞ 6

calc(4, 4) ➞ 20

Note:

m may not be equal to n.

*/

#include <assert.h>

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

// https://betterexplained.com/articles/navigate-a-grid-using-combinations-and-permutations/
long
path(long m, long n)
{
	return binomial(n + m - 2, n - 1);
}

int
main(void)
{
	assert(path(2, 2) == 2);
	assert(path(3, 3) == 6);
	assert(path(4, 4) == 20);
	assert(path(2, 1) == 1);
	assert(path(2, 3) == 3);
	assert(path(4, 2) == 4);
	assert(path(3, 4) == 10);
	assert(path(5, 4) == 35);
	assert(path(5, 5) == 70);

	return 0;
}
