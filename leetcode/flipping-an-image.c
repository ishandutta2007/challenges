/*

Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

*/

#include <stdio.h>

void
rev(int *m, size_t n)
{
	size_t i;
	int t;
	for (i = 0; i < n / 2; i++) {
		t = m[i];
		m[i] = m[n - i - 1];
		m[n - i - 1] = t;
	}
}

void
inv(int *m, size_t n)
{
	size_t i;
	for (i = 0; i < n; i++)
		m[i] = !m[i];
}

void
flipinv(size_t r, size_t c, int m[r][c])
{
	size_t i;
	for (i = 0; i < r; i++) {
		rev(m[i], c);
		inv(m[i], c);
	}
}

void
print(size_t r, size_t c, int m[r][c])
{
	size_t i, j;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
	printf("\n");
}

void
test(size_t r, size_t c, int m[r][c])
{
	print(r, c, m);
	flipinv(r, c, m);
	print(r, c, m);
}

int
main(void)
{
	int a[3][3] = {
	    {1, 1, 0},
	    {1, 0, 1},
	    {0, 0, 0},
	};
	test(3, 3, a);

	int b[4][4] = {
	    {1, 1, 0, 0},
	    {1, 0, 0, 1},
	    {0, 1, 1, 1},
	    {1, 0, 1, 0},
	};
	test(4, 4, b);

	return 0;
}
