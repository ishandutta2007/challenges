/*

Chef is eagerly waiting for a piece of information. His secret agent told him that this information would be revealed to him after K weeks.

X days have already passed and Chef is getting restless now. Find the number of remaining days Chef has to wait for, to get the information.

It is guaranteed that the information has not been revealed to the Chef yet.

Input Format
The first line of input will contain an integer T — the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers K and X, as described in the problem statement.

Output Format
For each test case, output the number of remaining days that Chef will have to wait for.

Constraints
1≤T≤500
1≤K≤10
1≤X<7⋅K

*/

#include <assert.h>

int
days(int k, int x)
{
	return (7 * k) - x;
}

int
main(void)
{
	assert(days(1, 5) == 2);
	assert(days(1, 6) == 1);
	assert(days(1, 1) == 6);
	assert(days(1, 2) == 5);

	return 0;
}
