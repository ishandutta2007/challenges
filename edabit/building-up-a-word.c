/*

You are given an input list of strings, ordered by ascending length.

Write a function that returns True if, for each pair of consecutive strings, the second string can be formed from the first by adding a single letter either at the beginning or end.
Examples

can_build(["a", "at", "ate", "late", "plate", "plates"]) ➞ True

can_build(["a", "at", "ate", "late", "plate", "plater", "platter"]) ➞ False
# "platter" is formed by adding "t" in the middle of "plater"

can_build(["it", "bit", "bite", "biters"]) ➞ False
# "biters" is formed by adding two letters - we can only add one

can_build(["mean", "meany"]) ➞ True

Notes

    Return False a word is NOT formed by adding only one letter.
    Return False if the letter is added to the middle of the previous word.
    Letters in tests will all be lower case.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
canbuild(const char **s, size_t n)
{
	size_t i, x, y;

	if (n == 0)
		return true;

	x = strlen(s[0]);
	for (i = 1; i < n; i++) {
		y = strlen(s[i]);
		if (!(x + 1 == y && (!strncmp(s[i], s[i - 1], x) || !strncmp(s[i] + 1, s[i - 1], x))))
			return false;
		x = y;
	}

	return true;
}

int
main(void)
{
	const char *s1[] = { "a", "at", "ate", "late", "plate", "plates" };
	const char *s2[] = { "u", "ut", "but", "butt", "butte", "butter", "buttery" };
	const char *s3[] = { "a", "ka", "ika", "pika", "pikac", "pikach", "pikachu" };
	const char *s4[] = { "a", "at", "tat", "stat", "state", "estate", "estates" };
	const char *s5[] = { "o", "ol", "old", "bold", "bolde", "mbolde", "embolde", "embolden" };
	const char *s6[] = { "mean", "meany" };
	const char *s7[] = { "at", "cat", "cate", "cater", "caters" };
	const char *s8[] = { "a", "at", "ate", "late", "plate", "plater", "platter" };
	const char *s9[] = { "i", "it", "bit", "bite", "biters" };
	const char *s10[] = { "e", "tea", "teac", "teach", "teache", "teacher", "teachers" };
	const char *s11[] = { "m", "ma", "man", "many", "meany" };
	const char *s12[] = { "o", "op", "top", "stop", "stops", "stoops" };
	const char *s13[] = { "air", "air", "airy", "fairy" };
	const char *s14[] = { "men", "mean", "meany" };

	assert(canbuild(s1, nelem(s1)) == true);
	assert(canbuild(s2, nelem(s2)) == true);
	assert(canbuild(s3, nelem(s3)) == true);
	assert(canbuild(s4, nelem(s4)) == true);
	assert(canbuild(s5, nelem(s5)) == true);
	assert(canbuild(s6, nelem(s6)) == true);
	assert(canbuild(s7, nelem(s7)) == true);
	assert(canbuild(s8, nelem(s8)) == false);
	assert(canbuild(s9, nelem(s9)) == false);
	assert(canbuild(s10, nelem(s10)) == false);
	assert(canbuild(s11, nelem(s11)) == false);
	assert(canbuild(s12, nelem(s12)) == false);
	assert(canbuild(s13, nelem(s13)) == false);
	assert(canbuild(s14, nelem(s14)) == false);

	return 0;
}
