/*

In chess, the Fool's Mate is the fastest possible way to reach checkmate. It is reached with Black's second move. In chess notation, one possible sequence of moves that achieves Fool's Mate is 1.f3 e6 2.g4 Qh4#.

Position after 1.f3 e6 2.g4 Qh4#

This is not the only possible way to achieve this checkmate (in the same number of moves). There are three things that can be varied while still taking the same number of moves:

White can move the f-pawn first or the g-pawn first,
White can move the f-pawn to f3 or f4, and
Black can move the e-pawn to e6 or e5.
This gives 8 possible games that end in Fool's Mate. Print them all in standard chess notation. They are:

1.f3 e5 2.g4 Qh4#
1.f3 e6 2.g4 Qh4#
1.f4 e5 2.g4 Qh4#
1.f4 e6 2.g4 Qh4#
1.g4 e5 2.f3 Qh4#
1.g4 e5 2.f4 Qh4#
1.g4 e6 2.f3 Qh4#
1.g4 e6 2.f4 Qh4#

The order in which the games are printed does not matter, so e.g. this is OK:

1.g4 e5 2.f4 Qh4#
1.f3 e6 2.g4 Qh4#
1.g4 e6 2.f4 Qh4#
1.f4 e5 2.g4 Qh4#
1.f4 e6 2.g4 Qh4#
1.g4 e5 2.f3 Qh4#
1.g4 e6 2.f3 Qh4#
1.f3 e5 2.g4 Qh4#

*/

#include <stdio.h>

char *
first(int n)
{
	if (n < 2)
		return "f3";
	if (n < 4)
		return "f4";
	return "g4";
}

char *
second(int n)
{
	if (n < 4)
		return (n & 1) ? "e6" : "e5";
	if (n < 6)
		return "e5";
	return "e6";
}

char *
third(int n)
{
	if (n < 4)
		return "g4";
	return (n & 1) ? "f4" : "f3";
}

char *
fourth(int)
{
	return "Qh4";
}

void
fools(void)
{
	int i;

	for (i = 0; i < 8; i++)
		printf("1. %s %s 2. %s %s#\n", first(i), second(i), third(i), fourth(i));
}

int
main(void)
{
	fools();
	return 0;
}
