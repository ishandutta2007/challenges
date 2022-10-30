/*

Given an input string and a wrapping string, find the location of the first input string char in the wrapping string and replace it with the wrapping string char 1 step to the right of that,
find the second char in the wrapping string and replace it with the char 2 steps to the right, find the third and replace it with the char 3 steps to the right, and so on.
If there are not enough chars in the wrapping string, wrap around.

The wrapping string does not have duplicates and the input string will always be made of chars in the wrapping string.

Reference implementation
s, wrap = input(), input()
n = 1
res = ""
for char in s:
    res += wrap[(wrap.index(char) + n) % len(wrap)]
    n += 1

print(res)
Test Cases
abc abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ => bdf

xyz abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ => yAC

ZZZ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ => abc

<empty string> <empty string> => <empty string>

abcdefg abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ => bdfhjln

123 0123456789 => 246

121212 12 => 222222
Scoring
This is code golf, so the shortest answer wins!

code-golf

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
shift(const char *s, const char *w, char *b)
{
	size_t h[256];
	size_t i, n;
	int c;

	memset(h, 0, sizeof(h));
	for (n = 0; w[n]; n++) {
		c = w[n] & 0xff;
		if (!h[c])
			h[c] = n + 1;
	}

	for (i = 0; s[i]; i++) {
		c = s[i] & 0xff;
		if (h[c] == 0)
			b[i] = s[i];
		else
			b[i] = w[(h[c] + i) % n];
	}
	b[i] = '\0';
	return b;
}

void
test(const char *s, const char *w, const char *r)
{
	char b[128];

	shift(s, w, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("abc", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", "bdf");
	test("xyz", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", "yAC");
	test("ZZZ", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", "abc");
	test("", "", "");
	test("abcdefg", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", "bdfhjln");
	test("123", "0123456789", "246");
	test("121212", "12", "222222");

	return 0;
}
