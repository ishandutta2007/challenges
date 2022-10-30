/*

Introduction
In the wake of the left-pad npm package fallout, let's have a code golf for implementing left-pad.

The left-pad function consists of 2 default arguments and 1 additional argument, in the form string, length, (padchar). If the padchar is not given, this is standardized to a space character. Let's take an example with two arguments:

left_pad("abc", 6)
First, we observe the length of the string, which is 3. After this, we need to pad this string in the left until the length of the full string has reached the length given in the function.
In this case 6. Since the padchar is not given, we need to pad this with spaces:

   abc
This is a string with 3 spaces and the initial string, resulting into a string with length 6. Here is an example with the padchar given:

left_pad("abc", 6, "-")
We just do the same as the example above, but replace the spaces with the padchar. In this case, the hyphen:

---abc

The Task

Given the string, length, and maybe the additional argument padchar, output the left-padded string.
You can assume that the length number is equal or greater than the length of the string. The padchar will always consist of 1 character.

Test cases

left_pad("string", length, ("padchar")) === "left-padded string"

left_pad("foo", 5) === "  foo"
left_pad("foobar", 6) === "foobar"
left_pad("1", 2, "0") === "01"
left_pad("1", 2, "-") === "-1"
This is code-golf, so the submission with the smallest number of bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
leftpad(const char *s, size_t l, char p, char *b)
{
	size_t i, n;

	i = 0;
	n = strlen(s);
	if (n < l) {
		memset(b, p, l - n);
		i += l - n;
	}

	strcpy(b + i, s);
	return b;
}

void
test(const char *s, size_t l, char p, const char *r)
{
	char b[128];

	leftpad(s, l, p, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("foo", 5, ' ', "  foo");
	test("foobar", 6, ' ', "foobar");
	test("1", 2, '0', "01");
	test("1", 2, '-', "-1");

	return 0;
}
