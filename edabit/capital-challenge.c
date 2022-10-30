/*

Given two strings, s1 and s2, select only the characters in each string where the character in the same position in the other string is in uppercase. Return these as a single string.

To illustrate, given the strings s1 = "heLLo" and s2 = "GUlp", we select the letters "he" from s1, because "G" and "U" are uppercase. We then select "lp" from s2, because "LL" is in uppercase. Finally, we join these together and return "help".
Examples

selectLetters("heLLO", "GUlp") ➞ "help"

selectLetters("1234567", "XxXxX")  ➞ "135"

selectLetters("EVERYTHING", "SomeThings") ➞  "EYSomeThings"

Notes

    The strings don't have to be the same length.
    Strings can contain non-alphabetic characters.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
selective(const char *s, const char *t, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i] && t[i]; i++) {
		if (isupper(t[i]))
			b[j++] = s[i];
	}
	for (i = 0; s[i] && t[i]; i++) {
		if (isupper(s[i]))
			b[j++] = t[i];
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[80];

	selective(s, t, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("heLLO", "GUlp", "help");
	test("1234567", "XxXxX", "135");
	test("EVERYTHING", "SomeThings", "EYSomeThings");
	test("PaTtErN", "pAtTeRn", "atrpten");
	test("nothing", "nothing", "");
	test("What do you think of it so far?", "RUBBISH!", "What doR");

	return 0;
}
