/*

Given a lower case string. Ex:

s = 'abcdefghijklmnopqrstuvwxyz'
The goal is to make every other vowel uppercase.

Desired output here:

abcdEfghijklmnOpqrstuvwxyz
As you can see, from aeiou, ‘e‘ and ‘o‘ get uppercased.

For aeiou, the desired output is:

aEiOu
There are only lowercase characters in the strings in all cases.

This is code-golf, so shortest code in bytes wins.

P.S. The vowels are aeiou

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
eovu(const char *s, char *b)
{
	size_t i, j, k;
	int c;

	for (i = j = k = 0; s[i]; i++) {
		c = s[i] & 0xff;
		if (strchr("aeiou", tolower(c)))
			c = (k++ & 1) ? toupper(c) : tolower(c);
		b[j++] = c;
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	eovu(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("abcdefghijklmnopqrstuvwxyz", "abcdEfghijklmnOpqrstuvwxyz");
	test("aeiou", "aEiOu");
	test("AEIOU", "aEiOu");

	return 0;
}
