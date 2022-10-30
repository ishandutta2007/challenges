/*

Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.

Note:

    2 <= A.length <= 20000
    A.length % 2 == 0
    0 <= A[i] <= 1000

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swap(int *x, int *y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}

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
	size_t i;

	qsort(a, n, sizeof(*a), cmp);
	for (i = 1; i <= n / 2; i += 2)
		swap(&a[i], &a[n / 2 + i - 1]);
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
	int a[] = {4, 2, 5, 7};
	paritysort(a, nelem(a));
	print(a, nelem(a));

	int b[] = {-4, -2, 0, 1, 5, 3};
	paritysort(b, nelem(b));
	print(b, nelem(b));

	int c[] = {1, 2};
	paritysort(c, nelem(c));
	print(c, nelem(c));

	return 0;
}
