/*

Given a name, return the letter with the highest index in alphabetical order, with its corresponding index, in the form of a string.

Examples

alphabet = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]


alphabetIndex("Flavio") ➞ "22v"

alphabetIndex("Andrey") ➞ "25y"

alphabetIndex()"Oscar") ➞ "19s"

Notes

If you're stuck, check the Resources tab.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
alphaindex(const char *s, char *b)
{
	size_t i;
	int c, d;

	c = -1;
	for (i = 0; s[i]; i++) {
		d = tolower(s[i]);
		if (c < d)
			c = d;
	}

	i = isalpha(c) ? c - 'a' + 1 : c;
	sprintf(b, "%zu%c", i, c);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[32];

	alphaindex(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Oscar", "19s");
	test("Lucas", "21u");
	test("Marko", "18r");
	test("Esley", "25y");
	test("Rogei", "18r");
	test("Nicolas", "19s");
	test("Flavio", "22v");
	test("Andrey", "25y");
	test("Hello", "15o");

	return 0;
}
