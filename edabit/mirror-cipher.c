/*

In Mirror Cipher, encoding is done by by switching message characters with its mirror opposite character of the key.

Create a function that takes two arguments; a message and an optional key, and returns the encoded message.

There are some variations on the rules of encipherment. One version of the cipher rules are outlined below:

message = "Mubashir Hassan"
key = "edabitisamazing"

mirrorCipher(message, key) ➞ "tuzishar hissid"

Step 1: Replace all characters of given message with mirror character in the key:

M = t, // 't' is mirror character of 'M'
u = u, // 'u' is not part of the key
b = z, // 'z' is mirror character of 'b'
a = i, and so on ...

Step 2: Return encoded message in lower case:

"tuzishar hissid"

If optional key is not given, consider the whole alphabet as a default (i.e. key = "abc..z").
Examples

mirrorCipher("Mubashir Hassan", "edabitisamazing") ➞ "tuzishar hissid"

mirrorCipher("Matt MacPherson") ➞ "nzgg nzxksvihlm"

mirrorCipher("Airforce is best", "pilot") ➞ "aorfirce os besp"

Notes

Ignore case of message and key, (e.g. "M" = "m").

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
mktable(int tab[256], const char *k)
{
	static const char defkey[] = "abcdefghijklmnopqrstuvwxyz";
	static const size_t defkeylen = sizeof(defkey) - 1;

	size_t i, j, n;

	if (k == NULL) {
		k = defkey;
		n = defkeylen;
	} else
		n = strlen(k);

	if (n == 0) {
		for (i = 0; i < 256; i++)
			tab[i] = i;
		return;
	}

	memset(tab, 0, sizeof(*tab) * 256);
	i = 0;
	j = n;
	while (i <= j) {
		tab[k[i] & 0xff] = k[j - 1];
		tab[k[j - 1] & 0xff] = k[i];
		i++;
		j--;
	}
}

char *
mirrorcrypt(const char *s, const char *k, char *b)
{
	int tab[256], c;
	size_t i;

	mktable(tab, k);
	for (i = 0; s[i]; i++) {
		c = s[i] & 0xff;
		if (isupper(c))
			c = tolower(c);

		b[i] = (tab[c]) ? tab[c] : c;
	}
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *k, const char *r)
{
	char b[128];

	mirrorcrypt(s, k, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Mubashir Hassan", "edabitisamazing", "tuzishar hissid");
	test("Matt MacPherson", NULL, "nzgg nzxksvihlm");
	test("Airforce is best", "pilot", "aorfirce os besp");
	test("hello", NULL, "svool");
	test("goodbye", NULL, "tllwybv");
	test("ngmlsoor", NULL, "mtnohlli");
	test("gsrh rh z hvxivg", NULL, "this is a secret");
	test("hello", "abcdefgh", "adllo");
	test("goodbye", "", "goodbye");
	test("this is a secret", " *", "this*is*a*secret");

	return 0;
}
