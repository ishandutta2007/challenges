/*

Create a function that returns true if the given string has any of the following:

    Only letters and no numbers.
    Only numbers and no letters.

If a string has both numbers and letters, or contains characters which don't fit into any category, return false

Examples

alphanumericRestriction("Bold") ➞ true

alphanumericRestriction("123454321") ➞ true

alphanumericRestriction("H3LL0") ➞ false

alphanumericRestriction("ed@bit") ➞ false

Notes

Any string that contains spaces or is empty should return false.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

bool
restricted(const char *s)
{
	size_t i, j, k;

	for (i = j = k = 0; s[i]; i++) {
		if (isalpha(s[i]))
			j++;
		else if (isdigit(s[i]))
			k++;
		else
			return false;
	}
	return !!j ^ !!k;
}

int
main(void)
{
	assert(restricted("Bold") == true);
	assert(restricted("123454321") == true);
	assert(restricted("H3LL0") == false);
	assert(restricted("hhefuhiwfgn") == true);
	assert(restricted("0") == true);
	assert(restricted("hhefuhiwfgn") == true);
	assert(restricted("ed@bit") == false);
	assert(restricted("only letters right") == false);
	assert(restricted("132 143 234") == false);
	assert(restricted("()") == false);
	assert(restricted("Hello") == true);
	assert(restricted("10,000") == false);
	assert(restricted("1a2b3c") == false);
	assert(restricted("") == false);

	return 0;
}
