// Create a function to concatenate two integer arrays.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int *
concat(int *a, size_t na, int *b, size_t nb)
{
	int *p;

	p = calloc(na + nb, sizeof(int));
	if (!p)
		return NULL;

	memmove(p, a, na * sizeof(int));
	memmove(p + na, b, nb * sizeof(int));
	return p;
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
test(int *a, size_t na, int *b, size_t nb)
{
	int *p;
	p = concat(a, na, b, nb);
	if (!p)
		return;
	print(p, na + nb);
	free(p);
}

int
main(void)
{
	int x1[] = {1, 3, 5};
	int y1[] = {2, 6, 8};
	test(x1, nelem(x1), y1, nelem(y1));

	int x2[] = {7, 8};
	int y2[] = {10, 9, 1, 1, 2};
	test(x2, nelem(x2), y2, nelem(y2));

	int x3[] = {4, 5, 1};
	int y3[] = {3, 3, 3, 3, 3};
	test(x3, nelem(x3), y3, nelem(y3));

	return 0;
}
