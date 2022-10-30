/*

Mark and Jane are very happy after having their first child. Their son loves toys, so Mark wants to buy some.
There are a number of different toys lying in front of him, tagged with their prices. Mark has only a certain amount to spend,
and he wants to maximize the number of toys he buys with this money.

Given a list of prices and an amount to spend, what is the maximum number of toys Mark can buy?
For example, if prices=[1 2 3 4] and Mark has 7 to spend, he can buy items [1 2 3] for 6, or [3 4] for 7 units of currency.
He would choose the first group of 3 items.

A toy can't be bought multiple times.

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
buyout(int *a, size_t n, int k)
{
	size_t i, c;

	qsort(a, n, sizeof(*a), cmp);

	c = 0;
	for (i = 0; i < n; i++) {
		if (k < a[i])
			break;
		k -= a[i];
		c++;
	}
	return c;
}

int
main(void)
{
	int a[] = {1, 2, 3, 4};
	printf("%zu\n", buyout(a, nelem(a), 7));

	int b[] = {1, 12, 5, 111, 200, 1000, 10};
	printf("%zu\n", buyout(b, nelem(b), 50));

	int c[] = {3, 7, 2, 9, 4};
	printf("%zu\n", buyout(c, nelem(c), 15));

	return 0;
}
