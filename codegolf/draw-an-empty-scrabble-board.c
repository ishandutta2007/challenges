/*

A standard Scrabble board is a 15×15 grid of spaces to place letter tiles.
Most of the spaces are blank but some are double word scores (pink), triple word scores (red), double letter scores (light blue), and triple letter scores (blue).
There is usually a star in the very center (which counts as a double word score).

Scrabble board

Write a program or function that outputs a standard, empty Scrabble board in ASCII form where:

. represents an empty space

D represents a double word score

T represents a triple word score

d represents a double letter score

t represents a triple letter score

X represents the center star

That is, your exact output must be

T..d...T...d..T
.D...t...t...D.
..D...d.d...D..
d..D...d...D..d
....D.....D....
.t...t...t...t.
..d...d.d...d..
T..d...X...d..T
..d...d.d...d..
.t...t...t...t.
....D.....D....
d..D...d...D..d
..D...d.d...D..
.D...t...t...D.
T..d...T...d..T

optionally followed by a trailing newline.

The shortest code in bytes wins.

*/

#include <stdio.h>

void
scrabble(void)
{
	puts("T..d...T...d..T");
	puts(".D...t...t...D.");
	puts("..D...d.d...D..");
	puts("d..D...d...D..d");
	puts("....D.....D....");
	puts(".t...t...t...t.");
	puts("..d...d.d...d..");
	puts("T..d...X...d..T");
	puts("..d...d.d...d..");
	puts(".t...t...t...t.");
	puts("....D.....D....");
	puts("d..D...d...D..d");
	puts("..D...d.d...D..");
	puts(".D...t...t...D.");
	puts("T..d...T...d..T");
}

int
main(void)
{
	scrabble();
	return 0;
}
