/*

Harry is a postman. He's got a post office with a size of n*m(a matrix / 2D array).
Each slot at the 2D array represents the number of letters in that spot.
Harry can only go right and down. He starts at (0, 0), and ends at (n-1, m-1).
n represents the height, and m the length. Return the maximum amount of letters he can pick up.
He can only pick up letters if he is on that spot.

Examples

harry(2, 2, [[5, 2], [5, 2]]) ➞ 12
// (5+5+2)

harry(3, 5, [[1, 2, 3, 4, 5], [6, 7, 8, 9, 10], [11, 12, 13, 14, 15]]) ➞ 72
// (1+6+11+12+13+14+15)

harry(0, 0, [[]]) ➞ -1

Notes

    Like you saw in example 3, if the matrix is empty, return -1.
    If the amount of letters is the same down and right, go right.
    You can't go down if you're on the bottom row, or right if you're on the most right column.

*/

#include <assert.h>
#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

long
harry(size_t r, size_t c, unsigned m[r][c])
{
	unsigned p[r][c];
	size_t i, j;
	long t, x, y;

	t = -1;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			x = (j > 0) ? p[i][j - 1] : 0;
			y = (i > 0) ? p[i - 1][j] : 0;
			t = p[i][j] = m[i][j] + max(x, y);
		}
	}
	return t;
}

int
main(void)
{
	unsigned m1[2][2] = {
		{ 5, 2 },
		{ 5, 2 },
	};

	unsigned m2[3][5] = {
		{ 1, 2, 3, 4, 5 },
		{ 6, 7, 8, 9, 10 },
		{ 11, 12, 13, 14, 15 },
	};

	unsigned m3[1][1] = {
		{ 5 },
	};

	unsigned m4[3][3] = {
		{ 9, 9, 9 },
		{ 0, 0, 9 },
		{ 0, 0, 9 },
	};

	unsigned m5[4][2] = {
		{ 5, 2 },
		{ 5, 2 },
		{ 5, 2 },
		{ 5, 2 },
	};

	unsigned m6[5][5] = {
		{ 5, 6, 2, 5, 1 },
		{ 7, 2, 4, 1, 2 },
		{ 0, 7, 5, 2, 14 },
		{ 9, 5, 12, 5, 9 },
		{ 19, 5, 2, 6, 2 },
	};

	assert(harry(2, 2, m1) == 12);
	assert(harry(3, 5, m2) == 72);
	assert(harry(0, 0, m2) == -1);
	assert(harry(1, 1, m3) == 5);
	assert(harry(3, 3, m4) == 45);
	assert(harry(4, 2, m5) == 22);
	assert(harry(5, 5, m6) == 55);

	return 0;
}
