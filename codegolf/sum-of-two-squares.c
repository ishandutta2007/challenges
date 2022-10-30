/*

Given a nonnegative integer n, determine whether n can be expressed as the sum of two square numbers, that is ∃a,b∈Z such that n=a2+b2.

   0 -> truthy
   1 -> truthy
   2 -> truthy
   3 -> falsy
   4 -> truthy
   5 -> truthy
   6 -> falsy
   7 -> falsy
  11 -> falsy
9997 -> truthy
9999 -> falsy
Relevant OEIS sequences:

A001481 - should return truthy
A022544 - should return falsy
This is code-golf, so shortest answer as measured in bytes wins.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
twosquares(int n)
{
	int a, b;

	for (a = 0; a * a <= n; a++) {
		for (b = 0; b * b <= n; b++) {
			if ((a * a) + (b * b) == n)
				return true;
		}
	}
	return false;
}

int
main(void)
{
	assert(twosquares(0) == true);
	assert(twosquares(1) == true);
	assert(twosquares(2) == true);
	assert(twosquares(3) == false);
	assert(twosquares(4) == true);
	assert(twosquares(5) == true);
	assert(twosquares(6) == false);
	assert(twosquares(7) == false);
	assert(twosquares(11) == false);
	assert(twosquares(9997) == true);
	assert(twosquares(9999) == false);

	assert(twosquares(137) == true);
	assert(twosquares(157) == true);
	assert(twosquares(160) == true);

	assert(twosquares(134) == false);
	assert(twosquares(198) == false);
	assert(twosquares(199) == false);

	return 0;
}
