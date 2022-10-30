/*

Create a function that takes two arrays and insert the second array in the middle of the first array.

Examples

tuckIn([1, 10], [2, 3, 4, 5, 6, 7, 8, 9]) ➞ [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

tuckIn([15,150], [45, 75, 35]) ➞ [15, 45, 75, 35, 150]

tuckIn([[1, 2], [5, 6]], [[3, 4]]) ➞ [[1, 2], [3, 4], [5, 6]]

Notes

    The first array always has two elements.
    Use the spread syntax to solve this challenge.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
print(int *a, size_t n)
{
	size_t i;

	printf("[ ");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("]\n");
}

int *
tuck(int *a, size_t na, int *b, size_t nb)
{
	size_t i;
	int *p;

	p = calloc(na + nb, sizeof(*p));
	if (!p)
		return NULL;

	memcpy(p, a, na / 2 * sizeof(*p));
	i = na / 2;
	memcpy(p + i, b, nb * sizeof(*p));
	i += nb;
	memcpy(p + i, a + na / 2, na / 2 * sizeof(*p));

	return p;
}

void
test(int *a, size_t na, int *b, size_t nb, int *r)
{
	int *p;

	p = tuck(a, na, b, nb);
	assert(p);
	print(p, na + nb);
	assert(!memcmp(p, r, (na + nb) * sizeof(*r)));
	free(p);
}

int
main(void)
{
	int a1[] = {1, 10};
	int b1[] = {2, 3, 4, 5, 6, 7, 8, 9};
	int r1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int a2[] = {15, 150};
	int b2[] = {45, 75, 35};
	int r2[] = {15, 45, 75, 35, 150};

	int a3[] = {1, 0};
	int b3[] = {0, 1, 0, 0};
	int r3[] = {1, 0, 1, 0, 0, 0};

	int a4[] = {'b', 't'};
	int b4[] = {'T', 'V', 'C'};
	int r4[] = {'b', 'T', 'V', 'C', 't'};

	test(a1, nelem(a1), b1, nelem(b1), r1);
	test(a2, nelem(a2), b2, nelem(b2), r2);
	test(a3, nelem(a3), b3, nelem(b3), r3);
	test(a4, nelem(a4), b4, nelem(b4), r4);

	return 0;
}
