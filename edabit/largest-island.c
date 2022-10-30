/*

An island is a region of contiguous ones. A contiguous one is a 1 that is touched by at least one other 1, either horizontally, vertically or diagonally.
Given a piece of the map, represented by a 2-D array, create a function that returns the area of the largest island.

Notes

    Maps can be any m x n dimension.
    Maps will always have at least 1 element. m >= 1 and n >= 1.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <inttypes.h>

ssize_t
max(ssize_t a, ssize_t b)
{
	return (a > b) ? a : b;
}

ssize_t
count(ssize_t r, ssize_t c, char m[r][c], ssize_t i, ssize_t j)
{
	ssize_t l;

	if (i < 0 || j < 0 || i >= r || j >= c)
		return 0;

	if (m[i][j] != 1)
		return 0;
	m[i][j] = 2;

	l = 1;
	l += count(r, c, m, i - 1, j - 1);
	l += count(r, c, m, i - 1, j);
	l += count(r, c, m, i - 1, j + 1);
	l += count(r, c, m, i, j - 1);
	l += count(r, c, m, i, j + 1);
	l += count(r, c, m, i + 1, j - 1);
	l += count(r, c, m, i + 1, j);
	l += count(r, c, m, i + 1, j + 1);
	return l;
}

ssize_t
largestisland(ssize_t r, ssize_t c, char m[r][c])
{
	ssize_t i, j, l;

	l = 0;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			l = max(l, count(r, c, m, i, j));
	}

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			m[i][j] = !!m[i][j];
	}
	return l;
}

int
main(void)
{
	char m1[3][3] = {
	    {1, 0, 0},
	    {0, 0, 0},
	    {0, 0, 1},
	};
	char m2[3][3] = {
	    {1, 1, 0},
	    {0, 1, 1},
	    {0, 0, 1},
	};
	char m3[3][3] = {
	    {1, 0, 0},
	    {1, 0, 0},
	    {1, 0, 1},
	};
	char m4[3][3] = {
	    {0, 0, 0},
	    {0, 1, 1},
	    {0, 1, 1},
	};
	char m5[3][3] = {
	    {1, 0, 0},
	    {0, 0, 1},
	    {0, 0, 1},
	};
	char m6[3][3] = {
	    {1, 0, 0},
	    {0, 1, 1},
	    {0, 0, 1},
	};
	char m7[3][2] = {
	    {1, 0},
	    {0, 1},
	    {0, 0},
	};
	char m8[1][1] = {
	    {1},
	};
	char m9[3][1] = {
	    {1},
	    {0},
	    {1},
	};
	char m10[3][3] = {
	    {1, 1, 1},
	    {0, 1, 1},
	    {0, 0, 1},
	};

	assert(largestisland(3, 3, m1) == 1);
	assert(largestisland(3, 3, m2) == 5);
	assert(largestisland(3, 3, m3) == 3);
	assert(largestisland(3, 3, m4) == 4);
	assert(largestisland(3, 3, m5) == 2);
	assert(largestisland(3, 3, m6) == 4);
	assert(largestisland(3, 2, m7) == 2);
	assert(largestisland(1, 1, m8) == 1);
	assert(largestisland(3, 1, m9) == 1);
	assert(largestisland(3, 3, m10) == 6);

	return 0;
}
