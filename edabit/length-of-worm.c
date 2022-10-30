/*

Given a string worm create a function that takes the length of the worm and converts it into millimeters. Each - represents one centimeter.

Examples

wormLength("----------") ➞ "100 mm."

wormLength("") ➞ "invalid"

wormLength("---_-___---_") ➞ "invalid"

Notes

Return "invalid" if an empty string is given or if the string has characters other than -.

Test.assertEquals(wormLength("----------"), "100 mm.")

Test.assertEquals(wormLength(""), "invalid")

Test.assertEquals(wormLength("---_-___---_"), "invalid")

Test.assertEquals(wormLength("------"), "60 mm.")

Test.assertEquals(wormLength("iwheguawhpvpaiehpiuwwega"), "invalid")

Test.assertEquals(wormLength("QWERTYUIOPASDFGHJKL"), "invalid")

Test.assertEquals(wormLength("------------"), "120 mm.")

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
wormlength(const char *s, char *b, size_t n)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (s[i] != '-')
			goto error;
	}

	if (i == 0) {
	error:
		snprintf(b, n, "invalid");
		return b;
	}

	snprintf(b, n, "%zu mm.", i * 10);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	wormlength(s, b, sizeof(b));
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("----------", "100 mm.");
	test("", "invalid");
	test("---_-___---_", "invalid");
	test("------", "60 mm.");
	test("iwheguawhpvpaiehpiuwwega", "invalid");
	test("QWERTYUIOPASDFGHJKL", "invalid");
	test("------------", "120 mm.");

	return 0;
}
