/*

Create a function that takes a string and checks if every single character is preceded and followed by a character adjacent to it in the english alphabet.

Example: "b" should be preceded and followed by ether "a" or "c" (abc || cba || aba || cbc == true but abf || zbc == false).

Examples

neighboring("aba") ➞ true

neighboring("abcdedcba") ➞ true

neighboring("efghihfe") ➞ false

neighboring("abc") ➞ true

neighboring("qrstuv") ➞ true

neighboring("mnopqrstsrqponm") ➞ true

Notes

All test cases will consist of lower case letters only.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool
neighbors(const char *s)
{
	size_t i;

	if (s[0] == '\0')
		return true;

	for (i = 1; s[i] && s[i + 1]; i++) {
		if (abs(s[i - 1] - s[i]) != 1 || abs(s[i + 1] - s[i]) != 1)
			return false;
	}
	return true;
}

int
main(void)
{
	assert(neighbors("abcdedcba") == true);
	assert(neighbors("aba") == true);
	assert(neighbors("efghihfe") == false);
	assert(neighbors("xyzyx") == true);
	assert(neighbors("mnopqrstsrqponm") == true);
	assert(neighbors("zyz") == true);
	assert(neighbors("aeiou") == false);
	assert(neighbors("cdefg") == true);
	assert(neighbors("qrstuv") == true);
	assert(neighbors("aaaaa") == false);

	return 0;
}
