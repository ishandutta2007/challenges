/*

Create a function that returns true if the two-dimensional n x n input array has a checker-board pattern.
Examples

isCheckerboard([
  [1, 1],
  [0, 1]
]) ➞ false

isCheckerboard([
  [0, 1],
  [1, 0]
]) ➞ true

isCheckerboard([
  [1, 0, 1, 0, 1],
  [0, 1, 0, 1, 0],
  [1, 0, 1, 0, 1],
  [0, 1, 0, 1, 0],
  [1, 0, 1, 1, 1]
]) ➞ false

isCheckerboard([
  [1, 0, 1, 0, 1],
  [0, 1, 0, 1, 0],
  [1, 0, 1, 0, 1],
  [0, 1, 0, 1, 0],
  [1, 0, 1, 0, 1]
]) ➞ true

Notes

    An element in the array adheres to the checker-board pattern if the elements directly to the left, right, top and below are of a different type, and the elements on the diagonal direction are of the same type.
    The element in the upper-left corner can be either 0 or 1.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <inttypes.h>

int
match(ssize_t n, ssize_t r, ssize_t c, ssize_t i, ssize_t j, int b[n][n], int d)
{
	if (i < 0 || i >= n || j < 0 || j >= n)
		return d;

	return b[r][c] == b[i][j];
}

int
ischeckered(ssize_t n, int b[n][n])
{
	static const ssize_t diag[][2] = {
		{ -1, -1 },
		{ 1, -1 },
		{ -1, 1 },
		{ 1, 1 },
	};
	static const ssize_t card[][2] = {
		{ 0, -1 },
		{ 0, 1 },
		{ -1, 0 },
		{ 1, 0 },
	};

	ssize_t i, j, k;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < 4; k++) {
				if (match(n, i, j, i + diag[k][0], j + diag[k][1], b, 1) == 0)
					return 0;
				if (match(n, i, j, i + card[k][0], j + card[k][1], b, 0) == 1)
					return 0;
			}
		}
	}

	return 1;
}

int
main(void)
{
	int b1[5][5] = {
		{ 1, 0, 1, 0, 1 },
		{ 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1 },
		{ 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1 },
	};
	int b2[5][5] = {
		{ 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1 },
		{ 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1 },
		{ 0, 1, 0, 1, 0 },
	};
	int b3[5][5] = {
		{ 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1 },
		{ 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 1, 1 },
		{ 0, 1, 0, 1, 0 },
	};
	int b4[5][5] = {
		{ 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1 },
		{ 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1 },
		{ 1, 1, 0, 1, 0 },
	};
	int b5[5][5] = {
		{ 1, 0, 1, 0, 1 },
		{ 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1 },
		{ 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 1, 1 },
	};
	int b6[2][2] = {
		{ 0, 1 },
		{ 1, 0 },
	};
	int b7[2][2] = {
		{ 1, 1 },
		{ 1, 0 },
	};
	int b8[2][2] = {
		{ 1, 1 },
		{ 0, 1 },
	};
	int b9[2][2] = {
		{ 1, 0 },
		{ 0, 1 },
	};
	int b10[3][3] = {
		{ 1, 0, 1 },
		{ 0, 1, 0 },
		{ 1, 0, 1 },
	};

	assert(ischeckered(5, b1) == 1);
	assert(ischeckered(5, b2) == 1);
	assert(ischeckered(5, b3) == 0);
	assert(ischeckered(5, b4) == 0);
	assert(ischeckered(5, b5) == 0);
	assert(ischeckered(2, b6) == 1);
	assert(ischeckered(2, b7) == 0);
	assert(ischeckered(2, b8) == 0);
	assert(ischeckered(2, b9) == 1);
	assert(ischeckered(3, b10) == 1);

	return 0;
}
