/*

A pronic number (or otherwise called as heteromecic) is a number which is a product of two consecutive integers,
that is, a number of the form n(n + 1). Create a function that determines whether a number is pronic or not.

Examples

isHeteromecic(0) ➞ true
// 0 * (0 + 1) = 0 * 1 = 0

isHeteromecic(2) ➞ true
// 1 * (1 + 1) = 1 * 2 = 2

isHeteromecic(7) ➞ false

isHeteromecic(110) ➞ true
// 10 * (10 + 1) = 10 * 11 = 110

isHeteromecic(136) ➞ false

isHeteromecic(156) ➞ true

Notes

    You are expected to solve this challenge via recursion.
    You can check on the Resources tab for more details about recursion.
    A non-recursive version of this challenge can be found here.
    If you find recursion to be fun, a collection of those challenges is found here.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
isheteromecic(unsigned n)
{
	unsigned r;

	r = sqrt(n);
	return r * (r + 1) == n;
}

int
main(void)
{
	static const unsigned itab[] = {
	    0,
	    2,
	    7,
	    110,
	    136,
	    156,
	    182,
	    218,
	    250,
	    272,
	    306,
	    362,
	    380,
	    422,
	    462,
	    600,
	};
	static const bool btab[] = {
	    true,
	    true,
	    false,
	    true,
	    false,
	    true,
	    true,
	    false,
	    false,
	    true,
	    true,
	    false,
	    true,
	    false,
	    true,
	    true,
	};

	size_t i;

	for (i = 0; i < nelem(itab); i++)
		assert(isheteromecic(itab[i]) == btab[i]);

	return 0;
}
