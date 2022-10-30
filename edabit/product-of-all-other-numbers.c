/*

You have an array of integers, and for each index you want to find the product of every integer except the integer at that index.

Create a function that takes an array of integers and returns an array of the products.

Notes

You can't use division, otherwise you might end up dividing by 0 and the universe would end.

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int *
products(int *a, size_t n)
{
	int *p, m;
	size_t i, j, z;

	if (n == 0)
		return NULL;

	p = calloc(n, sizeof(*p));
	if (!p)
		return NULL;

	z = 0;
	m = 1;
	for (i = j = 0; i < n; i++) {
		if (a[i])
			m *= a[i];
		else {
			j = i;
			z++;
		}
	}

	if (z == 1)
		p[j] = m;

	if (z >= 1)
		return p;

	for (i = 0; i < n; i++)
		p[i] = m / a[i];

	return p;
}

void
print(int *a, size_t n)
{
	size_t i;

	if (!a)
		return;

	printf("[");
	for (i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i + 1 < n)
			printf(", ");
	}
	printf("]\n");
}

void
test(int *a, size_t n)
{
	int *p;

	p = products(a, n);
	print(p, n);
	free(p);
}

int
main(void)
{
	int a1[] = {1, 2, 6, 5, 9};
	int a2[] = {1, 7, 3, 4};
	int a3[] = {1, 2, 3, 0, 5};
	int a4[] = {0, 0, 2, 3, 4, 6, 7, 8, 100, 0};

	test(a1, nelem(a1));
	test(a2, nelem(a2));
	test(a3, nelem(a3));
	test(a4, nelem(a4));

	return 0;
}
