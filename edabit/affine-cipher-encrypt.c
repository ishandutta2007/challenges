/*

Create a function that takes a string of plain text (English alphabet) all in lowercase, encryption function, and converts the plain text into ciphertext using the affine encryption function.
Encryption Function

In the affine cipher, the letters of an alphabet of size m are first mapped to the integers in the range 0 … m − 1.
It then uses modular arithmetic to transform the integer that each plaintext letter corresponds to into another integer that corresponds to a ciphertext letter.

The encryption function for a single letter is E(x)=(ax+b)mod m where modulus m is the size of the alphabet and a and b are the keys of the cipher. The value a must be chosen such that a and m are coprime.

The alphabet is going to be the letters a through z and will have the corresponding values a=0, b=1, c=2, d=3 ... z=25.
Examples

affineEncrypt("salakpur", "(x+2)%26") ➞ "ucncmrwt"
// a = 1 , b = 2
// Encryption function = "(x+2)%26"
// gcd(1, 26) = 1
// Therefore, we apply the encryption function for the letters.

affineEncrypt("dang", "(2x+7)%26") ➞ "2 and 26 are not coprime"
// a = 2, b = 7
// gcd(2, 26) = 2

Notes

    For the problem 1 =< a <= 11 , 1 =< b <= 9 , m = 26
    Create your own gcd function.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

unsigned
gcd(unsigned a, unsigned b)
{
	unsigned t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

char *
encryptaffine(const char *s, const char *t, char *b)
{
	unsigned a, c, m;
	size_t i;
	int n;

	a = 1;
	c = m = 0;

	n = sscanf(t, "(x+%u)%%%u", &c, &m);
	if (n != 2)
		n = sscanf(t, "(%ux+%u)%%%u", &a, &c, &m);
	if ((n != 2 && n != 3) || m == 0)
		return NULL;

	if (gcd(a, m) != 1) {
		sprintf(b, "%u and %u are not coprime", a, m);
		return b;
	}

	for (i = 0; s[i]; i++) {
		b[i] = s[i];
		if ('a' <= s[i] && s[i] <= 'z')
			b[i] = ((a * (s[i] - 'a') + c) % m) + 'a';
	}
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	assert(encryptaffine(s, t, b));
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("salakpur", "(x+2)%26", "ucncmrwt");
	test("birjung", "(5x+7)%26", "mvoadul");
	test("dang", "(2x+7)%26", "2 and 26 are not coprime");
	test("biratnagar", "(3x+1)%26", "ezabgobtba");
	test("mustang", "(7x+5)%26", "lpbifsv");
	test("kathmandu", "(6x+8)%26", "6 and 26 are not coprime");
	test("pokhara", "(x+3)%26", "srnkdud");
	test("bhaktapur", "(9x+2)%26", "lncorchaz");
	test("janakpur", "(11x+9)%26", "ejwjpsvo");
	test("janakpur", "(10x+5)%26", "10 and 26 are not coprime");
	test("itahari", "(3x+2)%26", "ahcxcba");
	test("lalitpur", "(4x+7)%26", "4 and 26 are not coprime");

	return 0;
}
