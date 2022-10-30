/*

Create a function that transposes a 2D matrix.
Examples

transposeMatrix([
  [1, 1, 1],
  [2, 2, 2],
  [3, 3, 3]
]) ➞ [
  [1, 2, 3],
  [1, 2, 3],
  [1, 2, 3]
]

transposeMatrix([
  [5, 5],
  [6, 7],
  [9, 1]
]) ➞ [
  [5, 6, 9],
  [5, 7, 1]
]

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
transpose(size_t r, size_t c, int M[r][c], int N[c][r])
{
	size_t i, j;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			N[j][i] = M[i][j];
	}
}

void
test(size_t r, size_t c, int M[r][c], int N[c][r])
{
	int P[r][c];

	transpose(r, c, M, P);
	assert(memcmp(P, N, r * c * sizeof(int)) == 0);
}

int
main(void)
{
	int m1[3][3] = {
		{ 1, 1, 1 },
		{ 2, 2, 2 },
		{ 3, 3, 3 },
	};
	int n1[3][3] = {
		{ 1, 2, 3 },
		{ 1, 2, 3 },
		{ 1, 2, 3 },
	};

	int m2[2][3] = {
		{ 1, 1, 1 },
		{ 2, 2, 2 },
	};
	int n2[3][2] = {
		{ 1, 2 },
		{ 1, 2 },
		{ 1, 2 }
	};

	int m3[3][4] = {
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
	};
	int n3[4][3] = {
		{ 1, 5, 9 },
		{ 2, 6, 10 },
		{ 3, 7, 11 },
		{ 4, 8, 12 },
	};

	int m4[3][2] = {
		{ 5, 5 },
		{ 6, 7 },
		{ 9, 1 },
	};
	int n4[2][3] = {
		{ 5, 6, 9 },
		{ 5, 7, 1 },
	};

	test(3, 3, m1, n1);
	test(2, 3, m2, n2);
	test(3, 4, m3, n3);
	test(3, 2, m4, n4);

	return 0;
}
