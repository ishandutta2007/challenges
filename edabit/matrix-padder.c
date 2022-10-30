/*

Create a function that takes a matrix of size (m, n) and returns a matrix of size (m+2, n+2) with a pad of 0s around the perimeter.
Examples

padMatrix([[]]) ➞ [[0, 0], [0, 0], [0, 0]]

padMatrix([[9]]) ➞ [
  [0, 0, 0],
  [0, 9, 0],
  [0, 0, 0]
]

padMatrix([["hi", True]]) ➞ [
  [0, 0, 0, 0],
  [0, "hi", True, 0],
  [0, 0, 0, 0]
]

padMatrix([
  [1, 2, 5],
  [8, 6, 7],
  [3, 4, 9]
]) ➞ [
  [0, 0, 0, 0, 0],
  [0, 1, 2, 5, 0],
  [0, 8, 6, 7, 0],
  [0, 3, 4, 9, 0],
  [0, 0, 0, 0, 0]
]

Notes

    All inputs will be arrays of arrays.
    Refer to the first example to handle an empty input.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void
padmatrix(size_t r, size_t c, int a[r][c], int b[r + 2][c + 2])
{
	size_t i, j;

	memset(b, 0, sizeof(b[0][0]) * (r + 2) * (c + 2));
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			b[i + 1][j + 1] = a[i][j];
	}
}

void
test(size_t r, size_t c, int a[r][c], int b[r + 2][c + 2])
{
	int m[r + 2][c + 2];

	padmatrix(r, c, a, m);
	assert(memcmp(b, m, sizeof(m)) == 0);
}

int
main(void)
{
	int b1[2][2] = {
	    {0, 0},
	    {0, 0},
	};

	int a2[1][1] = {
	    {9},
	};
	int b2[3][3] = {
	    {0, 0, 0},
	    {0, 9, 0},
	    {0, 0, 0},
	};

	int a3[1][2] = {
	    {'h', true},
	};
	int b3[3][4] = {
	    {0, 0, 0, 0},
	    {0, 'h', true, 0},
	    {0, 0, 0, 0},
	};

	int a4[3][3] = {
	    {1, 2, 5},
	    {8, 6, 7},
	    {3, 4, 9},
	};
	int b4[5][5] = {
	    {0, 0, 0, 0, 0},
	    {0, 1, 2, 5, 0},
	    {0, 8, 6, 7, 0},
	    {0, 3, 4, 9, 0},
	    {0, 0, 0, 0, 0},
	};

	test(0, 0, NULL, b1);
	test(1, 1, a2, b2);
	test(1, 2, a3, b3);
	test(3, 3, a4, b4);

	return 0;
}
