/*

Write a function that takes two arguments: a limit, lim, and a list of integers, x.
The function counts up from 0 by cycling through x and skipping numbers until we find the next number that's a multiple of x[i].
For example, when x is the list [5, 7, 3], start counting from 0:

Next multiple of 5 is 5

Next multiple of 7 is 7

Next multiple of 3 is 9

Next multiple of 5 is 10

Next multiple of 7 is 14

Next multiple of 3 is 15

When the count reaches lim or a number above it, return the number of steps it took to reach it. (multiple_cycle(15, [5, 7, 3]) would return 6.)

What is the result of multiple_count(1000000000, [5395, 7168, 2367, 9999, 3])?

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;
typedef long long vlong;

vlong
multiple_count(uvlong l, uvlong *x, size_t n)
{
	uvlong i, u, v;

	if (l == 0)
		return 0;

	if (n == 0)
		return -1;

	u = 0;
	for (i = 0; u <= l; i++) {
		v = x[i % n];
		if (v == 0)
			return -1;
		u = v * ((u / v) + 1);
	}
	return i - 1;
}

int
main(void)
{
	uvlong x1[] = {5, 7, 3};
	uvlong x2[] = {5395, 7168, 2367, 9999, 3};

	assert(multiple_count(15, x1, nelem(x1)) == 6);
	assert(multiple_count(1000000000ULL, x2, nelem(x2)) == 408040LL);

	return 0;
}
