/*

Write a function that returns true if there exists at least one number that is larger than or equal to n.

Notes

Return false for an empty array [].

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
existshigher(int *a, size_t n, int v)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (a[i] >= v)
			return 1;
	}
	return 0;
}

int
main(void)
{
	int a1[] = {5, 3, 15, 22, 4};
	int a2[] = {1, 2, 3, 4, 5};
	int a3[] = {4, 3, 3, 3, 2, 2, 2};
	int a4[] = {2, 2, 2, 2};

	printf("%d\n", existshigher(a1, nelem(a1), 10));
	printf("%d\n", existshigher(a2, nelem(a2), 8));
	printf("%d\n", existshigher(a3, nelem(a3), 4));
	printf("%d\n", existshigher(a4, nelem(a4), 5));
	printf("%d\n", existshigher(a4, 0, 0));

	return 0;
}
