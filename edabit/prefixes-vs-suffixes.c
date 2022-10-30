/*

Create two functions: isPrefix(word, prefix-) and isSuffix(word, -suffix).

    isPrefix should return true if it begins with the prefix argument.
    isSuffix should return true if it ends with the suffix argument.

Otherwise return false.
Examples

isPrefix("automation", "auto-") ➞ true

isSuffix("arachnophobia", "-phobia") ➞ true

isPrefix("retrospect", "sub-") ➞ false

isSuffix("vocation", "-logy") ➞ false

Notes

The prefix and suffix arguments have dashes - in them.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool
isprefix(const char *s, const char *t)
{
	size_t i;

	for (i = 0; s[i] && t[i] && t[i + 1]; i++) {
		if (s[i] != t[i])
			return false;
	}
	return true;
}

bool
issuffix(const char *s, const char *t)
{
	size_t n, m;

	n = strlen(s);
	m = strlen(t);
	while (n > 0 && m > 1) {
		if (s[--n] != t[--m])
			return false;
	}
	return true;
}

int
main(void)
{
	assert(isprefix("automation", "auto-") == true);
	assert(isprefix("superfluous", "super-") == true);
	assert(isprefix("oration", "mega-") == false);
	assert(isprefix("retrospect", "-") == true);
	assert(isprefix("retrospect", "sub-") == false);
	assert(isprefix("vocation", "-logy") == false);

	assert(issuffix("arachnophobia", "-phobia") == true);
	assert(issuffix("rhinoplasty", "-plasty") == true);
	assert(issuffix("vocation", "-") == true);
	assert(issuffix("movement", "-scope") == false);
	assert(issuffix("vocation", "-logy") == false);

	return 0;
}
