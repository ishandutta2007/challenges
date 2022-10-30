/*

Given an array of integers A sorted in non-decreasing order,
return an array of the squares of each number, also in sorted
non-decreasing order.

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
print(int *a, size_t n)
{
	size_t i;

	printf("[");
	for (i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i + 1 < n)
			printf(",");
	}
	printf("]\n");
}

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

void
test(int *a, size_t n)
{
	size_t i;

	if (n == 0)
		return;

	print(a, n);
	for (i = 0; i < n; i++)
		a[i] *= a[i];
	qsort(a, n, sizeof(*a), cmp);
	print(a, n);
	printf("\n");
}

int
main(void)
{
	int a[] = {-4, -1, 0, 3, 10};
	test(a, nelem(a));

	int b[] = {-7, -3, 2, 3, 11};
	test(b, nelem(b));

	return 0;
}
