/*

Given an array of integers nums, sort the array in ascending order.

Constraints:

1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000

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
	int a1[] = {5, 2, 3, 1};
	int a2[] = {5, 1, 1, 2, 0, 0};

	qsort(a1, nelem(a1), sizeof(*a1), cmp);
	qsort(a2, nelem(a2), sizeof(*a2), cmp);

	print(a1, nelem(a1));
	print(a2, nelem(a2));

	return 0;
}
