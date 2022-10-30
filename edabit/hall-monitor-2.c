/*

A floor plan is arranged as follows:

    You may freely move between rooms 1 and 2.
    You may freely move between rooms 3 and 4.
    However, you can enter the hallway to move between rooms 2 and 4.

Floor Plan

Create a function that validates whether the route taken between rooms is possible. The hallway will be given as the letter "H".
Examples

possiblePath([1, 2, "H", 4, 3]) ➞ true

possiblePath(["H", 1, 2]) ➞ false

possiblePath([4, 3, 4, "H", 4, "H"]) ➞ true

Notes

    A route may begin or end in any room (including the hallway).
    All inputs are either numbers 1-4 or the letter "H".
    No rooms will repeat.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int
ri(int r)
{
	switch (r) {
	case '1':
		return 0;
	case '2':
		return 1;
	case 'H':
		return 2;
	case '4':
		return 3;
	case '3':
		return 4;
	}
	return -1;
}

bool
path(const char *s)
{
	size_t i;
	int x, y;

	for (i = 0; s[i] && s[i + 1]; i++) {
		x = ri(s[i]);
		y = ri(s[i + 1]);
		if (x < 0 || y < 0 || abs(x - y) > 1)
			return false;
	}
	return true;
}

int
main(void)
{
	assert(path("12H43") == true);
	assert(path("H12") == false);
	assert(path("434H4H") == true);
	assert(path("H") == true);
	assert(path("1") == true);
	assert(path("121") == true);
	assert(path("H21H2") == false);
	assert(path("3H21") == false);
	assert(path("H23H") == false);
	assert(path("134") == false);

	return 0;
}
