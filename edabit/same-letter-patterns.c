/*

Create a function that returns true if two strings share the same letter pattern, and false otherwise.
Examples

same_letter_pattern("ABAB", "CDCD") ➞ true

same_letter_pattern("ABCBA", "BCDCB") ➞ true

same_letter_pattern("FFGG", "CDCD") ➞ false

same_letter_pattern("FFFF", "ABCD") ➞ false

Notes

N/A

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool
samepattern(const char *s, const char *t)
{
	size_t i, h[2][256];

	memset(h, 0, sizeof(h));
	for (i = 0; s[i] && t[i]; i++) {
		if (h[0][s[i] & 0xff]++ != h[1][t[i] & 0xff]++)
			return false;
	}
	return !s[i] && !t[i];
}

int
main(void)
{
	assert(samepattern("ABAB", "CDCD") == true);
	assert(samepattern("AAABBB", "CCCDDD") == true);
	assert(samepattern("ABCBA", "BCDCB") == true);
	assert(samepattern("AAAA", "BBBB") == true);
	assert(samepattern("BAAB", "ABBA") == true);
	assert(samepattern("BAAB", "QZZQ") == true);
	assert(samepattern("TTZZVV", "PPSSBB") == true);
	assert(samepattern("ZYX", "ABC") == true);
	assert(samepattern("AABAA", "SSCSS") == true);
	assert(samepattern("AABAABAA", "SSCSSCSS") == true);
	assert(samepattern("UBUBUBUB", "WEWEWEWE") == true);
	assert(samepattern("FFGG", "FFG") == false);
	assert(samepattern("FFGG", "CDCD") == false);
	assert(samepattern("FFFG", "GGHI") == false);
	assert(samepattern("FFFF", "ABCD") == false);
	assert(samepattern("ABCA", "ABCD") == false);
	assert(samepattern("ABCAAA", "DDABCD") == false);

	return 0;
}
