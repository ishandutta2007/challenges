/*

A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
0 <= grid[i][j] <= 15
	
*/

#include <stdio.h>

int
ismagic(size_t r, size_t c, int g[r][c], size_t i, size_t j)
{
	int a, b;
	size_t m, n;

	if (g[i + 1][j + 1] != 5)
		return 0;
	if (g[i][j] + g[i + 2][j + 2] != 10)
		return 0;
	if (g[i][j + 2] + g[i + 2][j] != 10)
		return 0;

	for (m = 0; m < 3; m++) {
		a = 0;
		b = 0;
		for (n = 0; n < 3; n++) {
			if (g[i + m][j + n] > 9 || g[i + n][j + m] > 9)
				return 0;
			if (g[i + n][j + m] == 0 || g[i + m][j + n] == 0)
				return 0;
			a += g[i + m][j + n];
			b += g[i + n][j + m];
		}
		if (a != 15 || b != 15)
			return 0;
	}

	return 1;
}

int
submagic(size_t r, size_t c, int g[r][c])
{
	size_t i, j;
	int n;

	if (r < 3 || c < 3)
		return 0;

	n = 0;
	for (i = 0; i < r - 2; i++) {
		for (j = 0; j < c - 2; j++) {
			if (ismagic(r, c, g, i, j))
				n++;
		}
	}
	return n;
}

int
main(void)
{
	int m1[3][4] = {
	    {4, 3, 8, 4},
	    {9, 5, 1, 9},
	    {2, 7, 6, 2},
	};

	printf("%d\n", submagic(3, 4, m1));
	return 0;
}
