/*

Create a function that takes a string and returns the number of alphanumeric characters that occur more than once.

Examples

DuplicateCount("abcde") ➞ 0

DuplicateCount("aabbcde") ➞ 2

DuplicateCount("Indivisibilities") ➞ 2

DuplicateCount("Aa") ➞ 0
// Case sensitive

Notes

    Duplicate characters are case sensitive.
    The input string will contain only alphanumeric characters.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
duplicates(const char *s)
{
	size_t i, r, h[256];

	memset(h, 0, sizeof(h));
	for (i = r = 0; s[i]; i++) {
		if (++h[s[i] & 0xff] == 2)
			r++;
	}
	return r;
}

int
main(void)
{
	assert(duplicates("abcde") == 0);
	assert(duplicates("Aa") == 0);
	assert(duplicates("aabbcde") == 2);
	assert(duplicates("aabbcdeB") == 2);
	assert(duplicates("indivisibility") == 1);
	assert(duplicates("Indivisibilities") == 2);
	assert(duplicates("aa1112") == 2);
	assert(duplicates("bb2c") == 1);

	return 0;
}
