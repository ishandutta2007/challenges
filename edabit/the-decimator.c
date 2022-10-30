/*

Write a DECIMATOR function which takes a string and decimates it (i.e. it removes the last 1/10 of the characters).

Always round up: if the string has 21 characters, 1/10 of the characters would be 2.1 characters, hence the DECIMATOR removes 3 characters. The DECIMATOR shows no mercy!

Examples

DECIMATOR("1234567890") ➞ "123456789"
// 10 characters, removed 1.

DECIMATOR("1234567890AB") ➞ "1234567890"
// 12 characters, removed 2.

DECIMATOR("123") ➞ "12"
// 3 characters, removed 1.

DECIMATOR("123456789012345678901") ➞ "123456789012345678"
// 21 characters, removed 3.

Notes

Make sure to remove characters from the end of the string.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *
decimator(const char *s, char *b)
{
	size_t i, n, m;

	n = strlen(s);
	m = ceil(0.1 * n);
	for (i = 0; i < n - m; i++)
		b[i] = s[i];
	b[i] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	decimator(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("1234567890", "123456789");
	test("1234567890AB", "1234567890");
	test("123", "12");
	test("123456789012345678901", "123456789012345678");
	test("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVW");
	test("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrst");
	test("A", "");
	test("", "");

	return 0;
}
