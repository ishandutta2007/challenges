/*

Given a grid of numbers, return a grid of the Spotlight Sum of each number.
The spotlight sum can be defined as the total of all numbers immediately surrounding the number on the grid, including the number in the total.

Examples

spotlightMap([
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]) ➞ [
  [12, 21, 16],
  [27, 45, 33],
  [24, 39, 28]
]


spotlightMap([
  [2, 6, 1, 3, 7],
  [8, 5, 9, 4, 0]
]) ➞ [
  [21, 31, 28, 24, 14],
  [21, 31, 28, 24, 14]
]


spotlightMap([[3]]) ➞ [[3]]

Notes

    Note that all numbers have a spotlight sum, including numbers on the edges.
    All inputs will be valid grid (all rows will have the same length).

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>

void
spotlight(ssize_t r, ssize_t c, int m[r][c], int p[r][c])
{
	ssize_t x, y, dx, dy;
	ssize_t i, j;
	int v;

	for (y = 0; y < r; y++) {
		for (x = 0; x < c; x++) {
			v = 0;
			for (dy = -1; dy <= 1; dy++) {
				for (dx = -1; dx <= 1; dx++) {
					i = y + dy;
					j = x + dx;
					if (i < 0 || j < 0 || i >= r || j >= c)
						continue;
					v += m[i][j];
				}
			}
			p[y][x] = v;
		}
	}
}

void
dump(ssize_t r, ssize_t c, int p[r][c])
{
	ssize_t x, y;

	for (y = 0; y < r; y++) {
		for (x = 0; x < c; x++)
			printf("%d ", p[y][x]);
		printf("\n");
	}
	printf("\n");
}

void
test(ssize_t r, ssize_t c, int m[r][c], int p[r][c])
{
	int b[r][c];

	spotlight(r, c, m, b);
	dump(r, c, b);
	assert(!memcmp(p, b, sizeof(b)));
}

int
main(void)
{
	int m1[3][3] = {
	    {1, 2, 3},
	    {4, 5, 6},
	    {7, 8, 9},
	};
	int p1[3][3] = {
	    {12, 21, 16},
	    {27, 45, 33},
	    {24, 39, 28},
	};

	int m2[2][5] = {
	    {2, 6, 1, 3, 7},
	    {8, 5, 9, 4, 0},
	};
	int p2[2][5] = {
	    {21, 31, 28, 24, 14},
	    {21, 31, 28, 24, 14},
	};

	int m3[5][2] = {
	    {7, 8},
	    {3, 1},
	    {4, 2},
	    {0, 5},
	    {9, 6},
	};
	int p3[5][2] = {
	    {19, 19},
	    {25, 25},
	    {15, 15},
	    {26, 26},
	    {20, 20},
	};

	int m4[5][5] = {
	    {5, 5, 5, 5, 5},
	    {5, 5, 5, 5, 5},
	    {5, 5, 5, 5, 5},
	    {5, 5, 5, 5, 5},
	    {5, 5, 5, 5, 5},
	};
	int p4[5][5] = {
	    {20, 30, 30, 30, 20},
	    {30, 45, 45, 45, 30},
	    {30, 45, 45, 45, 30},
	    {30, 45, 45, 45, 30},
	    {20, 30, 30, 30, 20},
	};
	int m5[1][1] = {
	    {3},
	};

	test(3, 3, m1, p1);
	test(2, 5, m2, p2);
	test(5, 2, m3, p3);
	test(5, 5, m4, p4);
	test(1, 1, m5, m5);
	test(0, 0, NULL, NULL);

	return 0;
}
