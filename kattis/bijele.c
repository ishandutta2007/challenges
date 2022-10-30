/*

Mirko has found an old chessboard and a set of pieces in his attic. Unfortunately, the set contains only white pieces, and apparently an incorrect number of them. A set of pieces should contain:

    One king

    One queen

    Two rooks

    Two bishops

    Two knights

    Eight pawns

Mirko would like to know how many pieces of each type he should add or remove to make a valid set.

Input

The input consists of 6 integers on a single line, each between 0 and 10 (inclusive). The numbers are, in order, the numbers of kings, queens, rooks, bishops, knights and pawns in the set Mirko found.

Output

Output should consist of 6 integers on a single line; the number of pieces of each type Mirko should add or remove. If a number is positive, Mirko needs to add that many pieces. If a number is negative, Mirko needs to remove pieces.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
pieces(int p[6])
{
	static const int tab[] = {
	    1,
	    1,
	    2,
	    2,
	    2,
	    8,
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		p[i] = tab[i] - p[i];
}

void
test(int p[6], int r[6])
{
	pieces(p);
	assert(!memcmp(p, r, sizeof(*r) * 6));
}

int
main(void)
{
	test((int[]){0, 1, 2, 2, 2, 7}, (int[]){1, 0, 0, 0, 0, 1});
	test((int[]){2, 1, 2, 1, 2, 1}, (int[]){-1, 0, 0, 1, 0, 7});

	return 0;
}
