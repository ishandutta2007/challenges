/*

Jay and Silent Bob have been given a fraction of an ounce but they only understand grams.
Convert a fraction passed as a string to grams with up to two decimal places. An ounce weighs 28 grams.

Examples

jay_and_bob("half") ➞ "14 grams"

jay_and_bob("quarter") ➞ "7 grams"

jay_and_bob("eighth") ➞ "3.5 grams"

Notes

Add the string "grams" to the end with a space.

Test.assert_equals(jay_and_bob("half"), "14 grams")

Test.assert_equals(jay_and_bob("quarter"), "7 grams")

Test.assert_equals(jay_and_bob("eighth"), "3.5 grams")

Test.assert_equals(jay_and_bob("sixteenth"), "1.75 grams")

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
jayandbob(const char *s, char *b, size_t n)
{
	static const char tab[][2][80] = {
	    {"half", "14 grams"},
	    {"quarter", "7 grams"},
	    {"eighth", "3.5 grams"},
	    {"sixteenth", "1.75 grams"},
	};
	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (!strcmp(s, tab[i][0])) {
			snprintf(b, n, "%s", tab[i][1]);
			return b;
		}
	}
	return NULL;
}

void
test(const char *s, const char *r)
{
	char b[80];

	jayandbob(s, b, sizeof(b));
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("half", "14 grams");
	test("quarter", "7 grams");
	test("eighth", "3.5 grams");
	test("sixteenth", "1.75 grams");

	return 0;
}
