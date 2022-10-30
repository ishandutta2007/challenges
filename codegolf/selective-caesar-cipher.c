/*

Input
A string of text.

Output
The string of text, however, every consonant is the next consonant in the alphabet, and every vowel is the next vowel in the alphabet (z becomes b, u becomes a).
The case of the new letter should be the same as the letter it is replacing (a becomes e, A becomes E). If there are two consonants in a row, they will be separated by the characters 'ei', the case of 'ei' can be whatever you please.
Characters outside of the 26 character Latin alphabet should remain unchanged. This includes whitespace and punctuation.

(For clarity, the vowels are aeiou. Y is not considered a vowel)

Examples: The phrase "Hello World" becomes "Jimeimu Xuseimeif" The phrase "codegolf" becomes "dufihumeig"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
next(const char *a, size_t n, int c)
{
	char *p;
	int r;

	p = strchr(a, tolower(c));
	if (!p)
		return -1;

	r = a[(p - a + 1) % n];
	if (isupper(c))
		r = toupper(r);
	return r;
}

char *
encode(const char *s, char *b)
{
	static const char consonant[] = "bcdfghjklmnpqrstvwxyz";
	static const char vowel[] = "aeiou";

	size_t i, j;
	int c, n;

	n = 0;
	for (i = j = 0; s[i]; i++) {
		c = next(consonant, nelem(consonant), s[i]);
		if (c >= 0) {
			if (++n >= 2) {
				b[j++] = 'e';
				b[j++] = 'i';
				n = 1;
			}
		} else {
			c = next(vowel, nelem(vowel), s[i]);
			n = 0;
		}

		if (c < 0)
			c = s[i];

		b[j++] = c;
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	encode(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Hello World", "Jimeimu Xuseimeif");
	test("codegolf", "dufihumeig");
	test("bcc", "ceideid");

	return 0;
}
