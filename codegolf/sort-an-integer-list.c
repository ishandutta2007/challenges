/*

The Challenge
It's quite simple really, sort a list of numbers.

Details
You must sort a list of numbers in ascending order, without using any built-in sorting functions/libraries/etc (i.e. list.sort() in Python).

Input/output can be done in any method you choose, as long as it is human readable.

Standard loopholes are disallowed as always.

Shortest code in bytes wins.

You must explain/list what sort method you used (Bubble, Insertion, Selection, etc.)

Input will not contain duplicates.

Sample Input/Output
Input: 99,-2,53,4,67,55,23,43,88,-22,36,45

Output: -22,-2,4,23,36,43,45,53,55,67,88,99

Note: A near direct opposite of Sort a List of Numbers

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dump(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int
stacksort(int *a, size_t n)
{
	size_t i, j;
	int *p, x;

	p = calloc(n, sizeof(*a));
	if (!p)
		return -errno;

	i = n;
	j = 0;
	while (i > 0) {
		x = a[--i];
		while (j > 0 && p[j - 1] > x)
			a[i++] = p[--j];
		p[j++] = x;
	}

	memcpy(a, p, sizeof(*p) * n);
	free(p);
	return 0;
}

void
test(int *a, size_t n, int *r)
{
	stacksort(a, n);
	dump(a, n);
	assert(!memcmp(a, r, sizeof(*r) * n));
}

int
main(void)
{
	int a1[] = {99, -2, 53, 4, 67, 55, 23, 43, 88, -22, 36, 45};
	int r1[] = {-22, -2, 4, 23, 36, 43, 45, 53, 55, 67, 88, 99};

	int a2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int r2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);

	return 0;
}
