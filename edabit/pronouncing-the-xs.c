/*

Create a function which replaces all the x's in the string in the following ways:

Replace all x's with "cks" UNLESS:

    The word begins with "x", therefore replace it with "z".
    The word is just the letter "x", therefore replace it with "ecks".

Examples

xPronounce("Inside the box was a xylophone") ➞ "Inside the bocks was a zylophone"

xPronounce("The x ray is excellent") ➞ "The ecks ray is eckscellent"

xPronounce("OMG x box unboxing video x D") ➞ "OMG ecks bocks unbocksing video ecks D"

Notes

    All x's are lowercase.
    I know that not all words with x's follow this rule, but there are too many edge cases to count!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
pronounce(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		b[j] = s[i];
		if (b[j] != 'x') {
			j++;
			continue;
		}

		if (i > 0 && isspace(s[i - 1])) {
			if (isspace(s[i + 1]))
				j += sprintf(b + j, "ecks");
			else
				b[j++] = 'z';
		} else
			j += sprintf(b + j, "cks");
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	pronounce(s, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Inside the box was a xylophone", "Inside the bocks was a zylophone");
	test("The x ray is excellent", "The ecks ray is eckscellent");
	test("OMG x box unboxing video x D", "OMG ecks bocks unbocksing video ecks D");
	test("I gotta make bux but the clox are ticking!", "I gotta make bucks but the clocks are ticking!");
	test("this test does not have an x in it", "this test does not have an ecks in it");
	test("Max bax pax", "Macks backs packs");
	test("Anti vax", "Anti vacks");
	test("Who is xavier and why does he have my car", "Who is zavier and why does he have my car");
	test("OMG xylem unboxing video x D", "OMG zylem unbocksing video ecks D");

	return 0;
}
