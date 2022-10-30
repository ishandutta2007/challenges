/*

We define the function g as g(n) = n XOR (n * 2) for any integer n > 0.

Given x > 0, find the smallest integer y > 0 such that gk(y) = x for some k > 0.

Example
x = 549

549 = 483 XOR (483 * 2)     (as binary: 1000100101 = 111100011 XOR 1111000110)
483 = 161 XOR (161 * 2)     (as binary:  111100011 =  10100001 XOR  101000010)
Which means that g2(161) = 549. We can't go any further, as there is no n such that g(n) = 161. So, the expected output for x = 549 is y = 161.

Rules
You are not supposed to support invalid entries. A pair (y, k) is guaranteed to exist for the input value x.
This is code-golf, so the shortest answer in bytes wins!
Test cases
     3 -->     1
     5 -->     1
     6 -->     2
     9 -->     7
    10 -->     2
    23 -->    13
    85 -->     1
   549 -->   161
   960 -->    64
  1023 -->   341
  1155 -->   213
  1542 -->     2
  9999 -->  2819
 57308 --> 19124
 57311 -->   223
983055 -->     1

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
value(uvlong x)
{
	uvlong y;

loop:
	for (y = 1; y < x; y++) {
		if ((y ^ (y << 1)) == x) {
			x = y;
			goto loop;
		}
	}
	return x;
}

int
main(void)
{
	assert(value(3) == 1);
	assert(value(5) == 1);
	assert(value(6) == 2);
	assert(value(9) == 7);
	assert(value(10) == 2);
	assert(value(23) == 13);
	assert(value(85) == 1);
	assert(value(549) == 161);
	assert(value(960) == 64);
	assert(value(1023) == 341);
	assert(value(1155) == 213);
	assert(value(1542) == 2);
	assert(value(9999) == 2819);
	assert(value(1023) == 341);
	assert(value(57308ULL) == 19124ULL);
	assert(value(57311ULL) == 223);
	assert(value(983055ULL) == 1);

	return 0;
}
