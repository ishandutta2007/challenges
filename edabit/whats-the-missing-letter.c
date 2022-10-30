/*

Given a string of letters in the English alphabet, return the letter that's missing from the string.
The missing letter will make the string be in alphabetical order (from A to Z).

If there are no missing letters in the string, return "No Missing Letter".
Examples

missingLetter("abdefg") ➞ "c"

missingLetter("mnopqs") ➞ "r"

missingLetter("tuvxyz") ➞ "w"

missingLetter("ghijklmno") ➞ "No Missing Letter"

Notes

The given string will never have more than one missing letter.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
missingletter(const char *s, char *b)
{
	size_t i;

	for (i = 0; s[i] && s[i + 1]; i++) {
		if (tolower(s[i]) + 1 != tolower(s[i + 1])) {
			b[0] = s[i] + 1;
			b[1] = '\0';
			return b;
		}
	}
	sprintf(b, "No Missing Letter");
	return b;
}

void
test(const char *s, const char *r)
{
	char b[80];

	missingletter(s, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("abdefg", "c");
	test("mnopqs", "r");
	test("tuvxyz", "w");
	test("jlm", "k");
	test("rsu", "t");
	test("eghij", "f");
	test("qrtuv", "s");
	test("ghijklmno", "No Missing Letter");
	test("xyz", "No Missing Letter");

	return 0;
}
