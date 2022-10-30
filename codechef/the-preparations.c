/*

Chef has an exam which will start exactly M minutes from now.
However, instead of preparing for his exam, Chef started watching Season-1 of Superchef.
Season-1 has N episodes, and the duration of each episode is K minutes.

Will Chef be able to finish watching Season-1 strictly before the exam starts?

Note: Please read the explanations of the sample test cases carefully.

Input Format

The first line contains an integer T denoting the number of test cases. T test cases then follow.
The first and only line of each test case contains 3 space separated integers M, N and K.

Output Format

For each test case, output on one line YES if it is possible to finish Season-1 strictly before the exam starts, or NO if it is not possible to do so.

Output is case insensitive, which means that "yes", "Yes", "YEs", "no", "nO" - all such strings will be acceptable.

Constraints
1≤T≤10^4
1≤M≤10^9
1≤N,K≤10^4

*/

#include <assert.h>

unsigned
bingeable(unsigned m, unsigned n, unsigned k)
{
	return n * k < m;
}

int
main(void)
{
	assert(bingeable(10, 1, 10) == 0);
	assert(bingeable(25, 2, 10) == 1);
	assert(bingeable(15, 2, 10) == 0);

	return 0;
}
