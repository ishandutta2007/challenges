/*

Consider a matrix where each cell contains either a 0 or a 1 and any cell containing a is called a filled cell.
Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally.
In the diagram below, the two colored regions show cells connected to the filled cells. Black on white are not connected.

000 0 01
010 0 00
000 000
Cells adjacent to filled cells:

If one or more filled cells are also connected, they form a region. Note that each cell in a region is connected to at least one other cell in the region but is not necessarily directly connected to all the other cells in the region.

*/

#define _GNU_SOURCE
#include <stdio.h>

size_t
max(size_t a, size_t b)
{
	return (a > b) ? a : b;
}

size_t
floodfill(ssize_t r, ssize_t c, size_t n, size_t m, int M[n][m])
{
	size_t s;

	if (r < 0 || c < 0 || (size_t)r >= n || (size_t)c >= m)
		return 0;
	if (!M[r][c])
		return 0;
	M[r][c] = 0;

	s = 1;
	s += floodfill(r - 1, c - 1, n, m, M);
	s += floodfill(r - 1, c, n, m, M);
	s += floodfill(r - 1, c + 1, n, m, M);
	s += floodfill(r, c - 1, n, m, M);
	s += floodfill(r, c + 1, n, m, M);
	s += floodfill(r + 1, c - 1, n, m, M);
	s += floodfill(r + 1, c, n, m, M);
	s += floodfill(r + 1, c + 1, n, m, M);
	return s;
}

size_t
maxregion(size_t n, size_t m, int M[n][m])
{
	size_t r, c, s;
	int N[n][m];

	for (r = 0; r < n; r++) {
		for (c = 0; c < m; c++)
			N[r][c] = M[r][c];
	}

	s = 0;
	for (r = 0; r < n; r++) {
		for (c = 0; c < m; c++)
			s = max(s, floodfill(r, c, n, m, N));
	}
	return s;
}

int
main(void)
{
	int m1[4][4] = {
	    {1, 1, 0, 0},
	    {0, 1, 1, 0},
	    {0, 0, 1, 0},
	    {1, 0, 0, 0},
	};
	int m2[5][4] = {
	    {0, 0, 1, 1},
	    {0, 0, 1, 0},
	    {0, 1, 1, 0},
	    {0, 1, 0, 0},
	    {1, 1, 0, 0},
	};
	int m3[5][5] = {
	    {1, 0, 1, 1, 0},
	    {1, 1, 0, 0, 1},
	    {0, 1, 1, 1, 0},
	    {0, 0, 0, 0, 1},
	    {1, 1, 1, 0, 0},
	};
	int m4[3][6] = {
	    {0, 0, 0, 0, 0, 1},
	    {0, 1, 0, 0, 0, 0},
	    {0, 0, 0, 0, 0, 0},
	};
	int m5[3][6] = {
	    {1, 1, 0, 0, 0, 1},
	    {0, 1, 1, 0, 0, 0},
	    {0, 0, 0, 1, 0, 0},
	};
	printf("%zu\n", maxregion(4, 4, m1));
	printf("%zu\n", maxregion(5, 4, m2));
	printf("%zu\n", maxregion(5, 5, m3));
	printf("%zu\n", maxregion(3, 6, m4));
	printf("%zu\n", maxregion(3, 6, m5));
	return 0;
}
