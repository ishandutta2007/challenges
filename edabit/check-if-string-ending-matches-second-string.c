/*

Create a function that takes two strings and returns true if the first string ends with the second string; otherwise return false.
Examples

checkEnding("abc", "bc") ➞ true

checkEnding("abc", "d") ➞ false

checkEnding("samurai", "zi") ➞ false

checkEnding("feminine", "nine") ➞ true

checkEnding("convention", "tio") ➞ false

Notes

All test cases are valid one word strings.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
checkending(const char *s, const char *t)
{
	size_t n, m;

	n = strlen(s);
	m = strlen(t);

	if (m > n)
		return 0;
	return strcmp(s + n - m, t) == 0;
}

int
main(void)
{
	assert(checkending("2", "") == 1);
	assert(checkending("abc", "bcdifherighir") == 0);
	assert(checkending("abc", "bc") == 1);
	assert(checkending("abc", "d") == 0);
	assert(checkending("samurai", "zi") == 0);
	assert(checkending("feminine", "nine") == 1);
	assert(checkending("convention", "tio") == 0);
	assert(checkending("cooperative", "ooper") == 0);
	assert(checkending("extraterrestrial", "xtraterrestrial") == 1);
	assert(checkending("access", "ss") == 1);
	assert(checkending("motorist", "is") == 0);
	assert(checkending("landowner", "landowner") == 1);

	return 0;
}
