/*

Usually when you sign up for an account to buy something, your credit card number, phone number or answer to a secret question is partially obscured in some way.
Since someone could look over your shoulder, you don't want that shown on your screen. Hence, the website masks these strings.

Your task is to create a function that takes a string, transforms all but the last four characters into "#" and returns the new masked string.
Examples

maskify("4556364607935616") ➞ "############5616"

maskify("64607935616") ➞ "#######5616"

maskify("1") ➞ "1"

maskify("") ➞ ""

Notes

    The maskify function must accept a string of any length.
    An empty string should return an empty string (fourth example above).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
maskify(char *s)
{
	size_t i, l;
	char c[4];

	for (i = 0; s[i]; i++) {
		c[i & 3] = s[i];
		s[i] = '#';
	}

	l = i;
	for (i = 0; i < l && i < 4; i++)
		s[l - i - 1] = c[(l - i - 1) & 3];

	return s;
}

int
main(void)
{
	char s1[] = "4556364607935616";
	char s2[] = "64607935616";
	char s3[] = "1";
	char s4[] = "";
	char s5[] = "tBy>L/cMe+?<j:6n;C~H";

	assert(strcmp(maskify(s1), "############5616") == 0);
	assert(strcmp(maskify(s2), "#######5616") == 0);
	assert(strcmp(maskify(s3), "1") == 0);
	assert(strcmp(maskify(s4), "") == 0);
	assert(strcmp(maskify(s5), "################;C~H") == 0);

	return 0;
}
