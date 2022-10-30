/*

John works at a clothing store. He has a large pile of socks that he must pair by color for sale.
Given an array of integers representing the color of each sock,
determine how many pairs of socks with matching colors there are.

For example, there are n=7 socks with colors [1 2 1 2 1 3 2].
There is one pair of color 1 and one of color 2.
There are three odd socks left, one of each color.
The number of pairs is 2.

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

size_t
sockpair(int *a, size_t n)
{
	size_t i, c, t;
	int v;

	qsort(a, n, sizeof(*a), cmp);

	t = 0;
	for (i = 0; i < n;) {
		v = a[i];
		c = 1;
		while (a[++i] == v)
			c++;
		t += c / 2;
	}

	return t;
}

int
main(void)
{
	int a[] = {1, 2, 1, 2, 1, 3, 2};
	printf("%zu\n", sockpair(a, nelem(a)));

	int b[] = {10, 20, 20, 10, 10, 30, 50, 10, 20};
	printf("%zu\n", sockpair(b, nelem(b)));

	return 0;
}
