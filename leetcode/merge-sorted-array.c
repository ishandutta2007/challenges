/*

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

    The number of elements initialized in nums1 and nums2 are m and n respectively.
    You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
merge(int *a, size_t m, int *b, size_t n)
{
	ssize_t i, j, k;

	i = m - 1;
	j = n - 1;
	k = m + n - 1;
	while (i >= 0 && j >= 0)
		a[k--] = (a[i] >= b[j]) ? a[i--] : b[j--];
	while (j >= 0)
		a[k--] = b[j--];
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
	int a[] = {1, 2, 3, 11, 12, 0, 0, 0, 0};
	int b[] = {2, 5, 6, 10};
	merge(a, 5, b, nelem(b));
	print(a, nelem(a));
	return 0;
}
