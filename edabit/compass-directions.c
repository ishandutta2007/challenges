/*

You face 1 out of the 4 compass directions: N, S, E or W.

    A left turn is a counter-clockwise turn. e.g. N (left-turn) ➞ W.
    A right turn is a clockwise turn. e.g. N (right-turn) ➞ E.

Create a function that takes in a starting direction and a sequence of left and right turns, and outputs the final direction faced.

Examples

final_direction("N", ["L", "L", "L"]) ➞ "E"

final_direction("N", ["R", "R", "R", "L"]) ➞ "S"

final_direction("N", ["R", "R", "R", "R"]) ➞ "N"

final_direction("N", ["R", "L"]) ➞ "N"

Notes

You can only face 1 out of the 4 compass directions: N, S, E or W.

*/

#include <assert.h>
#include <stdio.h>

unsigned
ri(char d)
{
	switch (d) {
	case 'N':
		return 0;
	case 'E':
		return 1;
	case 'S':
		return 2;
	case 'W':
		return 3;
	}
	return 'X';
}

char
rd(unsigned p)
{
	switch (p) {
	case 0:
		return 'N';
	case 1:
		return 'E';
	case 2:
		return 'S';
	case 3:
		return 'W';
	}
	return 'X';
}

char
compass(char d, const char *s)
{
	size_t i;
	unsigned p;

	p = ri(d);
	if (p == 'X')
		return p;
	for (i = 0; s[i]; i++) {
		if (s[i] == 'L')
			p--;
		else if (s[i] == 'R')
			p++;
	}
	return rd(p & 3);
}

int
main(void)
{
	assert(compass('N', "LLL") == 'E');
	assert(compass('N', "RRRRRRR") == 'W');
	assert(compass('N', "RRRL") == 'S');
	assert(compass('N', "RRRR") == 'N');
	assert(compass('N', "RL") == 'N');
	assert(compass('S', "RLRLR") == 'W');
	assert(compass('S', "RLRLRL") == 'S');
	assert(compass('S', "RLRLLL") == 'N');
	assert(compass('S', "RR") == 'N');
	assert(compass('S', "R") == 'W');
	assert(compass('S', "L") == 'E');
	assert(compass('W', "LRR") == 'N');
	assert(compass('W', "RLL") == 'S');
	assert(compass('E', "LRR") == 'S');
	assert(compass('E', "RLL") == 'N');

	return 0;
}
