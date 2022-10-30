/*

Create a function that takes a number N and returns its Double Factorial.
Examples

doubleFactorial(0) ➞ [1]

doubleFactorial(2) ➞ [2]

doubleFactorial(9) ➞ [945]

doubleFactorial(14) ➞ [645120]

Notes

    Assume all input values are greater than or equal to -1.
    Try to solve it with recursion.

*/

#include <assert.h>
#include <inttypes.h>

intmax_t
dblfact(intmax_t n)
{
	if (n <= 1)
		return 1;
	return n * dblfact(n - 2);
}

int
main(void)
{
	assert(dblfact(-1) == INTMAX_C(1));
	assert(dblfact(0) == INTMAX_C(1));
	assert(dblfact(1) == INTMAX_C(1));
	assert(dblfact(2) == INTMAX_C(2));
	assert(dblfact(7) == INTMAX_C(105));
	assert(dblfact(9) == INTMAX_C(945));
	assert(dblfact(14) == INTMAX_C(645120));
	assert(dblfact(22) == INTMAX_C(81749606400));
	assert(dblfact(25) == INTMAX_C(7905853580625));
	assert(dblfact(27) == INTMAX_C(213458046676875));

	return 0;
}
