/*

An uninteresting number (which I totally didn't make up only for this challenge) is created like this:

Take a positive integer N
Create a new number O by adding the digits of N at the end of N
The final uninteresting number is O*N
For example for N=12:

O = 1212
O*N = 1212 * 12
Final number is 14544
Input
A positive integer N (N > 0) or your language's equivalent. You don't have to catch incorrect input.

Output
The corresponding uninteresting number.

Test cases
  1 -> 11
  2 -> 44
  3 -> 99
 10 -> 10100
174 -> 30306276

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
shift10(uvlong n)
{
	uvlong p;

	p = 1;
	do {
		p *= 10;
	} while (n /= 10);

	return p;
}

uvlong
uninterest(uvlong n)
{
	return ((n * shift10(n)) + n) * n;
}

int
main(void)
{
	assert(uninterest(0) == 0);
	assert(uninterest(1) == 11);
	assert(uninterest(2) == 44);
	assert(uninterest(3) == 99);
	assert(uninterest(10) == 10100);
	assert(uninterest(12) == 14544);
	assert(uninterest(174) == 30306276ULL);

	return 0;
}
