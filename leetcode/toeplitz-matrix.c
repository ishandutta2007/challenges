/*

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 
*/

#include <stdio.h>

int
same(size_t r, size_t c, size_t i, size_t j, int m[r][c])
{
	for (;;) {
		if (i + 1 >= r || j + 1 >= c)
			break;
		if (m[i][j] != m[i + 1][j + 1])
			return 0;
		i++;
		j++;
	}
	return 1;
}

int
istoeplitz(size_t r, size_t c, int m[r][c])
{
	size_t i;

	if (r == 0 || c == 0)
		return 0;

	for (i = 0; i < r; i++) {
		if (!same(r, c, 0, i, m))
			return 0;
		if (!same(r, c, i, 0, m))
			return 0;
	}

	return 1;
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
}

int
main(void)
{
	int m1[3][4] = {
	    {1, 2, 3, 4},
	    {5, 1, 2, 3},
	    {9, 5, 1, 2},
	};
	printf("%d\n", istoeplitz(3, 4, m1));

	int m2[2][2] = {
	    {1, 2},
	    {2, 2},
	};
	printf("%d\n", istoeplitz(2, 2, m2));

	int m3[1][1] = {{1}};
	printf("%d\n", istoeplitz(1, 1, m3));

	int m4[1][2] = {
	    {1, 2},
	};
	printf("%d\n", istoeplitz(2, 1, m4));

	int m5[3][1] = {
	    {1},
	    {2},
	    {3},
	};
	printf("%d\n", istoeplitz(3, 1, m5));

	int m6[3][3] = {
	    {1, 2, 3},
	    {0, 1, 2},
	    {0, 0, 0},
	};
	printf("%d\n", istoeplitz(3, 3, m6));
	m6[2][2] = 1;
	printf("%d\n", istoeplitz(3, 3, m6));
	m6[1][0] = 2;
	printf("%d\n", istoeplitz(3, 3, m6));
	m6[2][1] = 2;
	printf("%d\n", istoeplitz(3, 3, m6));

	return 0;
}
