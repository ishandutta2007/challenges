/*

You're given a 2D array / matrix of a crop field. Each crop needs a water source. Each water source hydrates the 8 tiles aound it.
With "w" representing a water source, and "c" representing a crop, is every crop hydrated?
Examples

cropHydrated([
  [ "w", "c" ],
  [ "w", "c" ],
  [ "c", "c" ]
]) ➞ true

cropHydrated([
  [ "c", "c", "c" ]
]) ➞ false
// There isn"t even a water source.

cropHydrated([
  [ "c", "c", "c", "c" ],
  [ "w", "c", "c", "c" ],
  [ "c", "c", "c", "c" ],
  [ "c", "w", "c", "c" ]
]) ➞ false

Notes

"w" on its own should return true, and "c" on its own should return false.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>

int
iswater(ssize_t r, ssize_t c, char m[r][c], ssize_t x, ssize_t y)
{
	if (x < 0 || y < 0 || y >= r || x >= c)
		return 0;
	return m[y][x] == 'w';
}

int
crophydrated(ssize_t r, ssize_t c, char m[r][c])
{
	ssize_t x, y;
	int f;

	for (y = 0; y < r; y++) {
		for (x = 0; x < c; x++) {
			if (m[y][x] != 'c')
				continue;

			f = iswater(r, c, m, x - 1, y - 1);
			f |= iswater(r, c, m, x, y - 1);
			f |= iswater(r, c, m, x + 1, y - 1);
			f |= iswater(r, c, m, x - 1, y);
			f |= iswater(r, c, m, x + 1, y);
			f |= iswater(r, c, m, x - 1, y + 1);
			f |= iswater(r, c, m, x, y + 1);
			f |= iswater(r, c, m, x + 1, y + 1);
			if (!f)
				return 0;
		}
	}
	return 1;
}

int
main(void)
{
	char c1[3][2] = {
		{ 'w', 'c' },
		{ 'w', 'c' },
		{ 'c', 'c' },
	};
	char c2[1][3] = {
		{ 'c', 'c', 'c' },
	};
	char c3[4][4] = {
		{ 'c', 'c', 'c', 'c' },
		{ 'w', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'c' },
		{ 'c', 'w', 'c', 'c' },
	};
	char c4[5][2] = {
		{ 'w', 'w' },
		{ 'w', 'c' },
		{ 'c', 'c' },
		{ 'c', 'w' },
		{ 'c', 'w' },
	};
	char c5[4][5] = {
		{ 'c', 'w', 'w', 'w', 'c' },
		{ 'w', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'c' },
		{ 'w', 'c', 'c', 'w', 'c' },
	};
	char c6[1][2] = {
		{ 'c', 'w' },
	};
	char c7[2][5] = {
		{ 'w', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'w', 'c' },
	};
	char c8[7][3] = {
		{ 'c', 'c', 'c' },
		{ 'w', 'w', 'c' },
		{ 'c', 'c', 'c' },
		{ 'w', 'w', 'c' },
		{ 'c', 'c', 'c' },
		{ 'c', 'c', 'c' },
		{ 'c', 'w', 'c' },
	};
	char c9[2][3] = {
		{ 'c', 'c', 'c' },
		{ 'w', 'w', 'c' },
	};
	char c10[1][7] = {
		{ 'c', 'w', 'w', 'c', 'c', 'w', 'c' },
	};
	char c11[5][6] = {
		{ 'c', 'w', 'c', 'c', 'w', 'w' },
		{ 'c', 'c', 'w', 'c', 'c', 'c' },
		{ 'w', 'c', 'c', 'c', 'c', 'w' },
		{ 'c', 'w', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'w', 'w' },
	};
	char c12[6][1] = {
		{ 'c' },
		{ 'w' },
		{ 'c' },
		{ 'c' },
		{ 'w' },
		{ 'c' },
	};
	char c13[3][7] = {
		{ 'c', 'c', 'w', 'w', 'c', 'c', 'c' },
		{ 'c', 'w', 'c', 'w', 'w', 'c', 'w' },
		{ 'w', 'w', 'c', 'w', 'c', 'c', 'c' },
	};
	char c14[1][8] = {
		{ 'c', 'c', 'w', 'c', 'c', 'w', 'c', 'w' },
	};
	char c15[9][7] = {
		{ 'c', 'c', 'c', 'c', 'c', 'w', 'c' },
		{ 'c', 'w', 'c', 'c', 'w', 'c', 'w' },
		{ 'c', 'c', 'c', 'w', 'c', 'w', 'c' },
		{ 'w', 'w', 'c', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'w', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'w', 'c', 'c' },
		{ 'w', 'c', 'c', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'c', 'c', 'c' },
		{ 'w', 'c', 'c', 'c', 'c', 'c', 'w' },
	};
	char c16[9][4] = {
		{ 'c', 'w', 'c', 'c' },
		{ 'w', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'c' },
		{ 'w', 'c', 'c', 'c' },
		{ 'w', 'w', 'c', 'c' },
		{ 'c', 'w', 'c', 'c' },
		{ 'c', 'c', 'w', 'c' },
		{ 'c', 'c', 'w', 'w' },
		{ 'c', 'c', 'c', 'w' },
	};
	char c17[8][6] = {
		{ 'c', 'c', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'c', 'c' },
		{ 'w', 'c', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'c', 'w' },
		{ 'c', 'c', 'c', 'c', 'w', 'c' },
		{ 'c', 'w', 'w', 'c', 'c', 'c' },
	};
	char c18[8][7] = {
		{ 'c', 'c', 'c', 'c', 'c', 'w', 'c' },
		{ 'w', 'c', 'c', 'c', 'c', 'c', 'w' },
		{ 'c', 'c', 'c', 'c', 'c', 'c', 'c' },
		{ 'c', 'w', 'w', 'c', 'c', 'w', 'w' },
		{ 'c', 'c', 'w', 'c', 'w', 'c', 'c' },
		{ 'w', 'c', 'c', 'c', 'w', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'w', 'c', 'c' },
		{ 'w', 'c', 'c', 'c', 'c', 'c', 'c' },
	};
	char c19[8][9] = {
		{ 'c', 'w', 'c', 'c', 'w', 'c', 'c', 'c', 'w' },
		{ 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c' },
		{ 'w', 'c', 'c', 'c', 'w', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'c', 'w', 'w', 'w', 'c' },
		{ 'w', 'c', 'c', 'w', 'w', 'c', 'c', 'c', 'w' },
		{ 'c', 'c', 'c', 'c', 'w', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c' },
	};
	char c20[6][5] = {
		{ 'c', 'c', 'w', 'c', 'w' },
		{ 'c', 'c', 'c', 'c', 'c' },
		{ 'w', 'c', 'w', 'c', 'c' },
		{ 'c', 'w', 'w', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'w' },
		{ 'c', 'c', 'c', 'w', 'c' },
	};
	char c21[5][8] = {
		{ 'c', 'w', 'c', 'c', 'c', 'w', 'w', 'c' },
		{ 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c' },
		{ 'w', 'c', 'c', 'c', 'c', 'c', 'w', 'c' },
	};
	char c22[7][5] = {
		{ 'w', 'w', 'c', 'c', 'w' },
		{ 'c', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'w', 'c', 'c' },
		{ 'w', 'c', 'c', 'w', 'w' },
		{ 'c', 'c', 'w', 'c', 'c' },
		{ 'c', 'c', 'w', 'c', 'c' },
		{ 'c', 'c', 'c', 'w', 'c' },
	};
	char c23[8][6] = {
		{ 'c', 'c', 'w', 'c', 'c', 'w' },
		{ 'c', 'w', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'w', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'w', 'c' },
		{ 'c', 'c', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'c', 'c' },
		{ 'c', 'c', 'c', 'c', 'c', 'c' },
	};

	assert(crophydrated(3, 2, c1) == 1);
	assert(crophydrated(1, 3, c2) == 0);
	assert(crophydrated(4, 4, c3) == 0);
	assert(crophydrated(5, 2, c4) == 1);
	assert(crophydrated(4, 5, c5) == 1);
	assert(crophydrated(1, 2, c6) == 1);
	assert(crophydrated(2, 5, c7) == 1);
	assert(crophydrated(7, 3, c8) == 1);
	assert(crophydrated(2, 3, c9) == 1);
	assert(crophydrated(1, 7, c10) == 1);
	assert(crophydrated(5, 6, c11) == 1);
	assert(crophydrated(6, 1, c12) == 1);
	assert(crophydrated(3, 7, c13) == 1);
	assert(crophydrated(1, 8, c14) == 0);
	assert(crophydrated(9, 7, c15) == 0);
	assert(crophydrated(9, 4, c16) == 0);
	assert(crophydrated(8, 6, c17) == 0);
	assert(crophydrated(8, 7, c18) == 0);
	assert(crophydrated(8, 9, c19) == 0);
	assert(crophydrated(6, 5, c20) == 0);
	assert(crophydrated(5, 8, c21) == 0);
	assert(crophydrated(7, 5, c22) == 0);
	assert(crophydrated(8, 6, c23) == 0);

	return 0;
}
