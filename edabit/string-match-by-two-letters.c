/*

Create a function that takes two strings, a and b. Return the number of times the two strings contain the same two letters at the same index.

For example, if a = "bboiizz" and b = "bbuiiz", your function should return 3, since the "bb", "ii", and "iz" appear at the same place in both strings.
Examples

strMatchBy2char("yytaazz", "yyjaaz") ➞ 3

strMatchBy2char("edabit", "ed") ➞ 1

strMatchBy2char("", "") ➞ 0

Notes

Don't forget to return the result.

*/

#include <assert.h>
#include <stdio.h>

size_t
strmatch(const char *s, const char *t)
{
	size_t i, r;

	r = 0;
	for (i = 0; s[i] && t[i] && s[i + 1] && t[i + 1]; i++) {
		if (s[i] == t[i] && s[i + 1] == t[i + 1])
			r++;
	}
	return r;
}

int
main(void)
{
	assert(strmatch("bboiizz", "bbuiiz") == 3);
	assert(strmatch("yytaazz", "yyjaaz") == 3);
	assert(strmatch("edabit", "ed") == 1);
	assert(strmatch("", "") == 0);
	assert(strmatch("jjcAAzz", "jjBAAz") == 3);
	assert(strmatch("ABcd", "ABcD") == 2);
	assert(strmatch("ABc", "Ajc") == 0);
	assert(strmatch("ed", "edabit") == 1);
	assert(strmatch("e", "edabit") == 0);
	assert(strmatch("", "edabit") == 0);
	assert(strmatch("AABBccDD", "ABBBjjD") == 1);
	assert(strmatch("AAjjAAjj", "iAjjAi") == 3);
	assert(strmatch("iAjjAi", "AAjjAAjj") == 3);

	return 0;
}
