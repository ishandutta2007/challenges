/*

This challenge concerns square matrices (same number of rows and columns) as the below example illustrates:

[
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]

The entries in the diagonal line from the top left to the bottom right form the main diagonal of the matrix. In this case, 1,5,9 form the main diagonal.

Write a function that returns the matrix obtained by replacing the entries above the main diagonal with 0s.

For example, for the matrix above you should return:

[
  [1, 0, 0],
  [4, 5, 0],
  [7, 8, 9]
]

Examples

lowerTriang([
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]) ➞ [
  [1, 0, 0],
  [4, 5, 0],
  [7, 8, 9]
]

lowerTriang([
  [5, 7],
  [7, 9]
]) ➞ [
  [5, 0],
  [7, 9]
]

lowerTriang([
  [1, 8, 8, 1],
  [2, 7, 7, 2],
  [3, 6, 6, 3],
  [4, 5, 5, 4]
]) ➞ [
  [1, 0, 0, 0],
  [2, 7, 0, 0],
  [3, 6, 6, 0],
  [4, 5, 5, 4]
]

Notes

    As in the examples, the size of the matrices will vary (but they will always be square).
    In Linear Algebra, matrices with 0s above the diagonal are called lower triangular matrices.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
dump(size_t n, int m[n][n])
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
	printf("\n");
}

void
lowertriangle(size_t n, int m[n][n])
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++)
			m[i][j] = 0;
	}
}

void
test(size_t n, int m[n][n], int r[n][n])
{
	lowertriangle(n, m);
	dump(n, m);
	assert(!memcmp(m, r, sizeof(*r) * n));
}

int
main(void)
{
	int m1[3][3] = {
	    {1, 2, 3},
	    {4, 5, 6},
	    {7, 8, 9},
	};
	int r1[3][3] = {
	    {1, 0, 0},
	    {4, 5, 0},
	    {7, 8, 9},
	};

	int m2[2][2] = {
	    {5, 7},
	    {7, 9},
	};
	int r2[2][2] = {
	    {5, 0},
	    {7, 9},
	};

	int m3[4][4] = {
	    {1, 8, 8, 1},
	    {2, 7, 7, 2},
	    {3, 6, 6, 3},
	    {4, 5, 5, 4},
	};
	int r3[4][4] = {
	    {1, 0, 0, 0},
	    {2, 7, 0, 0},
	    {3, 6, 6, 0},
	    {4, 5, 5, 4},
	};

	int m4[2][2] = {
	    {1, 0},
	    {7, 3},
	};
	int r4[2][2] = {
	    {1, 0},
	    {7, 3},
	};

	int m5[5][5] = {
	    {0, 1, 2, 3, 4},
	    {1, 2, 3, 4, 5},
	    {2, 3, 4, 5, 6},
	    {3, 4, 5, 6, 7},
	    {4, 5, 6, 7, 8},
	};
	int r5[5][5] = {
	    {0, 0, 0, 0, 0},
	    {1, 2, 0, 0, 0},
	    {2, 3, 4, 0, 0},
	    {3, 4, 5, 6, 0},
	    {4, 5, 6, 7, 8},
	};

	test(3, m1, r1);
	test(2, m2, r2);
	test(4, m3, r3);
	test(2, m4, r4);
	test(5, m5, r5);

	return 0;
}
