/*

Create a function that finds the index of a given item.

Notes

If the item is not present, return -1.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <inttypes.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

ssize_t
search(int *a, ssize_t n, int v)
{
	ssize_t i;

	for (i = 0; i < n; i++) {
		if (a[i] == v)
			return i;
	}
	return -1;
}

int
main(void)
{
	int a1[] = { 1, 5, 3 };
	int a2[] = { 9, 8, 3 };
	int a3[] = { 1, 2, 3 };
	int a4[] = { 1, 5, 3, 10, 17, 20, -6 };

	printf("%zd\n", search(a1, nelem(a1), 5));
	printf("%zd\n", search(a2, nelem(a2), 3));
	printf("%zd\n", search(a3, nelem(a3), 4));
	printf("%zd\n", search(a4, nelem(a4), 20));

	return 0;
}
