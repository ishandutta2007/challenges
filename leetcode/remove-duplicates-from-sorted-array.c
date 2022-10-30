/*

Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

*/
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
dedup(int *a, size_t n)
{
	size_t i, j;

	if (n == 0)
		return 0;

	for (i = j = 0; i < n - 1; i++) {
		if (a[i] != a[i + 1])
			a[j++] = a[i];
	}
	a[j++] = a[n - 1];
	return j;
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
	int a[] = {1, 1, 2};
	size_t n = dedup(a, nelem(a));
	print(a, n);

	int b[] = {3, 4, 5, 5, 5, 5, 5, 5, 6, 6};
	n = dedup(b, nelem(b));
	print(b, n);

	int c[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	n = dedup(c, nelem(c));
	print(c, n);

	return 0;
}
