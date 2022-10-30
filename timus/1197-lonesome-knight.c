/*

The statement of this problem is very simple: you are to determine how many squares of the chessboard can be attacked by a knight standing alone on the board.
Recall that a knight moves two squares forward (horizontally or vertically in any direction) and then one square sideways (perpedicularly to the first direction).

Input

The first line contains the number N of test cases, 1 ≤ N ≤ 64. Each of the following N lines contains a test: two characters.
The first character is a lowercase English letter from 'a' to 'h' and the second character is an integer from 1 to 8; they specify the rank and file of the square at which the knight is standing.

Output

Output N lines. Each line should contain the number of the squares of the chessboard that are under attack by the knight.

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
fsq(const char *s, int *r, int *f)
{
	int c0, c1;

	if (s[0] == '\0')
		return -1;

	c0 = tolower(s[0]);
	c1 = s[1];

	if (!('a' <= c0 && c0 <= 'h'))
		return -1;
	if (!('1' <= c1 && c1 <= '8'))
		return -1;

	*r = c0 - 'a' + 1;
	*f = c1 - '1' + 1;
	return 0;
}

int
ksq(const char *s)
{
	static const int moves[][2] = {
	    {-2, -1},
	    {-2, 1},
	    {-1, -2},
	    {-1, 2},
	    {1, -2},
	    {1, 2},
	    {2, -1},
	    {2, 1},
	};

	size_t i;
	int r, f;
	int x, y;
	int n;

	if (fsq(s, &r, &f) < 0)
		return 0;

	n = 0;
	for (i = 0; i < nelem(moves); i++) {
		x = r + moves[i][0];
		y = f + moves[i][1];
		if ((1 <= x && x <= 8) && (1 <= y && y <= 8))
			n++;
	}
	return n;
}

int
main(void)
{
	assert(ksq("a1") == 2);
	assert(ksq("d4") == 8);
	assert(ksq("g6") == 6);

	return 0;
}
