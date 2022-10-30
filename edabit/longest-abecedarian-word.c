/*

An abecedarian word is a word where all of its letters are arranged in alphabetical order. Examples of these words include:

    Empty
    Forty
    Almost

Given an array of words, create a function which returns the longest abecedarian word. If no word in an array matches the criterea, return an empty string.

Examples

LongestAbecedarian(new string[] { "ace", "spades", "hearts", "clubs" }) ➞ "ace"

LongestAbecedarian(new string[] { "forty", "choppy", "ghost" }) ➞ "choppy"

LongestAbecedarian(new string[] { "one", "two", "three" }) ➞ ""

Notes

    All words will be given in lowercase.
    If two abecedarian words have the same length, return the word which appeared first in the array.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
count(const char *s)
{
	size_t c, i;

	c = 0;
	for (i = 0; s[i] && s[i + 1]; i++) {
		if (s[i] <= s[i + 1])
			c++;
		else
			return 0;
	}
	return c;
}

const char *
abecedarian(const char **s, size_t n)
{
	size_t i, x, y;
	const char *p;

	p = "";
	x = 0;
	for (i = 0; i < n; i++) {
		y = count(s[i]);
		if (x < y) {
			p = s[i];
			x = y;
		}
	}
	return p;
}

void
test(const char **s, size_t n, const char *r)
{
	const char *p;

	p = abecedarian(s, n);
	if (!p)
		assert(p == r);
	else
		assert(!strcmp(p, r));
}

int
main(void)
{
	const char *s1[] = {"ace", "spades", "hearts", "clubs"};
	const char *s2[] = {"forty", "choppy", "ghost"};
	const char *s3[] = {"one", "two", "three"};
	const char *s4[] = {"almost", "accept", "access"};
	const char *s5[] = {"aa", "bbb", "cccc"};

	test(s1, nelem(s1), "ace");
	test(s2, nelem(s2), "choppy");
	test(s3, nelem(s3), "");
	test(s4, nelem(s4), "almost");
	test(s5, nelem(s5), "cccc");

	return 0;
}
