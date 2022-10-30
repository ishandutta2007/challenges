/*

A great deal of energy is lost as metabolic heat when the organisms from one trophic level are consumed by the next level.

Suppose in Chefland the energy reduces by a factor of K, i.e, if initially, the energy is X, then the transfer of energy to the next tropic level is ⌊X/K⌋.
This limits the length of foodchain which is defined to be the highest level receiving non-zero energy.

E is the energy at the lowest tropic level. Given E and K for an ecosystem, find the maximum length of foodchain.
Note: ⌊x⌋ denoted the floor function, and it returns the greatest integer that is less than or equal to x (i.e rounds down to the nearest integer). For example, ⌊1.4⌋=1, ⌊5⌋=5, ⌊−1.5⌋=−2, ⌊−3⌋=−3 , ⌊0⌋=0.

Input Format

First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains a single line of input, two integers E,K.

Output Format

For each testcase, output in a single line answer to the problem.

Constraints
1≤T≤10^4
1≤E≤10^9
2≤K≤10^9

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
foodchain(uvlong e, uvlong k)
{
	uvlong r;

	for (r = 0; e; e /= k)
		r++;
	return r;
}

int
main(void)
{
	assert(foodchain(5, 3) == 2);
	assert(foodchain(6, 7) == 1);
	assert(foodchain(10, 2) == 4);

	return 0;
}
