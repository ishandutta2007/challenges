/*

Create a function which adds spaces before every capital in a word. Uncapitalize the whole string afterwards.
Examples

capSpace("helloWorld") ➞ "hello world"

capSpace("iLoveMyTeapot") ➞ "i love my teapot"

capSpace("stayIndoors") ➞ "stay indoors"

Notes

The first letter will stay uncapitalized.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
capspace(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (isupper(s[i]) && i > 0)
			b[j++] = ' ';
		b[j++] = tolower(s[i]);
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[80];

	capspace(s, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("helloWorld", "hello world");
	test("iLoveMyTeapot", "i love my teapot");
	test("stayIndoors", "stay indoors");

	return 0;
}
