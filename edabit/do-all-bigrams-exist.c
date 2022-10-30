/*

You are given an input array of bigrams, and an array of words.

Write a function that returns true if you can find every single bigram from this array can be found at least once in an array of words.
Examples

canFind(["at", "be", "th", "au"], ["beautiful", "the", "hat"]) ➞ true

canFind(["ay", "be", "ta", "cu"], ["maybe", "beta", "abet", "course"]) ➞ false
# "cu" does not exist in any of the words

canFind(["th", "fo", "ma", "or"], ["the", "many", "for", "forest"]) ➞ true

canFind(["oo", "mi", "ki", "la"], ["milk", "chocolate", "cooks"]) ➞ false

Notes

A bigram is string of two consecutive characters.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
allbigrams(const char **s, size_t n, const char **t, size_t m)
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (strstr(t[j], s[i]))
				break;
		}
		if (j == m)
			return 0;
	}
	return 1;
}

int
main(void)
{
	const char *s1[] = { "at", "be", "th", "au" };
	const char *t1[] = { "beautiful", "the", "hat" };

	const char *s2[] = { "bo", "ta", "el", "st", "ca" };
	const char *t2[] = { "books", "table", "cap", "hostel" };

	const char *s3[] = { "la", "te" };
	const char *t3[] = { "latte" };

	const char *s4[] = { "th", "fo", "ma", "or" };
	const char *t4[] = { "the", "many", "for", "forest" };

	const char *s5[] = { "ay", "be", "ta", "cu" };
	const char *t5[] = { "maybe", "beta", "abet", "course" };

	const char *s6[] = { "oo", "mi", "ki", "la" };
	const char *t6[] = { "milk", "chocolate", "cooks" };

	const char *s7[] = { "la" };

	const char *s8[] = { "la", "at", "te", "ea" };
	const char *t8[] = { "latte" };

	assert(allbigrams(s1, nelem(s1), t1, nelem(t1)) == 1);
	assert(allbigrams(s2, nelem(s2), t2, nelem(t2)) == 1);
	assert(allbigrams(s3, nelem(s3), t3, nelem(t3)) == 1);
	assert(allbigrams(s4, nelem(s4), t4, nelem(t4)) == 1);
	assert(allbigrams(s5, nelem(s5), t5, nelem(t5)) == 0);
	assert(allbigrams(s6, nelem(s6), t6, nelem(t6)) == 0);
	assert(allbigrams(s7, nelem(s7), NULL, 0) == 0);
	assert(allbigrams(s8, nelem(s8), t8, nelem(t8)) == 0);

	return 0;
}
