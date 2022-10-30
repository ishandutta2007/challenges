/*

Create a function that takes a string and returns a new string with its first and last characters swapped, except under three conditions:

    If the length of the string is less than two, return "Incompatible.".
    If the argument is not a string, return "Incompatible.".
    If the first and last characters are the same, return "Two's a pair.".

Examples

flipEndChars("Cat, dog, and mouse.") ➞ ".at, dog, and mouseC"

flipEndChars("ada") ➞ "Two's a pair."

flipEndChars("Ada") ➞ "adA"

flipEndChars("z") ➞ "Incompatible."

flipEndChars([1, 2, 3]) ➞ "Incompatible."

Notes

Tests are case sensitive (e.g. "A" and "a" are not the same character).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
swapc(char *x, char *y)
{
	char t;

	t = *x;
	*x = *y;
	*y = t;
}

char *
flipendchars(const char *s, char *b, size_t n)
{
	size_t l;

	l = strlen(s);
	if (l < 2)
		snprintf(b, n, "Incompatible.");
	else if (s[0] == s[l - 1])
		snprintf(b, n, "Two's a pair.");
	else {
		snprintf(b, n, "%s", s);
		if (l < n)
			swapc(&b[0], &b[l - 1]);
	}
	return b;
}

void
test(const char *s, const char *t)
{
	char b[1024];

	flipendchars(s, b, sizeof(b));
	assert(strcmp(b, t) == 0);
}

int
main(void)
{
	test("Cat, dog, and mouse.", ".at, dog, and mouseC");
	test("ada", "Two's a pair.");
	test("Ada", "adA");
	test("z", "Incompatible.");
	test("dfdkf49824fdfdfjhd", "Two's a pair.");
	test("#343473847#", "Two's a pair.");
	return 0;
}
