/*

Create a function that takes a 5x5 3D array and returns true if it has at least one Bingo, and false if it doesn't.

Examples

bingoCheck([
  [45, "x", 31, 74, 87],
  [64, "x", 47, 32, 90],
  [37, "x", 68, 83, 54],
  [67, "x", 98, 39, 44],
  [21, "x", 24, 30, 52]
]) ➞ true

bingoCheck([
  ["x", 43, 31, 74, 87],
  [64, "x", 47, 32, 90],
  [37, 65, "x", 83, 54],
  [67, 98, 39, "x", 44],
  [21, 59, 24, 30, "x"]
]) ➞ true

bingoCheck([
  ["x", "x", "x", "x", "x"],
  [64, 12, 47, 32, 90],
  [37, 16, 68, 83, 54],
  [67, 19, 98, 39, 44],
  [21, 75, 24, 30, 52]
]) ➞ true

bingoCheck([
  [45, "x", 31, 74, 87],
  [64, 78, 47, "x", 90],
  [37, "x", 68, 83, 54],
  [67, "x", 98, "x", 44],
  [21, "x", 24, 30, 52]
]) ➞ false

Notes

Only check for diagnols, horizontals and verticals.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
check(const char s[5][5], int r, int c, int dr, int dc)
{
	int i;

	for (i = 0; i < 5; i++) {
		if (r < 0 || r >= 5 || c < 0 || c >= 5 || s[r][c] != 'x')
			return false;

		r += dr;
		c += dc;
	}
	return true;
}

bool
bingo(const char s[5][5])
{
	int i;

	if (check(s, 0, 0, 1, 1))
		return true;
	if (check(s, 0, 4, 1, -1))
		return true;

	for (i = 0; i < 5; i++) {
		if (check(s, 0, i, 1, 0))
			return true;
		if (check(s, i, 0, 0, 1))
			return true;
	}
	return false;
}

int
main(void)
{
	const char s1[5][5] = {
	    {45, 'x', 31, 74, 87},
	    {64, 'x', 47, 32, 90},
	    {37, 'x', 68, 83, 54},
	    {67, 'x', 98, 39, 44},
	    {21, 'x', 24, 30, 52},
	};
	const char s2[5][5] = {
	    {'x', 43, 31, 74, 87},
	    {64, 'x', 47, 32, 90},
	    {37, 65, 'x', 83, 54},
	    {67, 98, 39, 'x', 44},
	    {21, 59, 24, 30, 'x'},
	};
	const char s3[5][5] = {
	    {37, 16, 84, 51, 33},
	    {64, 12, 47, 32, 90},
	    {'x', 'x', 'x', 'x', 'x'},
	    {67, 19, 98, 39, 44},
	    {21, 75, 24, 30, 52},
	};
	const char s4[5][5] = {
	    {45, 'x', 31, 74, 87},
	    {64, 78, 'x', 'x', 90},
	    {37, 'x', 68, 'x', 54},
	    {67, 'x', 98, 'x', 'x'},
	    {21, 'x', 24, 30, 52},
	};
	const char s5[5][5] = {
	    {45, 46, 31, 74, 'x'},
	    {64, 78, 80, 'x', 90},
	    {37, 81, 'x', 55, 54},
	    {67, 'x', 98, 34, 77},
	    {'x', 33, 24, 30, 52},
	};
	const char s6[5][5] = {
	    {'x', 0, 0, 0, 'x'},
	    {0, 'x', 0, 'x', 0},
	    {0, 0, 'x', 0, 0},
	    {0, 'x', 0, 'x', 0},
	    {0, 0, 0, 0, 0},
	};
	const char s7[5][5] = {
	    {'x', 'x', 'x', 'x', 0},
	    {'x', 'x', 'x', 'x', 0},
	    {'x', 'x', 'x', 'x', 0},
	    {'x', 'x', 'x', 'x', 0},
	    {0, 0, 0, 0, 0},
	};
	const char s8[5][5] = {
	    {'x', 'x', 'x', 'x', 'x'},
	    {'x', 'x', 'x', 'x', 'x'},
	    {'x', 'x', 'x', 'x', 'x'},
	    {'x', 'x', 'x', 'x', 'x'},
	    {'x', 'x', 'x', 'x', 'x'},
	};
	const char s9[5][5] = {
	    {1, 2, 3, 'x', 5},
	    {6, 7, 8, 'x', 10},
	    {11, 12, 13, 'x', 15},
	    {16, 'x', 'x', 'x', 'x'},
	    {21, 22, 'x', 'x', 25},
	};
	const char s10[5][5] = {
	    {'x', 'x', 'x', 'x', 1},
	    {0, 'x', 2, 3, 1},
	    {3, 5, 'x', 34, 1},
	    {5, 6, 'x', 5, 1},
	    {'x', 'x', 'x', 'x', 'x'},
	};

	assert(bingo(s1) == true);
	assert(bingo(s2) == true);
	assert(bingo(s3) == true);
	assert(bingo(s4) == false);
	assert(bingo(s5) == true);
	assert(bingo(s6) == false);
	assert(bingo(s7) == false);
	assert(bingo(s8) == true);
	assert(bingo(s9) == true);
	assert(bingo(s10) == true);

	return 0;
}
