/*

Given an array A of positive lengths, return the largest perimeter of a triangle with non-zero area, formed from 3 of these lengths.

If it is impossible to form any triangle of non-zero area, return 0.

Note:

    3 <= A.length <= 10000
    1 <= A[i] <= 10^6

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

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
maxperim(unsigned *a, size_t n)
{
	size_t i;

	if (n < 3)
		return 0;

	qsort(a, n, sizeof(*a), cmp);
	for (i = n - 3;; i--) {
		if (a[i] + a[i + 1] > a[i + 2])
			return a[i] + a[i + 1] + a[i + 2];
		if (i == 0)
			break;
	}
	return 0;
}

void
randuints(unsigned *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		a[i] = rand() & 0xffff;
}

int
main(void)
{
	unsigned a1[] = {2, 1, 2};
	unsigned a2[] = {1, 2, 1};
	unsigned a3[] = {3, 2, 3, 4};
	unsigned a4[] = {3, 6, 2, 3};

	srand(time(NULL));

	printf("%u\n", maxperim(a1, nelem(a1)));
	printf("%u\n", maxperim(a2, nelem(a2)));
	printf("%u\n", maxperim(a3, nelem(a3)));
	printf("%u\n", maxperim(a4, nelem(a4)));

	unsigned a[1024];
	int i;
	for (i = 0; i < 10; i++) {
		randuints(a, nelem(a));
		printf("%u\n", maxperim(a, nelem(a)));
	}

	return 0;
}
