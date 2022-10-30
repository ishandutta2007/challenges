/*

Write a function that accepts a string and an n and returns a cipher by rolling each character forward (n > 0) or backward (n < 0) n times.

Note: Think of the letters as a connected loop, so rolling a backwards once will yield z, and rolling z forward once will yield a. If you roll 26 times in either direction, you should end up back where you started.
Examples

RollingCipher("abcd", 1) ➞ "bcde"

RollingCipher("abcd", -1) ➞ "zabc"

RollingCipher("abcd", 3) ➞ "defg"

RollingCipher("abcd", 26) ➞ "abcd"

Notes

    All letters are lower cased.
    No spacing.
    Each character is rotated the same number of times.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
rollingcipher(const char *s, int n, char *b)
{
	size_t i;
	int c;

	for (i = 0; s[i]; i++) {
		c = s[i];
		if ('a' <= c && c <= 'z') {
			c = (c - 'a' + n) % 26;
			if (c < 0)
				c += 26;
			c += 'a';
		}
		b[i] = c;
	}
	b[i] = '\0';
	return b;
}

void
test(const char *s, int n, const char *t)
{
	char b[80];

	rollingcipher(s, n, b);
	assert(!strcmp(b, t));
}

int
main(void)
{
	test("abcd", 1, "bcde");
	test("abcd", -1, "zabc");
	test("abcd", 3, "defg");
	test("abcd", 25, "zabc");
	test("abcd", 26, "abcd");
	test("abcd", 27, "bcde");
	test("abcd", 0, "abcd");

	return 0;
}
