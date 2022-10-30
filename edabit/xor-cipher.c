/*

In XOR Cipher, encoding is done by an XOR operation on two given strings.
If the strings are of different lengths then the output should be the length of the shorter string.
Cut the length of the longer string to the same size as the smaller string before XOR operation.

Given two strings of msg1 and msg2, return the encoded message.
Examples

XORCipher("11", "22") ➞ "33"
// 11 XOR 22 = 33

XORCipher("1020304", "403201") ➞ "501231"
XORCipher("c611d9bdd9de38b9eb", "23a0745505d4d25494") ➞ "e5b1ade8dc0aeaed7f"

Notes
A hint is in the Comments section.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char
xd(char c)
{
	if ('0' <= c && c <= '9')
		return c - '0';
	if ('a' <= c && c <= 'f')
		return c - 'a' + 10;
	if ('A' <= c && c <= 'F')
		return c - 'A' + 10;
	return c;
}

char
xdr(char c)
{
	if (0 <= c && c <= 9)
		return c + '0';
	if (10 <= c && c <= 15)
		return c - 10 + 'a';
	return c;
}

char *
xorcipher(const char *s, const char *t, char *b)
{
	size_t i;

	for (i = 0; s[i] && t[i]; i++)
		b[i] = xdr(xd(s[i]) ^ xd(t[i]));
	b[i] = '\0';
	return b;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	xorcipher(s, t, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("11", "22", "33");
	test("1020304", "403201", "501231");
	test("1c0111001f010100061a024b53535009181c", "686974207468652062756c6c277320657965", "746865206b696420646f6e277420706c6179");
	test("aadf", "bce2", "163d");
	test("ab3f", "ac", "07");
	test("", "", "");
	test("c611d9bdd9de38b9eb", "23a0745505d4d25494", "e5b1ade8dc0aeaed7f");
	test("7d1e875da9d5e89b54c7eaf", "3541599be591709795cebd5", "485fdec64c44980cc10957a");
	test("785a6677b3e52f0e7", "a8d97da7441", "d0831bd0f7f");
	test("6cbd75511e7f750c6827", "1753547c813bfcd", "7bee212d9f4489d");

	return 0;
}
