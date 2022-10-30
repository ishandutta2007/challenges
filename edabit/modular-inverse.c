/*

A positive integer multiplied times its inverse is always equal to 1: 17*(1/17)==1.
Modular arithmetic has a similar inverse function, although, for modulus m, we are confined to integers from 0 to m-1.
The modular multiplicative inverse of 3 modulus 5 is equal to 2 because (3*2)%5==1.
Another example: the modular inverse of 17 modulus 1000007 is equal to 58824 because (17*58824)%1000007==1.
The modular inverse, if it exists, must always be in the range 0 to m-1.

Create a function that has arguments integer n and modulus m. The function will return the modular inverse of n mod m. If the modular inverse does not exist, return false.

Examples

modInv(2, 3) ➞ 2

modInv(12, 47) ➞ 4

modInv(11, 33) ➞ false

modInv(55, 678) ➞ 37

modInv(81, 3455) ➞ 2346

Notes

    Some of the test cases have rather large integers, so if you attempt to do a brute force search of the entire modular field, you may not be successful due to the 12 second time limit imposed by the server.
	See Resources for a more efficient approach.
    The modular inverse of a number n modulus m exists only if n and m are coprime (i.e. they have no common factors other than 1).
    One practical use of modular inverse is in public-key cryptography like RSA where it can be used to determine the value of the private key.

*/

#include <assert.h>
#include <stdio.h>

// https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
long
modinv(long a, long b)
{
	long t, nt, nnt;
	long r, nr, nnr;
	long q;

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
main(void)
{
	assert(modinv(2, 3) == 2);
	assert(modinv(12, 47) == 4);
	assert(modinv(11, 33) == -1);
	assert(modinv(55, 678) == 37);
	assert(modinv(81, 3455) == 2346);
	assert(modinv(8, 21) == 8);
	assert(modinv(101, 678) == 47);
	assert(modinv(21, 36) == -1);
	assert(modinv(2791, 9497) == 1749);
	assert(modinv(234, 807652131L) == -1);
	assert(modinv(71, 134676521L) == 41730753L);

	return 0;
}
