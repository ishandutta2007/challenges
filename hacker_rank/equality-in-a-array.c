/*

Karl has an array of integers. He wants to reduce the array until all remaining elements are equal.
Determine the minimum number of elements to delete to reach his goal.

For example, if his array is arr=[1 2 3], we see that he can delete the 2 elements 1 and 3 leaving arr=[2 2].
He could also delete both twos and either the 1 or the 3, but that would take 3 deletions.
The minimum number of deletions is 2.

Complete the equalizeArray function in the editor below.
It must return an integer that denotes the minimum number of deletions required.

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

#define max(a, b) (((a) > (b)) ? (a) : (b))

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

size_t
equalize(int *a, size_t n)
{
	size_t i, c, m;

	if (n == 0)
		return 0;

	qsort(a, n, sizeof(*a), cmp);

	c = m = 1;
	for (i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			m = max(m, c);
			c = 1;
		} else
			c++;
	}
	m = max(m, c);

	return n - m;
}

int
main(void)
{
	int a[] = {1, 2, 2, 3};
	printf("%zu\n", equalize(a, nelem(a)));

	int b[] = {3, 3, 2, 1, 3};
	printf("%zu\n", equalize(b, nelem(b)));

	int c[] = {1, 2, 3, 1, 2, 3, 3, 3};
	printf("%zu\n", equalize(c, nelem(c)));

	int d[] = {1, 2};
	printf("%zu\n", equalize(d, nelem(d)));
	printf("%zu\n", equalize(d, 1));

	return 0;
}
