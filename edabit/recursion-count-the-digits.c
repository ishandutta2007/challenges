/*

Create a function that will recursively count the number of digits of a number.
Conversion of the number to a string is not allowed, thus, the approach is recursive.

Examples

digitsCount(4666) ➞ 4

digitsCount(544) ➞ 3

digitsCount(121317) ➞ 6

digitsCount(0) ➞ 1

digitsCount(12345) ➞ 5

digitsCount(1289396387328L) ➞ 13

Notes

All inputs are integers but some are in exponential form, deal with it accordingly.
You are expected to come up with a solution using the concept of recursion or the so-called recursive approach.
Check out the Resources for more topics about recursion to read on
(if you aren't familiar with it yet or haven't fully understood the concept behind it before taking up this challenge or unless otherwise).
An iterative version of this challenge can be found via this link.
A collection of challenges alike can be found via this link.

*/

#include <assert.h>
#include <stdio.h>
#include <inttypes.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
digitsrec(intmax_t n)
{
	return (n) ? (1 + digitsrec(n / 10)) : 0;
}

int
digits(intmax_t n)
{
	return 1 + digitsrec(n / 10);
}

int
main(void)
{
	static const intmax_t in[] = {
	    INTMAX_C(0),
	    INTMAX_C(4666),
	    INTMAX_C(544),
	    INTMAX_C(121317),
	    INTMAX_C(12345),
	    INTMAX_C(1289396387328),
	    INTMAX_C(-1232323),
	    INTMAX_C(3463463874638476),
	    INTMAX_C(-231.2e6),
	    INTMAX_C(1283939312321),
	    INTMAX_C(-231273683),
	    INTMAX_C(3.2e6),
	    INTMAX_C(314890e3),
	};
	static const int out[] = {
	    1,
	    4,
	    3,
	    6,
	    5,
	    13,
	    7,
	    16,
	    9,
	    13,
	    9,
	    7,
	    9,
	};

	size_t i;

	for (i = 0; i < nelem(in); i++)
		assert(digits(in[i]) == out[i]);

	return 0;
}
