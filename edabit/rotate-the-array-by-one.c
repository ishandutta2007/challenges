/*

Given an array, rotates the values clockwise by one (the last value is sent to the first position).

Check the examples for a better understanding.

Examples

rotateByOne([1, 2, 3, 4, 5]) ➞ [5, 1, 2, 3, 4]

rotateByOne([6, 5, 8, 9, 7]) ➞ [7, 6, 5, 8, 9]

rotateByOne([20, 15, 26, 8, 4]) ➞ [4, 20, 15, 26, 8]

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swap(int *x, int *y)
{
	int t;

	t = *y;
	*y = *x;
	*x = t;
}

void
rot1(int *a, size_t n)
{
	size_t i;
	int p;

	if (n == 0)
		return;

	p = a[n - 1];
	for (i = 0; i < n; i++)
		swap(&a[i], &p);
}

void
test(int *a, size_t n, int *r)
{
	rot1(a, n);
	assert(!memcmp(a, r, sizeof(*r) * n));
}

int
main(void)
{
	int a1[] = {1, 2, 3, 4, 5};
	int r1[] = {5, 1, 2, 3, 4};

	int a2[] = {6, 5, 8, 9, 7};
	int r2[] = {7, 6, 5, 8, 9};

	int a3[] = {20, 15, 26, 8, 4};
	int r3[] = {4, 20, 15, 26, 8};

	int a4[] = {7, 8, 6, 4, 5};
	int r4[] = {5, 7, 8, 6, 4};

	int a5[] = {5, 9, 45, 1, 2};
	int r5[] = {2, 5, 9, 45, 1};

	int a6[] = {5, 9, 45, 1, 2, 8, 10, 12, 15};
	int r6[] = {15, 5, 9, 45, 1, 2, 8, 10, 12};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(a4, nelem(a4), r4);
	test(a5, nelem(a5), r5);
	test(a6, nelem(a6), r6);

	return 0;
}
