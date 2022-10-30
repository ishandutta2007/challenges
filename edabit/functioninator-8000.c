/*

Create a function that takes a single word string and does the following:

    Concatenates inator to the end if the word ends with a consonant otherwise, concatenate -inator instead.

    Adds the word length of the original word to the end, supplied with '000'.

The examples should make this clear.
Examples

inatorInator("Shrink") ➞ "Shrinkinator 6000"

inatorInator("Doom") ➞ "Doominator 4000"

inatorInator("EvilClone") ➞ "EvilClone-inator 9000"

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
isvowel(char c)
{
	return strchr("aeiou", tolower(c)) != NULL;
}

char *
inator(const char *s, char *b)
{
	size_t i, l;

	for (i = 0; s[i]; i++)
		b[i] = s[i];

	l = i;
	if (l > 0 && isvowel(b[l - 1]))
		b[i++] = '-';
	sprintf(&b[i], "inator %zu000", l);

	return b;
}

void
test(const char *s, const char *t)
{
	char b[80];
	assert(!strcmp(inator(s, b), t));
}

int
main(void)
{
	test("Shrink", "Shrinkinator 6000");
	test("Doom", "Doominator 4000");
	test("EvilClone", "EvilClone-inator 9000");
	test("Destroy", "Destroyinator 7000");
	test("a", "a-inator 1000");
	test("Shrek", "Shrekinator 5000");
	test("bEE", "bEE-inator 3000");
	test("CAPITALISE", "CAPITALISE-inator 10000");
	test("", "inator 0000");

	return 0;
}
