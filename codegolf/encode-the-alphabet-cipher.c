/*

Given a string that contains only lowercase letters, encode that string with the alphabet cipher.

To encode with the alphabet cipher (I will be using the example hello):

First, convert each letter in the string to a number depending on its position in the alphabet (a = 1, b = 2, etc.) Example: 8 5 12 12 15
Pad each number to two characters with 0s. Example: 08 05 12 12 15
Join. Example: 0805121215
Test cases
helloworld -> 08051212152315181204
codegolf -> 0315040507151206
alphabetcipher -> 0112160801020520030916080518
johncena -> 1015081403051401

Remember, this is code-golf, so the code with the fewest number of bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
encalp(const char *s, char *b)
{
	size_t i, j;
	int c;

	for (i = j = 0; (c = s[i]); i++) {
		if ('a' <= c && c <= 'z') {
			b[j++] = '0' + ((c - 'a' + 1) / 10);
			b[j++] = '0' + ((c - 'a' + 1) % 10);
		} else
			b[j++] = c;
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	encalp(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("helloworld", "08051212152315181204");
	test("codegolf", "0315040507151206");
	test("alphabetcipher", "0112160801020520030916080518");
	test("johncena", "1015081403051401");

	return 0;
}
