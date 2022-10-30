/*

Create a function that takes a string of ciphertext (English alphabet) all in lowercase, decryption function, and converts it into plain text using the affine decryption function.
Decryption Function

In the affine cipher, the letters of an alphabet of size m are first mapped to the integers in the range 0 … m − 1. It then uses modular arithmetic to transform the integer that each plaintext letter corresponds to into another integer that corresponds to a ciphertext letter. The decryption function for a single letter is E(x)=(ax+b)mod m where modulus m is the size of the alphabet and a and b are the keys of the cipher. The value a must be chosen such that a and m are coprime.

The decryption function is D(x)=a^(-1)*(x-b)mod m where a^(-1) is the modular multiplicative inverse of a modulo m ie a * a^(-1) mod m == 1. The multiplicative inverse of a only exists if a and m are coprime. Hence without the restriction on a, decryption might not be possible.

The alphabet is going to be the letters a through z and will have the corresponding values a=0, b=1, c=2, d=3 ... z=25.
Examples

test("ucncmrwt", "(x+2)%26") ➞ "salakpur"
// a = 1, b = 2, decryption = "(x+2)%26".
// Modular Multiplicative Inverse of 1 =  1.
// We apply the decryption function for the letters.

test("hezmrc", "(3x+4)%26") ➞ "bahuni"
// a = 3, b = 4, decryption = "(x+2)%26".
// Modular Multiplicative Inverse of 3 = 9.
// We apply the decryption function for the letters.

Notes

For the problem 1 =< a <= 11 , 1 =< b <= 9 , m = 26

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

int
modinv(int a, int b)
{
	int t, nt, nnt;
	int r, nr, nnr;
	int q;

	t = 0;
	r = b;
	nt = 1;
	nr = a;
	while (nr) {
		q = r / nr;
		nnt = t - q * nt;
		nnr = r - q * nr;

		t = nt;
		r = nr;
		nt = nnt;
		nr = nnr;
	}

	if (r > 1)
		return -1;
	if (t < 0)
		t += b;

	return t;
}

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

char *
decryptaffine(const char *s, const char *t, char *b)
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
			b[i] = mod((modinv(a, m) * (s[i] - 'a' - c)), m) + 'a';
	}
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	assert(decryptaffine(s, t, b));
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("hezmrc", "(3x+4)%26", "bahuni");
	test("ucncmrwt", "(x+2)%26", "salakpur");
	test("mvoadul", "(5x+7)%26", "birjung");
	test("ezabgobtba", "(3x+1)%26", "biratnagar");
	test("lpbifsv", "(7x+5)%26", "mustang");
	test("srnkdud", "(x+3)%26", "pokhara");
	test("lncorchaz", "(9x+2)%26", "bhaktapur");
	test("ejwjpsvo", "(11x+9)%26", "janakpur");
	test("ahcxcba", "(3x+2)%26", "itahari");
	test("ohofmapg", "(3x+7)%26", "lalitpur");

	return 0;
}
