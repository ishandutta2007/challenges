/*

The additive persistence of an integer, n, is the number of times you have to replace n with the sum of its digits until n becomes a single digit integer.

The multiplicative persistence of an integer, n, is the number of times you have to replace n with the product of its digits until n becomes a single digit integer.

Create two functions that take an integer as an argument and:

    Return its additive persistence.
    Return its multiplicative persistence.

Examples: Additive Persistence

additivePersistence(1679583) ➞ 3
// 1 + 6 + 7 + 9 + 5 + 8 + 3 = 39
// 3 + 9 = 12
// 1 + 2 = 3
// It takes 3 iterations to reach a single-digit number.

additivePersistence(123456) ➞ 2
// 1 + 2 + 3 + 4 + 5 + 6 = 21
// 2 + 1 = 3

additivePersistence(6) ➞ 0
// Because 6 is already a single-digit integer.

Examples: Multiplicative Persistence

multiplicativePersistence(77) ➞ 4
// 7 x 7 = 49
// 4 x 9 = 36
// 3 x 6 = 18
// 1 x 8 = 8
// It takes 4 iterations to reach a single-digit number.

multiplicativePersistence(123456) ➞ 2
// 1 x 2 x 3 x 4 x 5 x 6 = 720
// 7 x 2 x 0 = 0

multiplicativePersistence(4) ➞ 0
// Because 4 is already a single-digit integer.

Notes

The input n is never negative.

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;
typedef uvlong (*evalfn)(uvlong);

uvlong
sum(uvlong n)
{
	uvlong r;

	for (r = 0; n; n /= 10)
		r += n % 10;
	return r;
}

uvlong
product(uvlong n)
{
	uvlong r;

	if (n == 0)
		return 0;
	for (r = 1; n; n /= 10)
		r *= n % 10;
	return r;
}

uvlong
persistence(evalfn f, uvlong n)
{
	uvlong p;

	for (p = 0; n >= 10; p++)
		n = f(n);
	return p;
}

int
main(void)
{
	assert(persistence(sum, 1679583ull) == 3);
	assert(persistence(sum, 123456ull) == 2);
	assert(persistence(sum, 6ull) == 0);
	assert(persistence(sum, 5ull) == 0);
	assert(persistence(sum, 27ull) == 1);
	assert(persistence(sum, 58ull) == 2);
	assert(persistence(sum, 5789ull) == 3);

	assert(persistence(product, 77ull) == 4);
	assert(persistence(product, 123456ull) == 2);
	assert(persistence(product, 4ull) == 0);
	assert(persistence(product, 7ull) == 0);
	assert(persistence(product, 1234567890ull) == 1);
	assert(persistence(product, 39ull) == 3);
	assert(persistence(product, 6788ull) == 6);
	assert(persistence(product, 277777788888899ull) == 11);

	return 0;
}
