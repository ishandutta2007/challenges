/*

In probability theory, a probability matrix is a matrix such that:

    The matrix is a square matrix (same number of rows as columns).
    All entries are probabilities, i.e. numbers between 0 and 1.
    All rows add up to 1.

The following is an example of a probability matrix:

[
  [0.5, 0.5, 0.0],
  [0.2, 0.5, 0.3],
  [0.1, 0.2, 0.7]
]

Note that though all rows add up to 1, there is no restriction on the columns, which may or may not add up to 1.

Write a function that determines if a matrix is a probability matrix or not.
Examples

isProbMatrix([
  [0.5, 0.5, 0.0],
  [0.2, 0.5, 0.3],
  [0.1, 0.2, 0.7]
]) ➞ true

isProbMatrix([
  [0.5, 0.5, 0.0],
  [0.2, 0.5, 0.3]
]) ➞ false

// Not a square matrix.

isProbMatrix([
  [2, -1],
  [-1, 2]
]) ➞ false

// Entries not between 0 and 1.

isProbMatrix([
  [0, 1],
  [1, 0]
]) ➞ true

isProbMatrix([
  [0.5, 0.4],
  [0.5, 0.6]
]) ➞ false

// Rows do not add to 1.

Notes

Fun fact: for most probability matrices M (for example, if M has no zero entries), the matrix powers M^n converge (as n increases) to a matrix where all rows are identical.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

bool
isprobmatrix(size_t r, size_t c, double m[r][c])
{
	static const double eps = 1e-8;
	size_t i, j;
	double v;

	if (r != c)
		return false;

	for (i = 0; i < r; i++) {
		v = 0;
		for (j = 0; j < c; j++) {
			if (m[i][j] < 0 || m[i][j] > 1)
				return false;
			v += m[i][j];
		}
		if (fabs(1 - v) > eps)
			return false;
	}
	return true;
}

int
main(void)
{
	double m1[2][3] = {
	    {0.5, 0.5, 0.0},
	    {0.2, 0.5, 0.3},
	};
	double m2[2][2] = {
	    {2, -1},
	    {-1, 2},
	};
	double m3[2][2] = {
	    {0.5, 0.4},
	    {0.5, 0.6},
	};
	double m4[2][2] = {
	    {0, 1},
	    {1, 0},
	};
	double m5[2][2] = {
	    {2, 1},
	    {1, 2},
	};
	double m6[1][1] = {
	    {1},
	};
	double m7[3][3] = {
	    {0.5, 0.5, 0.0},
	    {0.2, 0.5, 0.3},
	    {0.1, 0.2, 0.7},
	};
	double m8[4][4] = {
	    {0, 0, 0, 1},
	    {0, 0, 0, 1},
	    {0, 0, 0, 1},
	    {0, 0, 0, 1},
	};
	double m9[4][4] = {
	    {1, 0, 0, 1},
	    {1, 0, 1, 1},
	    {1, 1, 0, 1},
	    {1, 0, 0, 1},
	};
	double m10[4][4] = {
	    {0.5, 0.0, 0.5, 0.0},
	    {0.1, 0.2, 0.3, 0.4},
	    {0.3, 0.2, 0.2, 0.3},
	    {0.0, 0.5, 0.0, 0.5},
	};
	double m11[3][3] = {
	    {0.5, 0.5, 0.0},
	    {0.2, 0.5, 0.3},
	    {0.1, 0.2, 0.7},
	};

	assert(isprobmatrix(2, 3, m1) == false);
	assert(isprobmatrix(2, 2, m2) == false);
	assert(isprobmatrix(2, 2, m3) == false);
	assert(isprobmatrix(2, 2, m4) == true);
	assert(isprobmatrix(2, 2, m5) == false);
	assert(isprobmatrix(1, 1, m6) == true);
	assert(isprobmatrix(3, 3, m7) == true);
	assert(isprobmatrix(4, 4, m8) == true);
	assert(isprobmatrix(4, 4, m9) == false);
	assert(isprobmatrix(4, 4, m10) == true);
	assert(isprobmatrix(3, 3, m11) == true);

	return 0;
}
