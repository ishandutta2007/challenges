/*

Create a function that takes a string, checks if it has the same number of x's and o's and returns either true or false.

    Return a boolean value (true or false).
    The string can contain any character.
    When no x and no o are in the string, return true.

Examples

XO("ooxx") ➞ true

XO("xooxx") ➞ false

XO("ooxXm") ➞ true
// Case insensitive.

XO("zpzpzpp") ➞ true
// Returns true if no x and o.

XO("zzoo") ➞ false

Notes

    Remember to return true if there aren't any x's or o's.
    Must be case insensitive.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

bool
XO(const char *s)
{
	size_t i, x, o;

	x = o = 0;
	for (i = 0; s[i]; i++) {
		x += tolower(s[i]) == 'x';
		o += tolower(s[i]) == 'o';
	}
	return x == o;
}

int
main(void)
{
	assert(XO("ooxx") == true);
	assert(XO("xooxx") == false);
	assert(XO("ooxXm") == true);
	assert(XO("zpzpzpp") == true);
	assert(XO("zzoo") == false);
	assert(XO("Xo") == true);
	assert(XO("x") == false);
	assert(XO("o") == false);
	assert(XO("xxxoo") == false);
	assert(XO("ooxx") == true);

	return 0;
}
