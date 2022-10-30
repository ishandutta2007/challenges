/*

A field in mathematics is a set of numbers, with addition and multiplication operations defined on it, such that they satisfy certain axioms (described in Wikipedia; see also below).

A finite field can have pn elements, where p is a prime number, and n is a natural number. In this challenge, let's take p = 2 and n = 8, so let's make a field with 256 elements.

The elements of the field should be consecutive integers in a range that contains 0 and 1:

-128 ... 127
0 ... 255
or any other such range
Define two functions (or programs, if that is easier), a(x,y) for abstract "addition", and m(x,y) for abstract "multiplication", such that they satisfy the field axioms:

Consistency: a(x,y) and m(x,y) produce the same result when called with same arguments
Closedness: The result of a and m is an integer in the relevant range
Associativity: for any x, y and z in the range, a(a(x,y),z) is equal to a(x,a(y,z)); the same for m
Commutativity: for any x and y in the range, a(x,y) is equal to a(y,x); the same for m
Distributivity: for any x, y and z in the range, m(x,a(y,z)) is equal to a(m(x,y),m(x,z))
Neutral elements: for any x in the range, a(0,x) is equal to x, and m(1,x) is equal to x
Negation: for any x in the range, there exists such y that a(x,y) is 0
Inverse: for any x≠0 in the range, there exists such y that m(x,y) is 1
The names a and m are just examples; you can use other names, or unnamed functions. The score of your answer is the sum of byte-lengths for a and m.

If you use a built-in function, please also describe in words which result it produces (e.g. provide a multiplication table).

*/

#include <assert.h>
#include <stdio.h>

int
add(int x, int y)
{
	return x ^ y;
}

int
mul(int x, int y)
{
	int p;
	int z;

	p = 0x11d;
	z = 0;
	while (x > 0) {
		if (x & 1)
			z ^= y;
		x >>= 1;
		y <<= 1;
		if (y & 0x100)
			y ^= p;
	}
	return z;
}

int
neg(int x)
{
	return x;
}

int
inv(int x)
{
	int y;

	if (x == 0)
		return 0;

	for (y = 1; y < 256; y++) {
		if (mul(x, y) == 1)
			return y;
	}
	return -1;
}

void
closedness(void)
{
	int x, y, z;
	int n;

	n = 256;
	for (x = 0; x < n; x++) {
		for (y = 0; y < n; y++) {
			z = add(x, y);
			assert(0 <= z && z < n);

			z = mul(x, y);
			assert(0 <= z && z < n);
		}
	}
}

void
associativity(void)
{
	int x, y, z;
	int n;

	n = 256;
	for (x = 0; x < n; x++) {
		for (y = 0; y < n; y++) {
			for (z = 0; z < n; z++) {
				assert(add(add(x, y), z) == add(x, add(y, z)));
				assert(mul(mul(x, y), z) == mul(x, mul(y, z)));
			}
		}
	}
}

void
commutativity(void)
{
	int x, y;
	int n;

	n = 256;
	for (x = 0; x < n; x++) {
		for (y = 0; y < n; y++) {
			assert(add(x, y) == add(y, x));
			assert(mul(x, y) == mul(y, x));
		}
	}
}

void
distributivity(void)
{
	int x, y, z;
	int n;

	n = 256;
	for (x = 0; x < n; x++) {
		for (y = 0; y < n; y++) {
			for (z = 0; z < n; z++) {
				assert(mul(x, add(y, z)) == add(mul(x, y), mul(x, z)));
			}
		}
	}
}

void
neutral(void)
{
	int x;
	int n;

	n = 256;
	for (x = 0; x < n; x++) {
		assert(add(0, x) == x);
		assert(mul(1, x) == x);
	}
}

void
negation(void)
{
	int x;
	int n;

	n = 256;
	for (x = 0; x < n; x++) {
		assert(add(x, neg(x)) == 0);
	}
}

void
inverse(void)
{
	int x;
	int n;

	n = 256;
	for (x = 1; x < n; x++) {
		assert(mul(x, inv(x)) == 1);
	}
}

// https://research.swtch.com/field
void
verify(void)
{
	closedness();
	associativity();
	commutativity();
	distributivity();
	neutral();
	negation();
	inverse();
}

int
main(void)
{
	verify();

	return 0;
}
