/*

The median of a list of numbers is essentially it's middle element after sorting.
The same number of elements occur after it as before.
Given a list of numbers with an odd number of elements, can you find the median?

For example, the median of [1 2 3 4 5] is 3, the middle element in the sorted array.

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int
median(int *a, size_t n)
{
	qsort(a, n, sizeof(*a), cmp);
	return a[n / 2];
}

int
main(void)
{
	int a[] = {1, 2, 3, 4, 5};
	printf("%d\n", median(a, nelem(a)));

	int b[] = {0, 1, 2, 4, 6, 5, 3};
	printf("%d\n", median(b, nelem(b)));

	return 0;
}
