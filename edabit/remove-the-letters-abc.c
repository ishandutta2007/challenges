/*

Create a function that will remove the letters "a", "b" and "c" from the given string and return the modified version.
If the given string does not contain "a", "b", or "c", return null.

Examples

removeABC("This might be a bit hard") ➞ "This might e  it hrd"

removeABC("hello world!") ➞ null

removeABC("") ➞ null

Notes

If the given string does not contain "a", "b", or "c", return null.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
removeabc(const char *s, char *b)
{
	size_t i, j;
	int f;

	f = 0;
	for (i = j = 0; s[i]; i++) {
		if (strchr("abc", s[i]))
			f = 1;
		else
			b[j++] = s[i];
	}
	b[j] = '\0';

	return (f) ? b : NULL;
}

void
test(const char *s, const char *r)
{
	char b[128], *p;

	p = removeabc(s, b);
	if (!p)
		assert(p == r);
	else
		assert(!strcmp(p, r));
}

int
main(void)
{
	test("This might be a bit hard", "This might e  it hrd");
	test("This is awesome", "This is wesome");
	test("hello world!", NULL);
	test("coding is fun!", "oding is fun!");
	test("", NULL);

	return 0;
}
