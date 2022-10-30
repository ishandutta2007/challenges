/*

Given any number, we can create a new number by adding the sums of squares of digits of that number.
For example, given 203, our new number is 4 + 0 + 9 = 13. If we repeat this process, we get a sequence of numbers:

203 -> 13 -> 10 -> 1 -> 1

Sometimes, like with 203, the sequence reaches (and stays at) 1. Numbers like this are called happy.

Not all numbers are happy. If we started with 11, the sequence would be:

11 -> 2 -> 4 -> 16 -> ...

This sequence will never reach 1, and so the number 11 is called unhappy.

Given a positive whole number, you have to determine whether that number is happy or unhappy.

Examples

happy(203) ➞ true

happy(11) ➞ false

happy(107) ➞ false

Notes

    You can assume (and it is actually true!) that all positive whole numbers are either happy or unhappy. Any happy number will have a 1 in its sequence, and every unhappy number will have a 4 in its sequence.
    The only numbers passed to your function will be positive whole numbers.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

bool
happy(unsigned n)
{
	unsigned u, v;

	for (;;) {
		v = 0;
		do {
			u = n % 10;
			v += u * u;
		} while (n /= 10);

		if (v == 0 || v == 4)
			return false;

		if (v == 1)
			return true;

		n = v;
	}
}

int
main(void)
{
	assert(happy(203) == true);
	assert(happy(11) == false);
	assert(happy(100) == true);
	assert(happy(101) == false);
	assert(happy(102) == false);
	assert(happy(103) == true);
	assert(happy(104) == false);
	assert(happy(105) == false);
	assert(happy(106) == false);
	assert(happy(107) == false);
	assert(happy(108) == false);
	assert(happy(109) == true);
	assert(happy(110) == false);
	assert(happy(UINT_MAX) == false);
	assert(happy(4000) == false);

	return 0;
}
