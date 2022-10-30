/*

Consider a sequence where the first two numbers are 0 and 1 and the next number of the sequence is the sum of the previous two numbers modulo three.

Create a function that finds the nth element of the sequence.

Examples

normal_sequence(1) ➞ 0

normal_sequence(2) ➞ 1

normal_sequence(3) ➞ 1

normal_sequence(20) ➞ 2

Notes

    1 ≤ N ≤ 10^19
    A hint in comments section.

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

// https://oeis.org/A082115
uvlong
normal(uvlong n)
{
	static const uvlong fib[] = {
	    0,
	    1,
	    1,
	    2,
	    3,
	    5,
	    8,
	    13,
	};

	return (n) ? fib[(n - 1) & 7] % 3 : 0;
}

int
main(void)
{
	assert(normal(1) == 0);
	assert(normal(2) == 1);
	assert(normal(3) == 1);
	assert(normal(20) == 2);
	assert(normal(8) == 1);
	assert(normal(41) == 0);
	assert(normal(48) == 1);
	assert(normal(148) == 2);
	assert(normal(163) == 1);
	assert(normal(111) == 2);
	assert(normal(118) == 2);
	assert(normal(117) == 0);
	assert(normal(90) == 1);
	assert(normal(91) == 1);
	assert(normal(95) == 2);
	assert(normal(87) == 2);
	assert(normal(85) == 0);
	assert(normal(82) == 1);
	assert(normal(71) == 2);
	assert(normal(72) == 1);
	assert(normal(51013947783ull) == 2);

	return 0;
}
