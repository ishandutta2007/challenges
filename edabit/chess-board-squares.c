/*

Create a function that takes a code of chess board square and return his color.

Alternative Text

Examples

chess_board("a1") ➞ "black"

chess_board("e5") ➞ "black"

chess_board("d1") ➞ "white"

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
chessboard(const char s[2])
{
	int f, r;

	r = s[0] - 'a';
	f = s[1] - '1';
	if (r < 0 || r >= 8 || f < 0 || f >= 8)
		return NULL;
	return ((r ^ f) & 1) ? "white" : "black";
}

void
test(const char s[2], const char *r)
{
	assert(!strcmp(chessboard(s), r));
}

int
main(void)
{
	test("a1", "black");
	test("e5", "black");
	test("d1", "white");
	test("c7", "black");
	test("h5", "white");
	test("g2", "white");
	test("b3", "white");
	test("f6", "black");
	test("g5", "black");
	test("c8", "white");
	test("e6", "white");
	test("b7", "white");
	test("g8", "white");
	test("h8", "black");
	test("h6", "black");
	test("a3", "black");
	test("a5", "black");
	test("a7", "black");

	return 0;
}
