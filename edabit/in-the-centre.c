/*

Given a string containing mostly spaces and one non-space character, return whether the character is positioned in the very centre of the string. This means the number of spaces on both sides should be the same.
Examples

isCentral("  #  ") ➞ true

isCentral(" 2    ") ➞ false

isCentral("@") ➞ true

Notes

Only one character other than spaces will be given at a time.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

bool
iscenter(const char *s)
{
	size_t i, x, y;

	x = y = 0;
	for (i = 0; s[i] && isspace(s[i]); i++)
		x++;

	if (s[i])
		i++;

	for (; s[i] && isspace(s[i]); i++)
		y++;

	return x == y;
}

int
main(void)
{
	assert(iscenter("  #  ") == true);
	assert(iscenter(" 2    ") == false);
	assert(iscenter("@") == true);
	assert(iscenter(" 1") == false);
	assert(iscenter("7 ") == false);
	assert(iscenter("  l ") == false);
	assert(iscenter(" a  ") == false);
	assert(iscenter("    G    ") == true);
	assert(iscenter("        %        ") == true);

	return 0;
}
