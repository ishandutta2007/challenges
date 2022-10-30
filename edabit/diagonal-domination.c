/*

A square matrix (same number of rows as columns) is called row diagonally dominant if
"the absolute value of each entry in the main diagonal is strictly larger than the sum of the absolute values of the other entries in that row".

To illustrate ...

[
  [10, 3, 6],
  [2, -9, -6],
  [1, -1, 4]
]

The absolute values from top left to bottom right are:

    10 = First item of first row.
    9 = Second item of second row.
    4 = Third item of third row.

... making a row diagonal dominant total of 23.

In the first row ...

    The value of the row diagonal dominant is 10.
    The sum of the other absolute values are 3 and 6 make a total of 9.

... so far, the matrix is row diagonally dominant, since 10 > 9.

In the second row ...

    The value of the row diagonal dominant is 9.
    The sum of the other absolute values in the second row are 3 and 6 which make a total of 9.

... meaning the matrix is not row diagonally dominant since 9 <= 9.

[
  [10, 3, 6],
  [3, -9, -6],
  [1, -1,  4]
]

For a square to be row diagonally dominant, all of the rows in the square have to be like Row 1.

Write a function that determines if a given square matrix is row diagonally dominant.
Examples

diagDom([
  [2, -1],
  [-1, 2]
]) ➞ true

diagDom([
  [0, 1],
  [1, 0]
]) ➞ false

diagDom([
  [10, 3, 6],
  [2, -9, -6],
  [1, -1, 4]
]) ➞ true

diagDom([
  [10, 3, 6],
  [4, -9, -6],
  [1, -1, 4]
]) ➞ false

Notes

As in the examples, the size of the matrices will change, but they will always be square.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool
diagdom(size_t n, int m[n][n])
{
	size_t i, j;
	int x, y;

	for (i = 0; i < n; i++) {
		x = abs(m[i][i]);
		y = 0;
		for (j = 0; j < n; j++) {
			if (i != j)
				y += abs(m[i][j]);
		}
		if (x <= y)
			return false;
	}
	return true;
}

int
main(void)
{
	int m1[2][2] = {
	    {2, -1},
	    {-1, 2},
	};
	int m2[2][2] = {
	    {0, 1},
	    {1, 0},
	};
	int m3[3][3] = {
	    {10, 3, 6},
	    {2, -9, -6},
	    {1, -1, 4},
	};
	int m4[3][3] = {
	    {10, 3, 6},
	    {3, -9, -6},
	    {1, -1, 4},
	};
	int m5[4][4] = {
	    {1, 0, 1, 0},
	    {0, 2, 0, 2},
	    {3, 0, 3, 0},
	    {0, 4, 0, 4},
	};
	int m6[4][4] = {
	    {5, 0, -1, 0},
	    {0, -6, 0, 2},
	    {3, 0, 7, 0},
	    {0, 4, 0, -8},
	};
	int m7[4][4] = {
	    {5, 1, -1, -2},
	    {0, -6, -3, 2},
	    {3, -2, 7, -1},
	    {-1, 3, -2, -8},
	};
	int m8[4][4] = {
	    {5, 1, -1, -2},
	    {0, -6, -3, 2},
	    {3, -2, 7, -2},
	    {-1, 3, -2, -8},
	};
	int m9[3][3] = {
	    {10, 3, 6},
	    {4, -9, -6},
	    {1, -1, 4},
	};

	assert(diagdom(2, m1) == true);
	assert(diagdom(2, m2) == false);
	assert(diagdom(3, m3) == true);
	assert(diagdom(3, m4) == false);
	assert(diagdom(4, m5) == false);
	assert(diagdom(4, m6) == true);
	assert(diagdom(4, m7) == true);
	assert(diagdom(4, m8) == false);
	assert(diagdom(3, m9) == false);

	return 0;
}
