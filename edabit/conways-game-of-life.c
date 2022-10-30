/*

Conway's Game of Life

The goal of this challenge is to implement the logic used in Conway's Game of Life. Wikipedia will give a better understanding of what it is and how it works (check the resources tab above).
Rules

    For a space that's "populated":
        Each cell with 0 or 1 neighbours dies, as if by solitude.
        Each cell with 2 or 3 neighbours survives.
        Each cell with 4 or more neighbours dies, as if by overpopulation.
    For a space that's "empty" or "unpopulated":
        Each cell with 3 neighbours becomes populated.

Parameters

board: a 2-dimensional array of values 0 to 1.

    0 means the cell is empty.
    1 means the cell is populated.

Return Value

A string containing the board's state after the game logic has been applied once.

On character: █
Off character: ░

Notes

The string should be divided by newlines \n to signal the end of each row.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

void
life(ssize_t r, ssize_t c, char in[r][c], char out[r][c])
{
	ssize_t x, y, dx, dy, i, j, l;

	for (y = 0; y < r; y++) {
		for (x = 0; x < c; x++) {
			l = 0;
			for (dy = -1; dy <= 1; dy++) {
				for (dx = -1; dx <= 1; dx++) {
					i = y + dy;
					j = x + dx;
					if (i < 0 || j < 0 || i >= r || j >= c)
						continue;
					if (dx == 0 && dy == 0)
						continue;
					l += in[i][j];
				}
			}

			out[y][x] = 0;
			if (in[y][x] && (l == 2 || l == 3))
				out[y][x] = 1;
			else if (!in[y][x] && l == 3)
				out[y][x] = 1;
		}
	}
}

void
stringify(ssize_t r, ssize_t c, char m[r][c], char *s)
{
	ssize_t x, y, l;

	l = 0;
	for (y = 0; y < r; y++) {
		for (x = 0; x < c; x++)
			l += sprintf(s + l, "%s", (m[y][x]) ? u8"█" : u8"░");

		if (y + 1 < r)
			l += sprintf(s + l, "\n");
	}
}

void
test(ssize_t r, ssize_t c, char in[r][c], const char *ex)
{
	char out[r][c], str[4 * r * c];

	life(r, c, in, out);
	stringify(r, c, out, str);
	assert(!strcmp(str, ex));
	printf("%s\n\n", str);
}

int
main(void)
{
	char ex1[3][3] = {
		{ 0, 0, 0 },
		{ 0, 1, 0 },
		{ 0, 0, 0 },
	};
	char ex2[3][3] = {
		{ 0, 1, 0 },
		{ 1, 1, 1 },
		{ 0, 1, 0 },
	};
	char ex3[3][3] = {
		{ 1, 0, 0 },
		{ 0, 1, 0 },
		{ 0, 0, 1 },
	};
	char ex4[3][3] = {
		{ 1, 0, 1 },
		{ 0, 0, 0 },
		{ 1, 0, 0 },
	};
	char glider[5][5] = {
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 1, 0 },
		{ 0, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0 },
	};
	char small_exploder[6][5] = {
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0 },
		{ 0, 1, 1, 1, 0 },
		{ 0, 1, 0, 1, 0 },
		{ 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0 },
	};
	char exploder[7][7] = {
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 1, 0, 1, 0 },
		{ 0, 1, 0, 0, 0, 1, 0 },
		{ 0, 1, 0, 0, 0, 1, 0 },
		{ 0, 1, 0, 0, 0, 1, 0 },
		{ 0, 1, 0, 1, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
	};
	char row_of_10[3][12] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};
	char lightweight_spaceship[6][7] = {
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 1, 1, 1, 0 },
		{ 0, 1, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 1, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
	};
	char tumbler[8][9] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 1, 0, 1, 1, 0, 0 },
		{ 0, 0, 1, 1, 0, 1, 1, 0, 0 },
		{ 0, 0, 0, 1, 0, 1, 0, 0, 0 },
		{ 0, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 0, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 0, 1, 1, 0, 0, 0, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};
	char checkerboard[7][9] = {
		{ 1, 0, 1, 0, 1, 0, 1, 0, 1 },
		{ 0, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 1, 0, 1 },
		{ 0, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 1, 0, 1 },
		{ 0, 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 1, 0, 1 },
	};
	char big_shape[10][15] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0 },
		{ 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0 },
		{ 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};

	test(3, 3, ex1, u8"░░░\n░░░\n░░░");
	test(3, 3, ex2, u8"███\n█░█\n███");
	test(3, 3, ex3, u8"░░░\n░█░\n░░░");
	test(3, 3, ex4, u8"░░░\n░█░\n░░░");
	test(5, 5, glider, u8"░░░░░\n░░░░░\n░█░█░\n░░██░\n░░█░░");
	test(6, 5, small_exploder, u8"░░░░░\n░███░\n░█░█░\n░█░█░\n░░█░░\n░░░░░");
	test(7, 7, exploder, u8"░░░░░░░\n░░█░█░░\n██░░░██\n███░███\n██░░░██\n░░█░█░░\n░░░░░░░");
	test(3, 12, row_of_10, u8"░░████████░░\n░░████████░░\n░░████████░░");
	test(6, 7, lightweight_spaceship, u8"░░░██░░\n░░████░\n░░██░██\n░░░░██░\n░░░░░░░\n░░░░░░░");
	test(8, 9, tumbler, u8"░░░░░░░░░\n░░██░██░░\n░░░░░░░░░\n░░░█░█░░░\n░░░█░█░░░\n██░█░█░██\n░██░░░██░\n░░░░░░░░░");
	test(7, 9, checkerboard, u8"░███████░\n█░░░░░░░█\n█░░░░░░░█\n█░░░░░░░█\n█░░░░░░░█\n█░░░░░░░█\n░███████░");
	test(10, 15, big_shape, u8"░░░░░░░░░█░░░░░\n░░██░░░░█░█░░░░\n░░██░░░░█░░░░░░\n░█░░█░░██░░█░░░\n░█░██░░░█░█░█░░\n░░█░░░░░░░░███░\n░░░██░░░░█░░██░\n░░░░██░░░░░░░░░\n░░░░░█░░█░░░░░░\n░░░░░░░░░░░░░░░");

	return 0;
}
