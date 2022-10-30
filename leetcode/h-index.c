/*

Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
cmp(const void *a, const void *b)
{
	unsigned x, y;

	x = *(unsigned *)a;
	y = *(unsigned *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

unsigned
hindex(unsigned *a, size_t n)
{
	unsigned h, m;
	size_t i;

	qsort(a, n, sizeof(*a), cmp);

	m = 0;
	for (i = 0; i < n; i++) {
		h = min(a[i], n - i);
		if (h > m)
			m = h;
		if (n - i < a[i])
			break;
	}
	return m;
}

int
main(void)
{
	unsigned a1[] = {0, 0, 0, 0};
	unsigned a2[] = {12, 312, 33, 12};
	unsigned a3[] = {1, 2, 3, 4, 5, 6, 7};
	unsigned a4[] = {22, 33, 1, 2, 4};
	unsigned a5[] = {1000, 2, 2, 2};
	unsigned a6[] = {23, 42, 12, 92, 39, 46, 23, 56, 31, 12, 43, 23, 54, 23, 56, 73, 35, 73, 42, 12, 10, 15, 35, 23, 12, 42};
	unsigned a7[] = {3, 0, 6, 1, 5};
	unsigned a8[] = {0};
	unsigned a9[] = {1};
	unsigned a10[] = {1, 2, 2};
	unsigned a11[] = {2, 2};

	assert(hindex(a1, nelem(a1)) == 0);
	assert(hindex(a2, nelem(a2)) == 4);
	assert(hindex(a3, nelem(a3)) == 4);
	assert(hindex(a4, nelem(a4)) == 3);
	assert(hindex(a5, nelem(a5)) == 2);
	assert(hindex(a6, nelem(a6)) == 20);
	assert(hindex(a7, nelem(a7)) == 3);
	assert(hindex(a8, nelem(a8)) == 0);
	assert(hindex(a9, nelem(a9)) == 1);
	assert(hindex(a10, nelem(a10)) == 2);
	assert(hindex(a11, nelem(a11)) == 2);

	return 0;
}
