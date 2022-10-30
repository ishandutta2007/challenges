/*

Write a function that returns true if there exists a row that is identical to a column in a 2-D matrix.

To illustrate:

[
  [1, 2, 3, 4],
  [2, 4, 9, 8],
  [5, 9, 7, 7],
  [6, 8, 1, 0]
]

// 2nd row + 2nd column are identical: [2, 4, 9, 8]

Examples

hasIdentical([
  [4, 4, 4, 4],
  [2, 4, 9, 8],
  [5, 4, 7, 7],
  [6, 4, 1, 0]
]) ➞ true

hasIdentical([
  [4, 4, 9, 4],
  [2, 1, 9, 8],
  [5, 4, 7, 7],
  [6, 4, 1, 0]
]) ➞ false

hasIdentical([
  [4, 4]
  [2, 1]
]) ➞ false

hasIdentical([
  [4, 2]
  [2, 1]
]) ➞ true

Notes

Non-square matrices should be false.

*/

#include <assert.h>
#include <stdio.h>

int
hasidentical(size_t r, size_t c, int m[r][c])
{
	size_t i, j, k, n;

	if (r != c)
		return 0;

	n = r;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				if (m[k][i] != m[j][k])
					break;
			}
			if (k == n)
				return 1;
		}
	}

	return 0;
}

int
main(void)
{
	int m1[4][4] = {
		{ 1, 2, 3, 4 },
		{ 2, 4, 9, 8 },
		{ 5, 9, 7, 7 },
		{ 6, 8, 1, 0 },
	};
	int m2[4][4] = {
		{ 4, 4, 4, 4 },
		{ 2, 4, 9, 8 },
		{ 5, 4, 7, 7 },
		{ 6, 4, 1, 0 },
	};
	int m3[2][2] = {
		{ 4, 4 },
		{ 2, 1 },
	};
	int m4[2][2] = {
		{ 4, 2 },
		{ 2, 1 },
	};
	int m5[5][5] = {
		{ 4, 2, 4, 6, 1 },
		{ 2, 4, 9, 4, 5 },
		{ 5, 1, 7, 1, 9 },
		{ 6, 4, 1, 0, 33 },
		{ 5, 5, 5, 33, 5 },
	};
	int m6[4][4] = {
		{ 4, 4, 9, 4 },
		{ 2, 1, 9, 8 },
		{ 5, 4, 7, 7 },
		{ 6, 4, 1, 0 },
	};
	int m7[3][3] = {
		{ 4, 4, 3 },
		{ 2, 1, 9 },
		{ 3, 8, 1 },
	};
	int m8[2][3] = {
		{ 4, 4, 4 },
		{ 2, 1, 4 },
	};
	int m9[1][3] = {
		{ 4, 4, 4 },
	};

	assert(hasidentical(4, 4, m1) == 1);
	assert(hasidentical(4, 4, m2) == 1);
	assert(hasidentical(2, 2, m3) == 0);
	assert(hasidentical(2, 2, m4) == 1);
	assert(hasidentical(5, 5, m5) == 1);
	assert(hasidentical(4, 4, m6) == 0);
	assert(hasidentical(3, 3, m7) == 0);
	assert(hasidentical(2, 3, m8) == 0);
	assert(hasidentical(1, 3, m9) == 0);

	return 0;
}
