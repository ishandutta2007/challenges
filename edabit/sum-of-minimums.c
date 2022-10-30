/*

Create a function that takes a 2D array arr returns the sum of the minimum value in each row.

Examples

sumMinimums([
  [1, 2, 3, 4, 5],
  [5, 6, 7, 8, 9],
  [20, 21, 34, 56, 100]
] ➞ 26

// minimum value of the first row is 1
// minimum value of the second row is 5
// minimum value of the third row is 20

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
minsum(size_t r, size_t c, int m[r][c])
{
	size_t i, j;
	int v, s;

	if (r == 0 || c == 0)
		return 0;

	s = 0;
	for (i = 0; i < r; i++) {
		v = m[i][0];
		for (j = 1; j < c; j++)
			v = min(v, m[i][j]);
		s += v;
	}
	return s;
}

int
main(void)
{
	int m1[3][5] = {
	    {1, 2, 3, 4, 5},
	    {5, 6, 7, 8, 9},
	    {20, 21, 34, 56, 100},
	};
	int m2[3][5] = {
	    {7, 9, 8, 6, 2},
	    {6, 3, 5, 4, 3},
	    {5, 8, 7, 4, 5},
	};
	int m3[4][4] = {
	    {11, 12, 14, 54},
	    {67, 89, 90, 56},
	    {7, 9, 4, 3},
	    {9, 8, 6, 7},
	};

	assert(minsum(3, 5, m1) == 26);
	assert(minsum(3, 5, m2) == 9);
	assert(minsum(4, 4, m3) == 76);

	return 0;
}
