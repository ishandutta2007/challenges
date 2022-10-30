/*

Write a function which increments a string to create a new string.

    If the string ends with a number, the number should be incremented by 1.
    If the string doesn't end with a number, 1 should be added to the new string.
    If the number has leading zeros, the amount of digits should be considered.

Examples

incrementString("foo") ➞ "foo1"

incrementString("foobar0009") ➞ "foobar0010"

incrementString("foo099") ➞ "foo100"

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *
incs(const char *s, char *b, size_t n)
{
	char fmt[128];
	unsigned long v;
	size_t l, d;

	l = strlen(s);
	for (d = 0; l > 0; l--) {
		if (!isdigit(s[l - 1]))
			break;
		d++;
	}

	v = strtoul(s + l, NULL, 10);
	snprintf(fmt, sizeof(fmt), "%%.%zus%%0%zulu", l, d);
	snprintf(b, n, fmt, s, v + 1);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	incs(s, b, sizeof(b));
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("foo", "foo1");
	test("foobar0009", "foobar0010");
	test("foobar01002", "foobar01003");
	test("foobar00599", "foobar00600");
	test("foo099", "foo100");
	test("foo09999", "foo10000");
	test("", "1");
	test("000", "001");

	return 0;
}
