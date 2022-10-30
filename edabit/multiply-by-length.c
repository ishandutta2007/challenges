/*

Create a function to multiply all values in an array by the amount of values in that array.

Notes

    All values are numbers.
    All arrays will have at least one element.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
lmul(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		a[i] *= n;
}

void
test(int *a, size_t n)
{
	size_t i;

	lmul(a, n);
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int
main(void)
{
	int a[] = {2, 3, 1, 0};
	test(a, nelem(a));

	return 0;
}
