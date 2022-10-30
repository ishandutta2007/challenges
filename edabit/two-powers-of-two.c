/*

Given a number n, return whether it can be expressed as the sum of two powers of two. That means the sum of these types of 'doubling' numbers 1, 2, 4, 8, 16, 32, etc ...

Examples

twoPowersTwo(9) ➞ true
// Can be expressed as 1 + 8 (2^0 + 2^3).

twoPowersTwo(32) ➞ true
// Can be expressed as 16 + 16 (2^4 + 2^4)

twoPowersTwo(68) ➞ true
// Can be expressed as 64 + 4 (2^6 + 2^2)

two_powers_of_two(14) ➞ false

Notes

    The two powers of two don't have to be unique.
    Inputs are whole numbers >= 0
    The powers of two themselves don't have to be whole numbers, so 1 can be considered as valid: 0.5 + 0.5 or 2^-1 + 2^-1
    You can find a similar challenge here.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
twopowerstwo(unsigned long n)
{
	int c;

	for (c = 0; c < 3 && n; c++)
		n &= n - 1;
	return c == 1 || c == 2;
}

int
main(void)
{
	assert(twopowerstwo(0) == false);
	assert(twopowerstwo(1) == true);
	assert(twopowerstwo(2) == true);
	assert(twopowerstwo(3) == true);
	assert(twopowerstwo(4) == true);
	assert(twopowerstwo(5) == true);
	assert(twopowerstwo(6) == true);
	assert(twopowerstwo(9) == true);
	assert(twopowerstwo(14) == false);
	assert(twopowerstwo(32) == true);
	assert(twopowerstwo(48) == true);
	assert(twopowerstwo(68) == true);
	assert(twopowerstwo(72) == true);
	assert(twopowerstwo(80) == true);
	assert(twopowerstwo(96) == true);
	assert(twopowerstwo(1052672ul) == true);
	assert(twopowerstwo(131080ul) == true);
	assert(twopowerstwo(270336ul) == true);
	assert(twopowerstwo(1048578ul) == true);
	assert(twopowerstwo(262176ul) == true);

	return 0;
}
