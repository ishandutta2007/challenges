/*

A Keyword Cipher is a monoalphabetic cipher that uses a keyword to provide encryption on the given string of the message.

Create a function that takes two arguments: a string message and a string key, and returns an encoded message.

For the encryption key, the keyword is placed at the beginning, followed by the rest of the characters in the alphabet in order (in other words, with the keyword characters removed):

A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z
K|E|Y|W|O|R|D|A|B|C|F|G|H|I|J|L|M|N|P|Q|S|T|U|V|X|Z

The encrypted message substitutes each plaintext character with the encryption key character in the corresponding position.

Return the given message encrypted against the key:

message = "ABCHIJ"
key = "KEYWORD"

keywordCipher(key, message) ➞ "KEYABC"
// A = K, B = E, C = Y, H = A, I = B, J = C

Examples

keywordCipher("keyword", "abchij") ➞ "keyabc"

keywordCipher("purplepineapple", "abc") ➞ "pur"

keywordCipher("mubashir", "edabit") ➞ "samucq"

Notes

    Don't forget to remove duplicates after concatenating the string with the keyword.
    Non-alphabetic characters must be left as they are.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
gentab(int tab[256], const char *k)
{
	int a, b, h[256];
	size_t i, j;

	memset(h, 0, sizeof(h));
	for (i = 0; i < 256; i++)
		tab[i] = i;

	for (i = j = 0; k[i] && j < 26; i++) {
		if (!isalpha(k[i]))
			continue;

		a = tolower(k[i]) & 0xff;
		b = toupper(k[i]) & 0xff;
		if (h[a] || h[b])
			continue;
		h[a] = h[b] = 1;

		tab['a' + j] = a;
		tab['A' + j] = b;
		j++;
	}

	for (i = 0; i < 26 && j < 26; i++) {
		if (!h['a' + i]) {
			tab['a' + j] = 'a' + i;
			tab['A' + j] = 'A' + i;
			j++;
		}
	}
}

char *
kwcrypt(const char *k, const char *s, char *b)
{
	int tab[256];
	size_t i;

	gentab(tab, k);
	for (i = 0; s[i]; i++)
		b[i] = tab[s[i] & 0xff];
	b[i] = '\0';
	return b;
}

void
test(const char *k, const char *s, const char *r)
{
	char b[128];

	kwcrypt(k, s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("keyword", "abc", "key");
	test("keyword", "xyz", "vxz");
	test("keyword", "aeiou", "kobjs");
	test("purplepineapple", "abc", "pur");
	test("purplepineapple", "xyz", "xyz");
	test("purplepineapple", "aeiou", "pebjt");
	test("etaoinshrdlucmfwypvbgkjqxz", "abc", "eta");
	test("etaoinshrdlucmfwypvbgkjqxz", "xyz", "qxz");
	test("etaoinshrdlucmfwypvbgkjqxz", "aeiou", "eirfg");
	test("tfozcivbsjhengarudlkpwqxmy", "abc", "tfo");
	test("tfozcivbsjhengarudlkpwqxmy", "tjuukf", "kjpphi");
	test("tfozcivbsjhengarudlkpwqxmy", "ajqqtb", "tjuukf");
	test("tfozcivbsjhengarudlkpwqxmy", "a_bc&*83", "t_fo&*83");
	test("mubashir", "pakistan", "lmecpqmj");
	test("mubashir", "edabit", "samucq");

	return 0;
}
