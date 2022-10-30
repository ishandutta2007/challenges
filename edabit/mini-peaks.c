/*

Write a function that returns all the elements in an array that are strictly greater than their adjacent left and right neighbors.

Notes

    Do not count boundary numbers, since they only have one left/right neighbor.
    If no such numbers exist, return an empty array.

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int *
minipeaks(int *a, size_t n, size_t *l)
{
	size_t i, j;
	int *p;

	*l = 0;

	if (n == 0)
		return NULL;

	p = calloc(n, sizeof(*a));
	if (!p)
		return NULL;

	for (i = 1, j = 0; i < n - 1; i++) {
		if (a[i - 1] < a[i] && a[i] > a[i + 1])
			p[j++] = a[i];
	}
	*l = j;

	return p;
}

void
print(int *a, size_t n)
{
	size_t i;

	printf("[");
	for (i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i + 1 < n)
			printf(" ");
	}
	printf("]\n");
}

void
test(int *a, size_t n)
{
	int *p;
	size_t l;

	p = minipeaks(a, n, &l);
	print(p, l);
	free(p);
}

int
main(void)
{
	int a1[] = {4, 5, 2, 1, 4, 9, 7, 2};
	int a2[] = {1, 2, 1, 1, 3, 2, 5, 4, 4};
	int a3[] = {1, 2, 3, 4, 5, 6};
	int a4[] = {6, 4, 3};
	int a5[] = {1, 1, 1, 1, 2, 1, 1, 1};
	int a6[] = {1, 9, 1, 8, 2, 7, 6};
	int a7[] = {7, 8, 7, 8, 7, 8, 5, 1, 2, 0};

	test(a1, nelem(a1));
	test(a2, nelem(a2));
	test(a3, nelem(a3));
	test(a4, nelem(a4));
	test(a5, nelem(a5));
	test(a6, nelem(a6));
	test(a7, nelem(a7));

	return 0;
}
