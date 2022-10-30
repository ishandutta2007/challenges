/*

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.

*/
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
movezeroes(int *a, size_t n)
{
	size_t i, j;

	for (i = j = 0; i < n; i++) {
		if (a[i] != 0)
			a[j++] = a[i];
	}
	for (; j < n; j++)
		a[j] = 0;
}

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
test(int *a, size_t n)
{
	movezeroes(a, n);
	print(a, n);
}

int
main(void)
{
	int a[] = {0, 1, 0, 3, 12};
	test(a, nelem(a));
	return 0;
}
