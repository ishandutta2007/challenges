/*

The purpose of this problem is to verify whether the method you are using to read input data is sufficiently fast to handle problems branded with the enormous Input/Output warning.

You are expected to be able to process at least 2.5MB of input data per second at runtime.

Input

The input begins with two positive integers n k (n, k<=10^7). The next n lines of input contain one positive integer ti, not greater than 10^9, each.

Output

Write a single integer to output, denoting how many integers ti are divisible by k.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
count(uvlong *a, size_t n, uvlong k)
{
	size_t i;
	uvlong r;

	r = 0;
	for (i = 0; i < n; i++)
		r += ((a[i] % k) == 0);
	return r;
}

int
main(void)
{
	uvlong a1[] = {1, 51, 966369ULL, 7, 9, 999996ULL, 11};

	assert(count(a1, nelem(a1), 3) == 4);

	return 0;
}
