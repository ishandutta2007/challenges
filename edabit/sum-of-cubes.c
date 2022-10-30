/*

Create a function that takes in an array of numbers and returns the sum of its cubes.

Notes

If given an empty array, return 0.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
sumcubes(int *a, size_t n)
{
	size_t i;
	int s;

	s = 0;
	for (i = 0; i < n; i++)
		s += a[i] * a[i] * a[i];
	return s;
}

int
main(void)
{
	int a1[] = {1, 5, 9};
	int a2[] = {3, 4, 5};
	int a3[] = {2};
	int a4[] = {1, 1, 1};
	int a5[] = {5, 1, 2};
	int a6[] = {32};
	int a7[] = {5, 9, 4, 4, 9};
	int a8[] = {0, 1, 2};

	printf("%d\n", sumcubes(a1, nelem(a1)));
	printf("%d\n", sumcubes(a2, nelem(a2)));
	printf("%d\n", sumcubes(a3, nelem(a3)));
	printf("%d\n", sumcubes(a3, 0));
	printf("%d\n", sumcubes(a4, nelem(a4)));
	printf("%d\n", sumcubes(a5, nelem(a5)));
	printf("%d\n", sumcubes(a6, nelem(a6)));
	printf("%d\n", sumcubes(a7, nelem(a7)));
	printf("%d\n", sumcubes(a8, nelem(a8)));
	printf("%d\n", sumcubes(a8, 0));
	return 0;
}
