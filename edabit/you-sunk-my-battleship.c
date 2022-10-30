/*

Remember the game Battleship? Ships are floating in a matrix. You have to fire torpedos at their suspected coordinates, to try and hit them.

Create a function that takes an array of arrays (matrix) and a coordinate as a string.
If the coordinate contains only water " . ", return "splash" and if the coordinate contains a ship " * ", return "BOOM".

Examples

[
  [".", ".", ".", "*", "*"],
  [".", "*", ".", ".", "."],
  [".", "*", ".", ".", "."],
  [".", "*", ".", ".", "."],
  [".", ".", "*", "*", "."],
]

fire(matrix, "A1") ➞ "splash"

fire(matrix, "A4") ➞ "BOOM"

fire(matrix, "D2") ➞ "BOOM"

Notes

    The provided matrix is always a square.
    The provided matrix will not be larger than 5 * 5 ( A1 * E5).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
fire(size_t n, char m[n][n], const char *s)
{
	int r, c;

	r = s[0];
	c = s[1];
	if (r < 'A' || r > 'E' || c < '1' || c > '5')
		return NULL;

	r -= 'A';
	c -= '1';
	switch (m[r][c]) {
	case '.':
		return "splash";
	case '*':
		return "BOOM";
	}
	return "beyond the environment";
}

int
main(void)
{
	char m1[5][5] = {
	    {'.', '.', '.', '*', '*'},
	    {'.', '*', '.', '.', '.'},
	    {'.', '*', '.', '.', '.'},
	    {'.', '*', '.', '.', '.'},
	    {'.', '*', '*', '*', '.'},
	};
	char m2[5][5] = {
	    {'.', '.', '.', '*', '*'},
	    {'.', '*', '.', '.', '.'},
	    {'.', '*', '.', '.', '.'},
	    {'.', '*', '.', '.', ','},
	    {'.', '.', '*', '*', '.'},
	};
	char m3[2][2] = {
	    {'.', '.'},
	    {'*', '*'},
	};
	char m4[2][2] = {
	    {'.', '.'},
	    {'*', '*'},
	};
	char m5[3][3] = {
	    {'*', '.', '.'},
	    {'.', '.', '.'},
	    {'.', '*', '*'},
	};
	char m6[3][3] = {
	    {'*', '.', '.'},
	    {'.', '.', '.'},
	    {'.', '*', '*'},
	};
	char m7[4][4] = {
	    {'.', '.', '.', '.'},
	    {'.', '*', '*', '.'},
	    {'.', '.', '.', '.'},
	    {'.', '.', '.', '.'},
	};
	char m8[4][4] = {
	    {'.', '.', '.', '.'},
	    {'.', '*', '*', '.'},
	    {'.', '.', '.', '.'},
	    {'.', '.', '.', '.'},
	};
	char m9[1][1] = {
	    {'*'},
	};

	assert(!strcmp(fire(5, m1, "A1"), "splash"));
	assert(!strcmp(fire(5, m2, "C2"), "BOOM"));
	assert(!strcmp(fire(2, m3, "B1"), "BOOM"));
	assert(!strcmp(fire(2, m4, "A2"), "splash"));
	assert(!strcmp(fire(3, m5, "C3"), "BOOM"));
	assert(!strcmp(fire(3, m6, "A3"), "splash"));
	assert(!strcmp(fire(4, m7, "B3"), "BOOM"));
	assert(!strcmp(fire(4, m8, "B4"), "splash"));
	assert(!strcmp(fire(1, m9, "A1"), "BOOM"));

	return 0;
}
