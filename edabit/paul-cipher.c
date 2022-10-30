/*

In Paul Cipher, only alpha characters will be encoded with the following rules:

    All alpha characters will be treated as uppercase letters.
    The first alpha character will not change (except for switching to upper case).
    All subsequent alpha characters will be shifted toward "Z" by the alphabetical position of the previous alpha character (wrap back to "A" if "Z" is passed).

he1lo would be encoded as follows:

paulCipher("he1lo") ➞ "HM1QA"

h -> H (First character to be changed to uppercase)
e -> M (H is the previous alpha character and 8th letter in the alphabets. E + 8 = M)
1 -> 1 (Keep all characters other than alphabets as it is)
l -> Q (E is the previous alpha character and 5th letter in the alphabets. L + 5 = Q)
o -> A (L is the previous alpha character and 12th letter in the alphabets. O + 12 = A)

Given a string txt, return the encoded message. See the below examples for a better understanding:
Examples

paulCipher("muBas41r") ➞ "MHWCT41K"

paulCipher("a1rForce") ➞ "A1SXUGUH"

paulCipher("MATT") ➞ "MNUN"

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
paulcipher(const char *s, char *b)
{
	size_t i;
	int c, nc;

	c = -1;
	for (i = 0; (b[i] = toupper(s[i])); i++) {
		if (c < 0) {
			c = b[i] - 'A' + 1;
		} else if (isalpha(b[i])) {
			nc = b[i] - 'A' + 1;
			b[i] = 'A' + ((c + nc - 1) % 26);
			c = nc;
		}
	}

	return b;
}

void
test(const char *s, const char *t)
{
	char b[128];

	paulcipher(s, b);
	assert(!strcmp(b, t));
}

int
main(void)
{
	test("he1lo", "HM1QA");
	test("muBas41r", "MHWCT41K");
	test("a1rForce", "A1SXUGUH");
	test("A1rForce", "A1SXUGUH");
	test("p4K1St4n", "P4A1DM4H");
	test("MATT", "MNUN");
	test("4elen10ve", "4EQQS10JA");
	test("He1lo", "HM1QA");
	test(" The quick brown fox jumps over the lazy dog. ", " TBM VLDLN MTGLK TUM HEHCI HKAW LBM QMAY CSV. ");
	test("5ddc4ddf-7a47-44d3-8eda-3171860dc938", "5DHG4GHJ-7G47-44E3-8IIE-3171860EG938");
	test("", "");

	return 0;
}
