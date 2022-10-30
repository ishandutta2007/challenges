/*

Given a 3x3 matrix of a completed tic-tac-toe game, create a function that returns whether the game is a win for "X", "O", or a "Draw", where "X" and "O" represent themselves on the matrix, and "E" represents an empty spot.
Examples

ticTacToe([
  ["X", "O", "X"],
  ["O", "X",  "O"],
  ["O", "X",  "X"]
]) ➞ "X"

ticTacToe([
  ["O", "O", "O"],
  ["O", "X", "X"],
  ["E", "X", "X"]
]) ➞ "O"

ticTacToe([
  ["X", "X", "O"],
  ["O", "O", "X"],
  ["X", "X", "O"]
]) ➞ "Draw"

Notes

Make sure that if O wins, you return the letter "O" and not the integer 0 (zero) and if it's a draw, make sure you return the capitalised word "Draw". If you return "X" or "O", make sure they're capitalised too.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
tictactoe(char m[3][3])
{
	static const unsigned tab[] = {
		0x07,
		0x38,
		0x1c0,
		0x49,
		0x92,
		0x124,
		0x54,
		0x111,
	};

	unsigned f, i, j, o, x, s;
	int no, nx;

	nx = no = 0;
	x = o = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			s = 1 << (3 * i + j);
			if (m[i][j] == 'X') {
				x |= s;
				nx++;
			} else if (m[i][j] == 'O') {
				o |= s;
				no++;
			}
		}
	}

	if (abs(nx - no) > 1)
		return "Invalid";

	f = 0;
	for (i = 0; i < nelem(tab); i++) {
		if ((x & tab[i]) == tab[i])
			f |= 0x1;
		if ((o & tab[i]) == tab[i])
			f |= 0x2;
	}

	if (f == 0)
		return "Draw";
	if (f == 1)
		return "X";
	if (f == 2)
		return "O";
	return "Invalid";
}

int
main(void)
{
	char m1[3][3] = {
		{ 'X', 'O', 'X' },
		{ 'O', 'X', 'O' },
		{ 'O', 'X', 'X' },
	};

	char m2[3][3] = {
		{ 'O', 'O', 'O' },
		{ 'O', 'X', 'X' },
		{ 'E', 'X', 'X' },
	};

	char m3[3][3] = {
		{ 'X', 'X', 'O' },
		{ 'O', 'O', 'X' },
		{ 'X', 'X', 'O' },
	};

	char m4[3][3] = {
		{ 'X', 'O', 'O' },
		{ 'X', 'O', 'O' },
		{ 'X', 'X', 'X' },
	};

	char m5[3][3] = {
		{ 'X', 'X', 'O' },
		{ 'O', 'O', 'X' },
		{ 'X', 'X', 'O' },
	};

	char m6[3][3] = {
		{ 'X', 'O', 'X' },
		{ 'O', 'X', 'O' },
		{ 'E', 'E', 'X' },
	};

	char m7[3][3] = {
		{ 'X', 'O', 'E' },
		{ 'X', 'O', 'E' },
		{ 'E', 'O', 'X' },
	};

	char m8[3][3] = {
		{ 'X', 'X', 'X' },
		{ 'E', 'E', 'E' },
		{ 'O', 'E', 'E' },
	};

	assert(!strcmp(tictactoe(m1), "X"));
	assert(!strcmp(tictactoe(m2), "O"));
	assert(!strcmp(tictactoe(m3), "Draw"));
	assert(!strcmp(tictactoe(m4), "X"));
	assert(!strcmp(tictactoe(m5), "Draw"));
	assert(!strcmp(tictactoe(m6), "X"));
	assert(!strcmp(tictactoe(m7), "O"));
	assert(!strcmp(tictactoe(m8), "Invalid"));

	return 0;
}
