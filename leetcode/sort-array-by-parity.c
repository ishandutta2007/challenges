/*

Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;

	if (!(x & 1) && (y & 1))
		return -1;
	if ((x & 1) && !(y & 1))
		return 1;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

void
paritysort(int *a, size_t n)
{
	qsort(a, n, sizeof(*a), cmp);
}

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int
main(void)
{
	int a[] = {3, 1, 2, 4};
	paritysort(a, nelem(a));
	print(a, nelem(a));

	int b[] = {-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 10};
	paritysort(b, nelem(b));
	print(b, nelem(b));

	return 0;
}
