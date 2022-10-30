/*

A floor plan is arranged as follows:

    Four rooms, which all lead into the hallway.
    It's impossible to move between rooms without first going into the hallway.

Room

Create a function which validates whether the path between rooms is possible. The hallway will be given as the letter 'H'.
Examples

possiblePath([1, "H", 2, "H", 3, "H", 4]) ➞ true

possiblePath(["H", 3, "H"]) ➞ true

possiblePath([1, 2, "H", 3]) ➞ false

Notes

    A route may begin or end in a hallway.
    All inputs are either numbers 1-4, or the letter "H".
    No rooms will repeat.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

int
ri(int r)
{
	switch (r) {
	case '1':
		return 0;
	case '2':
		return 1;
	case '3':
		return 2;
	case '4':
		return 3;
	case 'H':
		return 4;
	}
	return -1;
}

bool
path(const char *s)
{
	static const char tab[5][5] = {
	    {1, 0, 0, 0, 1},
	    {0, 1, 0, 0, 1},
	    {0, 0, 1, 0, 1},
	    {0, 0, 0, 1, 1},
	    {1, 1, 1, 1, 1},
	};

	size_t i;
	int x, y;

	for (i = 0; s[i] && s[i + 1]; i++) {
		x = ri(s[i]);
		y = ri(s[i + 1]);
		if (x < 0 || y < 0 || !tab[x][y])
			return false;
	}
	return true;
}

int
main(void)
{
	assert(path("1H2H3H4") == true);
	assert(path("H3H") == true);
	assert(path("H") == true);
	assert(path("3") == true);
	assert(path("12H3") == false);
	assert(path("H13") == false);
	assert(path("24H") == false);
	assert(path("1H1H1H") == true);
	assert(path("3H2H3H1") == true);
	assert(path("H2H34H1H2H") == false);

	return 0;
}
