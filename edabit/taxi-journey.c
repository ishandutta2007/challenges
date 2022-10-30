/*

A taxi journey costs $3 for the first kilometer travelled. However, all kilometers travelled after that will cost $2 each.

Create a function which returns the distance that the taxi must've travelled, given the cost as a parameter.
Examples

journey_distance(3) ➞ 1
# The first kilometer costs $3

journey_distance(9) ➞ 4
# The first kilometer costs $3 plus the other three kilometers (costing $2 each)

journey_distance(5) ➞ 2

Notes

    The input tests are valid integers >= 0.
    The output will always be a whole number.
    Remember that you are calculating the distance from the cost, not the other way around!

*/

#include <assert.h>

unsigned long
journey(unsigned long c)
{
	return (c < 3) ? 0 : (c - 3) / 2 + 1;
}

int
main(void)
{
	assert(journey(0) == 0);
	assert(journey(3) == 1);
	assert(journey(5) == 2);
	assert(journey(9) == 4);
	assert(journey(15) == 7);
	assert(journey(99) == 49);
	assert(journey(11037) == 5518);

	return 0;
}
