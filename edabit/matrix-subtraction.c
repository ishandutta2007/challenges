/*

Two matrices must have an equal number of rows and columns to be subtracted.
In which case, the subtracted of two matrices A and B will be a matrix which has the same number of rows and columns as A and B.

The result of the subtraction of A and B, denoted A - B is computed by subtracting corresponding elements of A and B.

Create a function that takes 2 x 2D array (matrix A, matrixB) as an argument and returns a 2D array (matrix C). C = A-B.

Examples

sub([
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
], [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]) ➞ [
  [0, 0, 0],
  [0, 0, 0],
  [0, 0, 0]
]

Notes

Treat strings of numbers as integers.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

void
sub(size_t r, size_t c, double a[r][c], double b[r][c], double m[r][c])
{
	size_t i, j;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			m[i][j] = a[i][j] - b[i][j];
	}
}

void
test(size_t r, size_t c, double a[r][c], double b[r][c], double m[r][c])
{
	size_t i, j;
	double p[r][c];

	sub(r, c, a, b, p);
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			assert(fabs(p[i][j] - m[i][j]) < 1e-8);
	}
}

int
main(void)
{
	double a1[3][3] = {
	    {1, 2, 3},
	    {4, 5, 6},
	    {7, 8, 9},
	};
	double b1[3][3] = {
	    {1, 2, 3},
	    {4, 5, 6},
	    {7, 8, 9},
	};
	double m1[3][3] = {
	    {0, 0, 0},
	    {0, 0, 0},
	    {0, 0, 0},
	};

	double a2[3][3] = {
	    {1, 2, 3},
	    {4, 5, 6},
	    {7, 8, 9},
	};
	double b2[3][3] = {
	    {1, 2, 3},
	    {4, 5, 6},
	    {7, 8, 10},
	};
	double m2[3][3] = {
	    {0, 0, 0},
	    {0, 0, 0},
	    {0, 0, -1},
	};

	double a3[2][2] = {
	    {1, 2},
	    {4, 5},
	};
	double b3[2][2] = {
	    {1, 2},
	    {4, 5},
	};
	double m3[2][2] = {
	    {0, 0},
	    {0, 0},
	};

	double a4[2][2] = {
	    {1, 2},
	    {4, -5},
	};
	double b4[2][2] = {
	    {2, 2},
	    {4, -5},
	};
	double m4[2][2] = {
	    {-1, 0},
	    {0, 0},
	};

	double a5[1][1] = {
	    {21},
	};
	double b5[1][1] = {
	    {63},
	};
	double m5[1][1] = {
	    {-42},
	};

	double a6[3][3] = {
	    {0, 0, 0},
	    {0, 0, 0},
	    {0, 0, 0},
	};
	double b6[3][3] = {
	    {0, 0, 0},
	    {0, 0, 0},
	    {0, 0, 0},
	};
	double m6[3][3] = {
	    {0, 0, 0},
	    {0, 0, 0},
	    {0, 0, 0},
	};

	double a7[3][3] = {
	    {0, 0, 0},
	    {0, 0, 0},
	    {0, 0, 0},
	};
	double b7[3][3] = {
	    {0, 0, 0},
	    {0, 0, 0},
	    {0, 0, 0.678},
	};
	double m7[3][3] = {
	    {0, 0, 0},
	    {0, 0, 0},
	    {0, 0, -0.678},
	};

	double a8[3][3] = {
	    {2, 0, 0},
	    {0, 0, 0},
	    {0, 0, 0},
	};
	double b8[3][3] = {
	    {3, 0, 0},
	    {0, 0, 0},
	    {0, 0, 0.678},
	};
	double m8[3][3] = {
	    {-1, 0, 0},
	    {0, 0, 0},
	    {0, 0, -0.678},
	};

	test(3, 3, a1, b1, m1);
	test(3, 3, a2, b2, m2);
	test(2, 2, a3, b3, m3);
	test(2, 2, a4, b4, m4);
	test(1, 1, a5, b5, m5);
	test(3, 3, a6, b6, m6);
	test(3, 3, a7, b7, m7);
	test(3, 3, a8, b8, m8);

	return 0;
}
