/*

Dropsort, designed by David Morgan-Mar, is an example of a linear-time "sorting algorithm" that produces a list that is, in fact, sorted, but contains only some of the original elements.
Any element that is not at least as large as the maximum of the elements preceding it is simply removed from the list and discarded.

In this task, you will be given a list of integers as input (STDIN or function argument, you are required to support at least the range of 8-bit signed integers.) Your task is to dropsort them and then output the remaining elements in order.

You may assume that the list is non-empty.

This is code golf, so the shortest program wins.

Test Cases

Input             Output
1 2 5 4 3 7       1 2 5 7
10 -1 12          10 12
-7 -8 -5 0 -1 1   -7 -5 0 1
9 8 7 6 5         9
10 13 17 21       10 13 17 21
10 10 10 9 10     10 10 10 10

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
dropsort(int *a, size_t n)
{
	size_t i, j;

	if (n == 0)
		return 0;

	for (i = j = 1; i < n; i++) {
		if (a[i] >= a[j - 1])
			a[j++] = a[i];
	}
	return j;
}

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
test(int *a, size_t n, int *r, size_t nr)
{
	n = dropsort(a, n);
	print(a, n);
	assert(n == nr);
	assert(!memcmp(a, r, n * sizeof(*r)));
}

int
main(void)
{
	int a1[] = {1, 2, 5, 4, 3, 7};
	int a2[] = {10, -1, 12};
	int a3[] = {-7, -8, -5, 0, -1, 1};
	int a4[] = {9, 8, 7, 6, 5};
	int a5[] = {10, 13, 17, 21};
	int a6[] = {10, 10, 10, 9, 10};
	int a7[] = {7, 2, 5, 4, 8};
	int a8[] = {9};

	int r1[] = {1, 2, 5, 7};
	int r2[] = {10, 12};
	int r3[] = {-7, -5, 0, 1};
	int r4[] = {9};
	int r5[] = {10, 13, 17, 21};
	int r6[] = {10, 10, 10, 10};
	int r7[] = {7, 8};
	int r8[] = {9};

	test(a1, nelem(a1), r1, nelem(r1));
	test(a2, nelem(a2), r2, nelem(r2));
	test(a3, nelem(a3), r3, nelem(r3));
	test(a4, nelem(a4), r4, nelem(r4));
	test(a5, nelem(a5), r5, nelem(r5));
	test(a6, nelem(a6), r6, nelem(r6));
	test(a7, nelem(a7), r7, nelem(r7));
	test(a8, nelem(a8), r8, nelem(r8));

	return 0;
}
