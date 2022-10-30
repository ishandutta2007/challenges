/*

Create an ordered 2D array (matrix). A matrix is ordered if its (0, 0) element is 1, its (0, 1) element is 2, and so on. Your function needs to create an a × b matrix. a is the first argument and b is the second.
Examples

orderedMatrix(5, 5) ➞ {
  {1 ,2 ,3 ,4 ,5},
  {6 ,7 ,8 ,9 ,10},
  {11, 12, 13, 14, 15},
  {16, 17, 18, 19, 20},
  {21, 22, 23, 24, 25}
}

orderedMatrix(1, 1) ➞ {{1}}

orderedMatrix(1, 5) ➞ {{1, 2, 3, 4, 5}}

Notes

    a is the height of the matrix (y coordinate), and b is the width (x coordinate).
    a and b will always be positive, and the matrix will always be square shaped (in each row are the same amount of columns).
    a and b are integers.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
matord(size_t r, size_t c, int m[r][c])
{
	size_t i, j;
	int v;

	v = 1;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			m[i][j] = v++;
	}
}

void
test(size_t r, size_t c, int m[r][c])
{
	int p[r][c];

	matord(r, c, p);
	assert(memcmp(m, p, r * c * sizeof(m[0][0])) == 0);
}

int
main(void)
{
	int m1[1][2] = {
		{ 1, 2 },
	};
	int m2[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },
	};
	int m3[5][5] = {
		{ 1, 2, 3, 4, 5 },
		{ 6, 7, 8, 9, 10 },
		{ 11, 12, 13, 14, 15 },
		{ 16, 17, 18, 19, 20 },
		{ 21, 22, 23, 24, 25 },
	};
	int m4[3][4] = {
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
	};
	int m5[1][1] = {
		{ 1 },
	};
	int m6[1][5] = {
		{ 1, 2, 3, 4, 5 },
	};

	test(1, 2, m1);
	test(3, 3, m2);
	test(5, 5, m3);
	test(3, 4, m4);
	test(1, 1, m5);
	test(1, 5, m6);

	return 0;
}
