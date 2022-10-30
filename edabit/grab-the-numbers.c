/*

Given a string including a bunch of characters and numbers, return the sum of all the numbers in the string.
Note that multiple digits next to each other are counted as a whole number rather than separate digits.

Examples

grabNumberSum("aeiou250abc10") ➞ 260

grabNumberSum("one1two2twenty20") ➞ 23

grabNumberSum("900uwu50uwuuwuuwu25uwu25") ➞ 1000

Notes

Remember not to just add single digit numbers together, it should be possible for answers to easily get into the 100s!

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned long long uvlong;

uvlong
grabsum(const char *s)
{
	uvlong r;
	size_t i;
	char *ep;

	r = 0;
	for (i = 0; s[i]; i++) {
		if (isdigit(s[i])) {
			r += strtoull(&s[i], &ep, 10);
			i = ep - s - 1;
		}
	}
	return r;
}

int
main(void)
{
	assert(grabsum("aeiou5abc10") == 15);
	assert(grabsum("75shugeb15hvyff15") == 105);
	assert(grabsum("900uwu50uwuuwuuwu25uwu25") == 1000);
	assert(grabsum("one1two2twenty20") == 23);
	assert(grabsum("1s1s11") == 13);
	assert(grabsum("75") == 75);
	assert(grabsum("aeiou250abc10") == 260);

	return 0;
}
