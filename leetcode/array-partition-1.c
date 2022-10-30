/*

Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Note:
    n is a positive integer, which is in the range of [1, 10000].
    All the integers in the array will be in the range of [-10000, 10000].


*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int
minpart(int *a, size_t n)
{
	size_t i;
	int r;

	qsort(a, n, sizeof(*a), cmp);
	for (i = 0; i < n; i += 2)
		r += a[i];
	return r;
}

int
main(void)
{
	int a[] = {1, 4, 3, 2};
	printf("%d\n", minpart(a, nelem(a)));

	int b[] = {1, 3, 54, 3, 2, 3, 4, 5, 6, 10};
	printf("%d\n", minpart(b, nelem(b)));

	return 0;
}
