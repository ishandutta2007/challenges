/*

In Salesforce CRM, every object has 15-character alphanumeric ID, which is case-sensitive.
If anyone's curious, actually it's base-62 number. However, tools used for data migration and integration may or may not support case sensitivity.
To overcome that, IDs can be safely converted to 18-character case-insensitive alphanumeric IDs. In that process 3-character alphanumeric checksum is appended to the ID.

The conversion algorithm is:

Example:

a0RE000000IJmcN
Split ID into three 5-character chunks.

a0RE0  00000  IJmcN
Reverse each chunk.

0ER0a  00000  NcmJI
Replace each character in every chunk by 1 if it's uppercase or by 0 if otherwise.

01100  00000  10011
For each 5-digit binary number i, get character at position i in concatenation of uppercase alphabet and digits 0-5 (ABCDEFGHIJKLMNOPQRSTUVWXYZ012345).

00000 -> A,
00001 -> B,
00010 -> C, ...,
11010 -> Z,
11011 -> 0, ...,
11111 -> 5`
Yielding:

M  A  T
Append these characters, the checksum, to the original ID.

Output:

a0RE000000IJmcNMAT
Write program or function which takes 15-character alphanumeric (ASCII) string as input and returns 18-character ID.

Input validation is out of scope of this question. Programs may return any value or crash on invalid input.

Please, don't use Salesforce propretiary languages' features that make this challenge trivial (such as formula CASESAFEID(), converting Id to String in APEX &c).

Test Cases
a01M00000062mPg    -> a01M00000062mPgIAI
001M000000qfPyS    -> 001M000000qfPySIAU
a0FE000000D6r3F    -> a0FE000000D6r3FMAR
0F9E000000092w2    -> 0F9E000000092w2KAA
aaaaaaaaaaaaaaa    -> aaaaaaaaaaaaaaaAAA
AbCdEfGhIjKlMnO    -> AbCdEfGhIjKlMnOVKV
aBcDEfgHIJKLMNO    -> aBcDEfgHIJKLMNO025

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

size_t
csum(const char *s, int *c)
{
	size_t i;

	*c = 0;
	for (i = 0; s[i] && i < 5; i++) {
		if (isupper(s[i]))
			*c |= 1 << i;
	}
	return i;
}

char *
conv(const char *s, char *b)
{
	static const char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ012345";

	size_t i, j;
	int c;

	for (i = j = 0; s[i];) {
		i += csum(s + i, &c);
		b[j++] = alphabet[c];
	}

	memmove(b + i, b, j);
	memmove(b, s, i);
	b[i + j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	conv(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("a0RE000000IJmcN", "a0RE000000IJmcNMAT");
	test("a01M00000062mPg", "a01M00000062mPgIAI");
	test("001M000000qfPyS", "001M000000qfPySIAU");
	test("a0FE000000D6r3F", "a0FE000000D6r3FMAR");
	test("0F9E000000092w2", "0F9E000000092w2KAA");
	test("aaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaAAA");
	test("AbCdEfGhIjKlMnO", "AbCdEfGhIjKlMnOVKV");
	test("aBcDEfgHIJKLMNO", "aBcDEfgHIJKLMNO025");

	return 0;
}
