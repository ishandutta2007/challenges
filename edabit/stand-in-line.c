/*

Write a function that takes an array and a number as arguments.
Add the number to the end of the array, then remove the first element of the array.
The function should then return the updated array.

Notes

For an empty array input, return: "No array has been selected"

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
nextinline(int *a, size_t n, int v)
{
	if (n == 0)
		return n;
	memmove(a, a + 1, (n - 1) * sizeof(*a));
	a[n - 1] = v;
	return n;
}

void
test(int *a, size_t n, int v)
{
	size_t i;

	if (n == 0) {
		printf("No array has been selected\n");
		return;
	}

	nextinline(a, n, v);
	printf("[");
	for (i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i + 1 < n)
			printf(", ");
	}
	printf("]\n");
}

int
main(void)
{
	int a1[] = {5, 6, 7, 8, 9};
	int a2[] = {7, 6, 3, 23, 17};
	int a3[] = {1, 10, 20, 42};
	int a4[] = {0};

	test(a1, nelem(a1), 1);
	test(a2, nelem(a2), 10);
	test(a3, nelem(a3), 6);
	test(a3, 0, 6);
	test(a4, nelem(a4), 1);

	return 0;
}
