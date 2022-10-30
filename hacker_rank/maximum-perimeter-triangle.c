/*

Given an array of stick lengths, use of them to construct a non-degenerate triange with the maximum possible perimeter. Print the lengths of its sides as
space-separated integers in non-decreasing order.

If there are several valid triangles having the maximum perimeter:

    Choose the one with the longest maximum side.
    If more than one has that maximum, choose from them the one with the longest minimum side.
    If more than one has that maximum as well, print any one them.

If no non-degenerate triangle exists, print -1.

*/
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	unsigned x = *(unsigned *)a;
	unsigned y = *(unsigned *)b;
	if (x > y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

void
maxperim(unsigned *a, size_t n)
{
	size_t i;

	qsort(a, n, sizeof(*a), cmp);
	for (i = 0; i < n - 2; i++) {
		if (a[i] < a[i + 1] + a[i + 2]) {
			printf("%u %u %u\n", a[i + 2], a[i + 1], a[i]);
			return;
		}
	}
	printf("%d\n", -1);
}

int
main(void)
{
	unsigned a[] = {1, 2, 3, 4, 5, 10};
	maxperim(a, nelem(a));

	unsigned b[] = {1, 1, 1, 3, 3};
	maxperim(b, nelem(b));

	unsigned c[] = {1, 2, 3};
	maxperim(c, nelem(c));

	unsigned d[] = {1, 1, 1, 2, 3, 5};
	maxperim(d, nelem(d));

	return 0;
}
