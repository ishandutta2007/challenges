/*

Write a function that returns the longest sequence of consecutive zeroes in a binary string.

Examples

longestZero("01100001011000") ➞ "0000"

longestZero("100100100") ➞ "00"

longestZero("11111") ➞ ""

Notes

If no zeroes exist in the input, return an empty string.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
longestzero(const char *s, char *b)
{
	size_t i, n, m;

	for (i = m = 0; s[i];) {
		while (s[i] && s[i] != '0')
			i++;

		for (n = 0; s[i] && s[i] == '0'; n++)
			i++;

		if (m < n)
			m = n;
	}

	for (i = 0; i < m; i++)
		b[i] = '0';
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	longestzero(s, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("01100001011000", "0000");
	test("100100100", "00");
	test("111101", "0");
	test("1000000000011101", "0000000000");
	test("100001110000100000", "00000");
	test("101001101", "00");
	test("101010101", "0");
	test("1001001", "00");
	test("111111", "");

	return 0;
}
