/*

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swap(int *x, int *y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}

void
rot90cw(size_t n, int a[n][n])
{
	size_t x, y;

	if (n == 0)
		return;

	for (y = 0; y < n - 1; y++) {
		for (x = y; x < n; x++)
			swap(&a[x][y], &a[y][x]);
	}

	for (y = 0; y < n; y++) {
		for (x = 0; x < n / 2; x++)
			swap(&a[y][x], &a[y][n - x - 1]);
	}
}

void
print(size_t n, int a[n][n])
{
	size_t x, y;

	printf("[\n");
	for (y = 0; y < n; y++) {
		printf("  [");
		for (x = 0; x < n; x++) {
			printf("%d", a[y][x]);
			if (x + 1 < n)
				printf(",");
		}
		printf("]");
		if (y + 1 < n)
			printf(",");
		printf("\n");
	}
	printf("]\n\n");
}

void
test(size_t n, int a[n][n])
{
	print(n, a);
	rot90cw(n, a);
	print(n, a);
}

int
main(void)
{
	int m1[3][3] = {
	    {1, 2, 3},
	    {4, 5, 6},
	    {7, 8, 9},
	};
	test(nelem(m1), m1);

	int m2[4][4] = {
	    {5, 1, 9, 11},
	    {2, 4, 8, 10},
	    {13, 3, 6, 7},
	    {15, 14, 12, 16},
	};
	test(nelem(m2), m2);

	return 0;
}
