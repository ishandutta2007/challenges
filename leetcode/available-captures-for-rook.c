/*

On an 8 x 8 chessboard, there is one white rook.  There also may be empty squares, white bishops, and black pawns.
These are given as characters 'R', '.', 'B', and 'p' respectively.
Uppercase characters represent white pieces, and lowercase characters represent black pieces.

The rook moves as in the rules of Chess: it chooses one of four cardinal directions (north, east, west, and south),
then moves in that direction until it chooses to stop, reaches the edge of the board,
or captures an opposite colored pawn by moving to the same square it occupies.
Also, rooks cannot move into the same square as other friendly bishops.

Return the number of pawns the rook can capture in one move.

Note:

    board.length == board[i].length == 8
    board[i][j] is either 'R', '.', 'B', or 'p'
    There is exactly one cell with board[i][j] == 'R'

*/

#include <stdio.h>

int
findrook(char b[8][8], int *x, int *y)
{
	int i, j;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (b[i][j] == 'R') {
				*x = i;
				*y = j;
				return 1;
			}
		}
	}
	return 0;
}

int
captures(char b[8][8], int x, int y, int dx, int dy)
{
	int c;

	c = 0;
	for (;;) {
		x += dx;
		y += dy;
		if (x < 0 || x > 7 || y < 0 || y > 7)
			break;

		if (b[x][y] == 'p')
			c++;

		if (b[x][y] != '.')
			break;
	}
	return c;
}

int
rookcaptures(char b[8][8])
{
	int x, y, c;

	if (!findrook(b, &x, &y))
		return -1;

	c = captures(b, x, y, -1, 0);
	c += captures(b, x, y, 1, 0);
	c += captures(b, x, y, 0, -1);
	c += captures(b, x, y, 0, 1);
	return c;
}

int
main(void)
{
	char b1[8][8] = {
	    {'.', '.', '.', '.', '.', '.', '.', '.'},
	    {'.', '.', '.', 'p', '.', '.', '.', '.'},
	    {'.', '.', '.', 'R', '.', '.', '.', 'p'},
	    {'.', '.', '.', '.', '.', '.', '.', '.'},
	    {'.', '.', '.', 'p', '.', '.', '.', '.'},
	    {'.', '.', '.', '.', '.', '.', '.', '.'},
	    {'.', '.', '.', '.', '.', '.', '.', '.'},
	    {'.', '.', '.', '.', '.', '.', '.', '.'},
	};

	char b2[8][8] = {
	    {'.', '.', '.', '.', '.', '.', '.', '.'},
	    {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
	    {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
	    {'.', 'p', 'B', 'R', 'B', 'p', '.', '.'},
	    {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
	    {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
	    {'.', '.', '.', '.', '.', '.', '.', '.'},
	    {'.', '.', '.', '.', '.', '.', '.', '.'},
	};

	char b3[8][8] = {
	    {'.', '.', '.', '.', '.', '.', '.', '.'},
	    {'.', '.', '.', 'p', '.', '.', '.', '.'},
	    {'.', '.', '.', 'p', '.', '.', '.', '.'},
	    {'p', 'p', '.', 'R', '.', 'p', 'B', '.'},
	    {'.', '.', '.', '.', '.', '.', '.', '.'},
	    {'.', '.', '.', 'B', '.', '.', '.', '.'},
	    {'.', '.', '.', 'p', '.', '.', '.', '.'},
	    {'.', '.', '.', '.', '.', '.', '.', '.'},
	};

	printf("%d\n", rookcaptures(b1));
	printf("%d\n", rookcaptures(b2));
	printf("%d\n", rookcaptures(b3));

	return 0;
}
