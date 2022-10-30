/*

You are given a number of sticks of varying lengths. You will iteratively cut the sticks into smaller sticks,
discarding the shortest pieces until there are none left.
At each iteration you will determine the length of the shortest stick remaining,
cut that length from each of the longer sticks and then discard all the pieces of that shortest length.
When all the remaining sticks are the same length, they cannot be shortened so discard them.

For each operation, print the number of sticks that are present before the operation on separate lines.

*/
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

void
cut(int *a, size_t n)
{
	size_t i;

	qsort(a, n, sizeof(*a), cmp);
	printf("%zu\n", n);
	for (i = 1; i < n; i++) {
		if (a[i] != a[i - 1])
			printf("%zu\n", n - i);
	}
	printf("\n");
}

int
main(void)
{
	int a[] = {5, 4, 4, 2, 2, 8};
	cut(a, nelem(a));

	int b[] = {1, 2, 3, 4, 3, 3, 2, 1};
	cut(b, nelem(b));

	int c[] = {1, 2, 3};
	cut(c, nelem(c));

	return 0;
}
