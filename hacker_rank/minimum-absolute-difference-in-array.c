/*

Consider an array of integers, arr=[arr[0], arr[1] ...].
We define the absolute difference between two elements, a[i] and a[j] (where i != j), to be the absolute value of
|a[i]-a[j]|.

Given an array of integers, find and print the minimum absolute difference between any two elements in the array. 

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int
mad_slow(int *a, size_t n)
{
	size_t i, j;
	int m;

	m = INT_MAX;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++)
			m = min(m, abs(a[i] - a[j]));
	}
	return m;
}

int
cmp(const void *a, const void *b, void *u)
{
	int x = *(int *)a;
	int y = *(int *)b;
	int *m = u;
	*m = min(*m, abs(x - y));
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int
mad(int *a, size_t n)
{
	int m;

	if (n <= 1)
		return 0;

	m = INT_MAX;
	qsort_r(a, n, sizeof(*a), cmp, &m);
	return m;
}

int
main(void)
{
	int a[] = {-2, 2, 4};
	printf("%d %d\n", mad_slow(a, nelem(a)), mad(a, nelem(a)));

	int b[] = {3, -7, 0};
	printf("%d %d\n", mad_slow(b, nelem(b)), mad(b, nelem(b)));

	int c[] = {-59, -36, -13, 1, -53, -92, -2, -96, -54, 75};
	printf("%d %d\n", mad_slow(c, nelem(c)), mad(c, nelem(c)));

	int d[] = {1, -3, 71, 68, 17};
	printf("%d %d\n", mad_slow(d, nelem(d)), mad(d, nelem(d)));

	srand(time(NULL));
	static int f[32768];
	for (int i = 0; i < 8; i++) {
		for (size_t j = 0; j < nelem(f); j++)
			f[j] = rand();
		printf("%d %d\n", mad_slow(f, nelem(f)), mad(f, nelem(f)));
	}

	return 0;
}
