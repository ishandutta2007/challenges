/*

Given an integer array, find three numbers whose product is maximum and output the maximum product.

Note:
    The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
    Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
cmp(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int
maxproduct3(int *a, size_t n)
{
	if (n < 3)
		return 0;
	qsort(a, n, sizeof(*a), cmp);
	return a[n - 1] * max(a[0] * a[1], a[n - 2] * a[n - 3]);
}

int
main(void)
{
	int a[] = {1, 2, 3};
	printf("%d\n", maxproduct3(a, nelem(a)));

	int b[] = {1, 2, 3, 4};
	printf("%d\n", maxproduct3(b, nelem(b)));

	int c[] = {-1000, -981, -93, 20, 10, 1, 2, 3, 4, 5, 9};
	printf("%d\n", maxproduct3(c, nelem(c)));

	int d[] = {-102, 1, 0, -23, 1, 3, 4};
	printf("%d\n", maxproduct3(d, nelem(d)));

	int e[] = {-12, -10, -9, 0, 2, 3, 4, 5, 8};
	printf("%d\n", maxproduct3(e, nelem(e)));

	int f[] = {-2, -3, -32, -19};
	printf("%d\n", maxproduct3(f, nelem(f)));

	return 0;
}
