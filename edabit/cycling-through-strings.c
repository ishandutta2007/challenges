/*

Given two strings, repeatedly cycle through all of the letters in the first string until it is the same length as the second string.
Examples

stringCycling("abc", "hello") ➞ "abcab"

stringCycling("programming", "edabit") ➞ "progra"

stringCycling("ha", "good morning") ➞ "hahahahahaha"

Notes

All tests will include valid strings.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
strcyc(const char *s, const char *t, char *b)
{
	size_t i, j, k;

	for (i = j = k = 0; t[i]; i++) {
		b[j++] = s[k++];
		if (!s[k - 1] || !s[k])
			k = 0;
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	strcyc(s, t, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("abc", "hello", "abcab");
	test("programming", "edabit", "progra");
	test("ha", "good morning", "hahahahahaha");
	test(" ", "python", "      ");
	test("the quick brown fox jumps over the lazy dog", "abcde", "the q");
	test("", "", "");

	return 0;
}
