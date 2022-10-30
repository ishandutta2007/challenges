/*

Create a function to count the number of 1s in a 2D array.
Examples

count_ones([
  [1, 0],
  [0, 0]
]) ➞ 1

count_ones([
  [1, 1, 1],
  [0, 0, 1],
  [1, 1, 1]
]) ➞ 7

count_ones([
  [1, 2, 3],
  [0, 2, 1],
  [5, 7, 33]
]) ➞ 2

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>

size_t
countones(size_t r, size_t c, char m[r][c])
{
	size_t i, j, n;

	n = 0;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			n += m[i][j] == 1;
	}
	return n;
}

int
main(void)
{
	char m1[2][2] = {
		{ 1, 0 },
		{ 0, 0 },
	};

	char m2[3][3] = {
		{ 1, 1, 1 },
		{ 0, 0, 1 },
		{ 1, 1, 1 },
	};

	char m3[3][3] = {
		{ 1, 2, 3 },
		{ 0, 2, 1 },
		{ 5, 7, 33 },
	};

	char m4[3][3] = {
		{ 1, 0, 1 },
		{ 0, 0, 0 },
		{ 0, 0, 1 },
	};

	char m5[3][3] = {
		{ 1, 1, 1 },
		{ 0, 0, 1 },
		{ 1, 1, 1 },
	};

	char m6[3][3] = {
		{ 1, 2, 3 },
		{ 0, 2, 1 },
		{ 5, 7, 33 },
	};

	char m7[3][3] = {
		{ 5, 2, 3 },
		{ 0, 2, 5 },
		{ 5, 7, 33 },
	};

	char m8[2][2] = {
		{ 1, 1 },
		{ 0, 1 },
	};

	char m9[3][2] = {
		{ 5, 2 },
		{ 0, 2 },
		{ 5, 1 },
	};

	assert(countones(2, 2, m1) == 1);
	assert(countones(3, 3, m2) == 7);
	assert(countones(3, 3, m3) == 2);
	assert(countones(3, 3, m4) == 3);
	assert(countones(3, 3, m5) == 7);
	assert(countones(3, 3, m6) == 2);
	assert(countones(3, 3, m7) == 0);
	assert(countones(2, 2, m8) == 3);
	assert(countones(3, 2, m9) == 1);

	return 0;
}
