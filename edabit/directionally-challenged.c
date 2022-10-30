/*

Suppose you are directionally challenged, and get lost easily. As a result, sometimes you walk in circles or make U-turns.
You might take a sub-optimal route. Create a function that returns the difference in length between your path and the optimal path. Both paths reach the same destination.

You start at (0,0) and reach your destination by the end of the input array.

A demonstration:

Your route: ["N", "S", "E", "W", "E", "E", "E", "N"]  // 8
Optimal route: ["E", "E", "E", "N"] (or ["N", "E", "E", "E"], etc.) // 4
// Difference in length: 8 - 4 = 4

// Explanation: Your "S" cancels out your "N" and your "W" cancels out your "E" leaving you back at (0,0)

Examples

routeDiff(["N", "E", "S", "W"]) ➞ 4
// You"ve just walked in a circle! You are back at the origin. Your optimal path was `[]`.

routeDiff(["N", "N", "N", "E", "N", "E"]) ➞ 0
// No improvements here!

routeDiff(["N", "S", "N", "S", "E", "W", "E", "E"]) ➞ 6

Notes

Remember that a N cancels out a S, and an E cancels out a W

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y;
} Point;

unsigned
route(const char *s)
{
	Point p;
	size_t i;

	p.x = p.y = 0;
	for (i = 0; s[i]; i++) {
		p.x += (s[i] == 'E');
		p.x -= (s[i] == 'W');
		p.y += (s[i] == 'N');
		p.y -= (s[i] == 'S');
	}
	return i - (abs(p.x) + abs(p.y));
}

int
main(void)
{
	assert(route("NESW") == 4);
	assert(route("NNNENE") == 0);
	assert(route("NSNSEWEE") == 6);
	assert(route("NSNSE") == 4);
	assert(route("NNSSSSE") == 4);
	assert(route("NNSSWSE") == 6);
	assert(route("NSE") == 2);
	assert(route("SSS") == 0);
	assert(route("SSSSSN") == 2);

	return 0;
}
