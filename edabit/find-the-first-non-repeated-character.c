/*

Create a function that accepts a string as an argument and returns the first non-repeated character.

Examples

firstNonRepeatedCharacter("g") ➞ "g"

firstNonRepeatedCharacter("it was then the frothy word met the round night") ➞ "a"

firstNonRepeatedCharacter("the quick brown fox jumps then quickly blows air") ➞ "f"

firstNonRepeatedCharacter("hheelloo") ➞ false

firstNonRepeatedCharacter("") ➞ false

Notes

    An empty string should return false.
    If every character repeats, return false.
    Don't worry about case sensitivity or non-alphanumeric characters.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
nrc(const char *s)
{
	size_t i, j, h[256][2];
	int c;

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++) {
		c = s[i] & 0xff;
		h[c][0]++;
		h[c][1] = i;
	}

	c = 0;
	for (i = j = 0; i < nelem(h); i++) {
		if (h[i][0] == 1 && (c == 0 || h[i][1] < j)) {
			j = h[i][1];
			c = i;
		}
	}
	return c;
}

int
main(void)
{
	assert(nrc("g") == 'g');
	assert(nrc("it was then the frothy word met the round night") == 'a');
	assert(nrc("the quick brown fox jumps then quickly blows air") == 'f');
	assert(nrc("the misty examination pleases into the drab county") == 'x');
	assert(nrc("hheelloo") == 0);
	assert(nrc("it was then the darling top met the whispering wing") == 'd');
	assert(nrc("") == 0);
	assert(nrc("it was then the frothy word met the round night") == 'a');
	assert(nrc("is the remind zone better than the section") == 'm');
	assert(nrc("b") == 'b');
	assert(nrc("what if the brainy boss ate the afternoon") == 'w');
	assert(nrc("the sympathetic mixture rejects into the leafy objective") == 'p');

	return 0;
}
