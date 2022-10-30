/*

Create a function that accepts an array of two strings and checks if the letters in the second string are present in the first string.
Examples

letterCheck(["trances", "nectar"]) ➞ true

letterCheck(["compadres", "DRAPES"]) ➞ true

letterCheck(["parses", "parsecs"]) ➞ false

Notes

    Function should not be case sensitive (as indicated in the second example).
    Both strings are presented as a single argument in the form of an array.
    Bonus: Solve this without RegEx.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
lw(int c)
{
	c &= 0xff;
	if (isalpha(c))
		return tolower(c);
	return c;
}

bool
lettercheck(const char *s, const char *t)
{
	size_t i, h[256];

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++)
		h[lw(s[i])]++;
	for (i = 0; t[i]; i++) {
		if (!h[lw(t[i])])
			return false;
	}
	return true;
}

int
main(void)
{
	assert(lettercheck("compadres", "DRAPES") == true);
	assert(lettercheck("parses", "parsecs") == false);
	assert(lettercheck("trances", "nectar") == true);
	assert(lettercheck("THE EYES", "they see") == true);
	assert(lettercheck("assert", "staring") == false);
	assert(lettercheck("arches", "later") == false);
	assert(lettercheck("dale", "caller") == false);
	assert(lettercheck("parses", "parsecs") == false);
	assert(lettercheck("replays", "adam") == false);
	assert(lettercheck("mastering", "streaming") == true);
	assert(lettercheck("drapes", "compadres") == false);
	assert(lettercheck("deltas", "slated") == true);

	return 0;
}
