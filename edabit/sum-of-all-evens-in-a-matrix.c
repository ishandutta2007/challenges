/*

Create a function that returns the sum of all even elements in a 2D matrix.

Notes

Submatrices will be of equal length.
Return 0 if the 2D matrix only consists of empty submatrices.

*/

#include <stdio.h>

int
mse(size_t r, size_t c, int m[r][c])
{
	size_t i, j;
	int s;

	s = 0;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			if (!(m[i][j] & 1))
				s += m[i][j];
		}
	}
	return s;
}

int
main(void)
{
	int m1[3][3] = {
	    {1, 0, 2},
	    {5, 5, 7},
	    {9, 4, 3},
	};

	int m2[2][2] = {
	    {1, 1},
	    {1, 1},
	};

	int m3[2][2] = {
	    {42, 9},
	    {16, 8},
	};

	int m4[4][4] = {
	    {1, 5, 1, 3},
	    {4, 1, 2, 0},
	    {6, 9, 7, 4},
	    {5, 1, 2, 6},
	};

	int m5[4][3] = {
	    {1, 0, 1},
	    {33, 1, 2},
	    {15, 9, 1},
	    {5, 1, 979},
	};

	int m6[2][4] = {
	    {2, 19, 5, 43},
	    {67, 2, 0, 12},
	};

	int m7[3][4] = {
	    {1, 3, 7, 9},
	    {11, 13, 15, 17},
	    {19, 21, 23, 25},
	};

	printf("%d\n", mse(3, 3, m1));
	printf("%d\n", mse(2, 2, m2));
	printf("%d\n", mse(2, 2, m3));
	printf("%d\n", mse(0, 3, m3));
	printf("%d\n", mse(4, 4, m4));
	printf("%d\n", mse(4, 3, m5));
	printf("%d\n", mse(2, 4, m6));
	printf("%d\n", mse(3, 4, m7));

	return 0;
}
