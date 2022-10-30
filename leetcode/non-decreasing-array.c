/*

Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Note: The n belongs to [1, 10,000]. 

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
nondec(int *a, size_t n)
{
	size_t i, d;

	if (n == 0)
		return 0;

	d = 0;
	for (i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1])
			d++;
	}
	return d < 2;
}

int
main(void)
{
	int a1[] = {4, 2, 3};
	int a2[] = {4, 2, 1};
	int a3[] = {4, 4, -2, 13, 4, 2, 45, 2, 3};
	int a4[] = {1, 4, 5, -2, 6, 7, 8, 9, 10};
	int a5[] = {1, 2, 3, 100, 4, 5, 6, 7};
	int a6[] = {1, 2, 3, 1, 4, 5, 6, 7};
	int a7[] = {2, -3};
	int a8[] = {2, -3, 50};
	int a9[] = {2, 4, -1};

	printf("%d\n", nondec(a1, nelem(a1)));
	printf("%d\n", nondec(a2, nelem(a2)));
	printf("%d\n", nondec(a3, nelem(a3)));
	printf("%d\n", nondec(a4, nelem(a4)));
	printf("%d\n", nondec(a5, nelem(a5)));
	printf("%d\n", nondec(a6, nelem(a6)));
	printf("%d\n", nondec(a7, nelem(a7)));
	printf("%d\n", nondec(a8, nelem(a8)));
	printf("%d\n", nondec(a9, nelem(a9)));

	int a10[1024];
	for (size_t i = 0; i < nelem(a10); i++)
		a10[i] = i;
	printf("%d\n", nondec(a10, nelem(a10)));
	a10[45] = 10;
	printf("%d\n", nondec(a10, nelem(a10)));
	a10[46] = 11;
	printf("%d\n", nondec(a10, nelem(a10)));
	a10[47] = -3;
	printf("%d\n", nondec(a10, nelem(a10)));

	return 0;
}
