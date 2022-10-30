/*

Write a function that swaps the first pair (1st and 2nd characters) with the second pair (3rd and 4th characters) for every quadruplet substring.
Examples

swapTwo("ABCDEFGH") ➞ "CDABGHEF"

swapTwo("AABBCCDDEEFF") ➞ "BBAADDCCFFEE"

swapTwo("munchkins") ➞ "ncmuinhks"

swapTwo("FFGGHHI") ➞ "GGFFHHI"

Notes

Keep leftover strings in the same order.

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

int
notnul4(const char *s)
{
	return s[0] && s[1] && s[2] && s[3];
}

char *
swaptwo(char *s)
{
	size_t i;

	for (i = 0; notnul4(&s[i]); i += 4) {
		swapc(&s[i], &s[i + 2]);
		swapc(&s[i + 1], &s[i + 3]);
	}
	return s;
}

void
test(const char *s, const char *t)
{
	char b[80];

	snprintf(b, sizeof(b), "%s", s);
	swaptwo(b);
	assert(!strcmp(b, t));
}

int
main(void)
{
	test("ABCDEFGH", "CDABGHEF");
	test("AABBCCDDEEFF", "BBAADDCCFFEE");
	test("oompaloompa", "mpooooalmpa");
	test("munchkins", "ncmuinhks");
	test("FFGGHHI", "GGFFHHI");
	test("FFG", "FFG");
	test("", "");

	return 0;
}
