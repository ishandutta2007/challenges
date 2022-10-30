/*

Write a function that returns the longest common ending between two strings.
Examples

longestCommonEnding("multiplication", "ration") ➞ "ation"

longestCommonEnding("potent", "tent") ➞ "tent"

longestCommonEnding("skyscraper", "carnivore") ➞ ""

Notes

Return an empty string if there exists no common ending.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
lce(const char *s, const char *t)
{
	size_t i, j, m, n;

	m = strlen(s);
	n = strlen(t);
	for (i = j = 0; i < m && j < n; i++, j++) {
		if (s[m - i - 1] != t[n - j - 1])
			return &s[m - i];
	}
	if (i == m)
		return s;
	if (j == n)
		return t;
	return "";
}

int
main(void)
{
	assert(!strcmp(lce("pitiful", "beautiful"), "tiful"));
	assert(!strcmp(lce("truck", "trick"), "ck"));
	assert(!strcmp(lce("vote", "asymptote"), "ote"));
	assert(!strcmp(lce("multiplication", "ration"), "ation"));
	assert(!strcmp(lce("potent", "tent"), "tent"));
	assert(!strcmp(lce("skyscraper", "carnivore"), ""));

	return 0;
}
