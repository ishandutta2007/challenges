/*

Challenge

Given a number A, find the smallest possible value of B+C, if B*C = A. Here A, B, and C must all be positive integers. It's okay to use brute force by checking every possible value of B and C.
You don't need to handle inputs larger than six digits. Post the return value for A = 345678 along with your solution.

For instance, given A = 12345 you should return 838. Here's why. There are four different ways to represent 12345 as the product of two positive integers:

12345 = 1*12345
12345 = 3*4115
12345 = 5*2469
12345 = 15*823

The sum of the two factors in each case is:

1*12345 => 1+12345 = 12346
3*4115 => 3+4115 = 4118
5*2469 => 5+2469 = 2474
15*823 => 15+823 = 838

The smallest sum of a pair of factors in this case is 838.
Examples

12 => 7
456 => 43
4567 => 4568
12345 => 838

The corresponding products are 12 = 3*4, 456 = 19*24, 4567 = 1*4567, and 12345 = 15*823.
Hint

Want to test whether one number divides evenly into another? This is most commonly done with the modulus operator (usually %), which gives you the remainder when you divide one number by another.
If the modulus is 0, then there's no remainder and the numbers divide evenly. For instance, 12345 % 5 is 0, because 5 divides evenly into 12345.
Optional bonus 1

Handle larger inputs efficiently. You should be able to handle up to 12 digits or so in about a second (maybe a little longer depending on your programming language). Find the return value for 1234567891011.

Hint: how do you know when you can stop checking factors?
Optional bonus 2

Efficiently handle very large inputs whose prime factorization you are given. For instance, you should be able to get the answer for 6789101112131415161718192021 given that its prime factorization is:

6789101112131415161718192021 = 3*3*3*53*79*1667*20441*19646663*89705489

In this case, you can assume you're given a list of primes instead of the number itself. (To check your solution, the output for this input ends in 22.)

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

typedef unsigned long long uvlong;

uvlong
integer(uvlong a)
{
	uvlong b, c, r;

	r = ULLONG_MAX;
	for (b = 0; b <= a; b++) {
		for (c = 0; c <= a; c++) {
			if (b * c > a)
				break;

			if (b * c == a && r > b + c)
				r = b + c;
		}
	}
	return r;
}

int
main(void)
{
	assert(integer(12ull) == 7ull);
	assert(integer(456ull) == 43ull);
	assert(integer(4567ull) == 4568ull);
	assert(integer(12345ull) == 838ull);
	assert(integer(345678ull) == 3491ull);

	return 0;
}
