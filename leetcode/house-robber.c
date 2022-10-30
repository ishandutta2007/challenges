/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

long
rob(unsigned *a, size_t n)
{
	size_t i;
	unsigned *p;
	long r;

	p = calloc(n + 2, sizeof(*a));
	if (!p)
		return -1;

	for (i = 0; i < n; i++)
		p[i + 2] = max(p[i + 1], p[i] + a[i]);

	r = p[n + 1];
	free(p);
	return r;
}

int
main(void)
{
	unsigned h1[] = {1, 2, 3, 1};
	unsigned h2[] = {2, 7, 9, 3, 1};
	unsigned h3[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	printf("%ld\n", rob(h1, nelem(h1)));
	printf("%ld\n", rob(h2, nelem(h2)));
	printf("%ld\n", rob(h2, 0));
	printf("%ld\n", rob(h3, nelem(h3)));
	return 0;
}
