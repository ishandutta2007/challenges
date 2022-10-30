/*

Mubashir has started his journey from home. Given a string of directions (N=North, W=West, S=South, E=East), he will walk for one minute in each direction.
Determine whether a set of directions will lead him back to the starting position or not.

Examples

backToHome("EEWE") ➞ false

backToHome("NENESSWW") ➞ true

backToHome("NEESSW") ➞ false

Notes

N/A

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
	int x, y;
} Point;

bool
backhome(const char *s)
{
	Point p;

	p.x = p.y = 0;
	while (*s) {
		switch (*s++) {
		case 'N':
			p.y++;
			break;
		case 'S':
			p.y--;
			break;
		case 'E':
			p.x++;
			break;
		case 'W':
			p.x--;
			break;
		}
	}
	return p.x == 0 && p.y == 0;
}

int
main(void)
{
	assert(backhome("NNNN") == false);
	assert(backhome("NENESSWW") == true);
	assert(backhome("NEESSW") == false);
	assert(backhome("EEWE") == false);
	assert(backhome("NNSSEEEWWWEW") == true);

	return 0;
}
