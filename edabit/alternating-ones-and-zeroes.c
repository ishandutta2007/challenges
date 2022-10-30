/*

Write a function that returns true if the binary string can be rearranged to form a string of alternating 0s and 1s.

Examples

canAlternate("0001111") ➞ true
// Can make: "1010101"

canAlternate("01001") ➞ true
// Can make: "01010"

canAlternate("010001") ➞ false

canAlternate("1111") ➞ false

Notes

    No substring of the output may contain more than one consecutive repeating character (e.g. 00 or 11 are not allowed).
    Return false if a string only contains 0s or only contains 1s.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
alternate(const char *s)
{
	size_t i, z, o;

	for (i = z = o = 0; s[i]; i++) {
		z += (s[i] == '0');
		o += (s[i] == '1');
	}

	if (z == 0 || o == 0)
		return false;
	return z == o || z + 1 == o || o + 1 == z;
}

int
main(void)
{
	assert(alternate("0001111") == true);
	assert(alternate("01001") == true);
	assert(alternate("010001") == false);
	assert(alternate("0100110111") == false);
	assert(alternate("10101010") == true);
	assert(alternate("010101000") == false);
	assert(alternate("0111") == false);
	assert(alternate("00") == false);
	assert(alternate("1111") == false);
	assert(alternate("101") == true);
	assert(alternate("11") == false);
	assert(alternate("110") == true);

	return 0;
}
