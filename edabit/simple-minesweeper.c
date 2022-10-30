/*

Given a 2D array of mines, replace the question mark with the number of mines that immediately surround it.
This includes the diagonals, meaning it is possible for it to be surrounded by 8 mines maximum.

The key is as follows:

    An empty space: "-"
    A mine: "#"
    Number showing number of mines surrounding it: "?"

Examples

minesweeper([
  ["-", "#", "-"],
  ["-", "?", "-"],
  ["-", "-", "-"]
]) ➞ [
  ["-", "#", "-"],
  ["-", "1", "-"],
  ["-", "-", "-"]
]

minesweeper([
  ["-", "#", "-"],
  ["#", "-", "?"],
  ["#", "#", "-"]
]) ➞ [
  ["-", "#", "-"],
  ["#", "-", "2"],
  ["#", "#", "-"]
]

minesweeper([
  ["-", "#", "#"],
  ["?", "#", ""],
  ["#", "?", "-"]
]) ➞ [
  ["-", "#", "#"],
  ["3", "#", ""],
  ["#", "2", "-"]
]

minesweeper([
  ["-", "-", "#"],
  ["?", "-", "-"],
  ["-", "-", "-"]
]) ➞ [
  ["-", "-", "#"],
  ["0", "-", "-"],
  ["-", "-", "-"]
]

Notes

    You will only be given 3x3 grids.
    The question mark is not limited to the centre (there may be multiple question marks).

*/

#include <assert.h>
#include <string.h>

int
count(char b[3][3], int x, int y)
{
	if (x < 0 || y < 0 || x >= 3 || y >= 3)
		return 0;
	return b[y][x] == '#';
}

void
minesweeper(char a[3][3], char b[3][3])
{
	int x, y, dx, dy, c;

	for (y = 0; y < 3; y++) {
		for (x = 0; x < 3; x++) {
			b[y][x] = a[y][x];
			if (b[y][x] != '?')
				continue;

			c = 0;
			for (dy = -1; dy <= 1; dy++)
				for (dx = -1; dx <= 1; dx++)
					c += count(a, x + dx, y + dy);
			b[y][x] = c + '0';
		}
	}
}

void
test(char a[3][3], char b[3][3])
{
	char c[3][3];

	minesweeper(a, c);
	assert(!memcmp(b, c, sizeof(c)));
}

int
main(void)
{
	char a1[3][3] = {
	    {'-', '#', '-'},
	    {'-', '?', '-'},
	    {'-', '-', '-'},
	};
	char b1[3][3] = {
	    {'-', '#', '-'},
	    {'-', '1', '-'},
	    {'-', '-', '-'},
	};

	char a2[3][3] = {
	    {'-', '#', '-'},
	    {'#', '-', '?'},
	    {'#', '#', '-'},
	};
	char b2[3][3] = {
	    {'-', '#', '-'},
	    {'#', '-', '2'},
	    {'#', '#', '-'},
	};

	char a3[3][3] = {
	    {'-', '#', '#'},
	    {'?', '#', '-'},
	    {'#', '?', '-'},
	};
	char b3[3][3] = {
	    {'-', '#', '#'},
	    {'3', '#', '-'},
	    {'#', '2', '-'},
	};

	char a4[3][3] = {
	    {'-', '-', '#'},
	    {'?', '-', '-'},
	    {'-', '-', '-'},
	};
	char b4[3][3] = {
	    {'-', '-', '#'},
	    {'0', '-', '-'},
	    {'-', '-', '-'},
	};

	char a5[3][3] = {
	    {'?', '?', '?'},
	    {'?', '#', '?'},
	    {'?', '?', '?'},
	};
	char b5[3][3] = {
	    {'1', '1', '1'},
	    {'1', '#', '1'},
	    {'1', '1', '1'},
	};

	char a6[3][3] = {
	    {'?', '?', '?'},
	    {'?', '?', '?'},
	    {'?', '?', '?'},
	};
	char b6[3][3] = {
	    {'0', '0', '0'},
	    {'0', '0', '0'},
	    {'0', '0', '0'},
	};

	char a7[3][3] = {
	    {'#', '#', '#'},
	    {'#', '-', '#'},
	    {'#', '#', '#'},
	};
	char b7[3][3] = {
	    {'#', '#', '#'},
	    {'#', '-', '#'},
	    {'#', '#', '#'},
	};

	test(a1, b1);
	test(a2, b2);
	test(a3, b3);
	test(a4, b4);
	test(a5, b5);
	test(a6, b6);
	test(a7, b7);

	return 0;
}
