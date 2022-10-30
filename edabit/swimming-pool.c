/*

Suppose a swimming pool blueprint can be represented as a 2D array, where 1s represent the pool and 0s represent the rest of the backyard.

[[0, 0, 0, 0, 0, 0, 0, 0],
[0, 1, 1, 1, 1, 1, 0, 0],
[0, 1, 1, 1, 1, 1, 0, 0],
[0, 1, 1, 0, 0, 0, 0, 0],
[0, 0, 0, 0, 0, 0, 0, 0]]
// Legitimate

Suppose a pool is considered legitimate if it does not touch any of the four borders in this 2D array.

[[1, 1, 0, 0, 0, 0, 0, 0],
[1, 1, 1, 1, 1, 1, 0, 0],
[0, 1, 1, 1, 1, 1, 0, 0],
[0, 0, 0, 0, 0, 0, 0, 0]]
// Illegitimate! 
// The 1s are touching both the left "fence" and the upper "fence".

Create a function that returns true if the pool plan is legitimate, and false otherwise.
Examples

isLegitimate([
  [0, 0, 0, 0, 0, 0, 0, 0],
  [0, 0, 1, 1, 1, 0, 0, 0],
  [0, 1, 1, 1, 1, 1, 0, 0],
  [0, 0, 0, 0, 0, 0, 0, 0]
]) ➞ true

isLegitimate([
  [0, 0, 0, 0, 0, 0, 0, 0],
  [0, 0, 1, 1, 1, 0, 0, 0],
  [0, 1, 1, 1, 1, 1, 0, 0],
  [0, 0, 1, 1, 1, 0, 0, 0]
]) ➞ false

isLegitimate([
  [0, 0, 0, 0, 0],
  [0, 1, 1, 1, 0],
  [0, 1, 1, 1, 0],
  [0, 0, 0, 0, 0]
]) ➞ true

*/

#include <assert.h>
#include <stdio.h>

int
legitpool(size_t r, size_t c, int m[r][c])
{
	size_t i;

	for (i = 0; i < c; i++) {
		if (m[0][i] || m[r - 1][i])
			return 0;
	}

	for (i = 0; i < r; i++) {
		if (m[i][0] || m[i][c - 1])
			return 0;
	}

	return 1;
}

int
main(void)
{
	int m1[4][8] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 1, 1, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
	};
	int m2[4][8] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 1, 1, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 0, 1, 1, 1, 0, 0, 0 },
	};
	int m3[4][5] = {
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0 },
	};
	int m4[4][5] = {
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0 },
	};
	int m5[5][8] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
	};
	int m6[6][8] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 1, 1, 0, 0, 1, 0, 0 },
		{ 0, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
	};
	int m7[6][8] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 0, 0, 0, 1, 0 },
		{ 0, 1, 0, 0, 0, 1, 1, 0 },
		{ 0, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
	};
	int m8[6][8] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 0, 0, 0, 1, 0 },
		{ 0, 1, 0, 0, 0, 1, 1, 0 },
		{ 0, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1 },
	};
	int m9[6][6] = {
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 1 },
		{ 0, 1, 1, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0 },
	};
	int m10[6][3] = {
		{ 0, 0, 0 },
		{ 0, 1, 0 },
		{ 0, 1, 0 },
		{ 0, 1, 0 },
		{ 0, 1, 0 },
		{ 0, 0, 0 },
	};
	int m11[6][3] = {
		{ 0, 0, 0 },
		{ 0, 1, 0 },
		{ 0, 1, 0 },
		{ 0, 1, 1 },
		{ 0, 1, 0 },
		{ 0, 0, 0 },
	};
	int m12[6][3] = {
		{ 0, 0, 0 },
		{ 0, 1, 0 },
		{ 0, 1, 0 },
		{ 1, 1, 1 },
		{ 0, 1, 0 },
		{ 0, 0, 0 },
	};

	assert(legitpool(4, 8, m1) == 1);
	assert(legitpool(4, 8, m2) == 0);
	assert(legitpool(4, 5, m3) == 1);
	assert(legitpool(4, 5, m4) == 0);
	assert(legitpool(5, 8, m5) == 1);
	assert(legitpool(6, 8, m6) == 1);
	assert(legitpool(6, 8, m7) == 1);
	assert(legitpool(6, 8, m8) == 0);
	assert(legitpool(6, 6, m9) == 0);
	assert(legitpool(6, 3, m10) == 1);
	assert(legitpool(6, 3, m11) == 0);
	assert(legitpool(6, 3, m12) == 0);

	return 0;
}
