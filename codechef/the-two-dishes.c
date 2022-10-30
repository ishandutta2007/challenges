/*

Chef prepared two dishes yesterday. Chef had assigned the tastiness T1 and T2 to the first and to the second dish respectively. The tastiness of the dishes can be any integer between 0 and N (both inclusive).

Unfortunately, Chef has forgotten the values of T1 and T2 that he had assigned to the dishes. However, he remembers the sum of the tastiness of both the dishes - denoted by S.

Chef wonders, what can be the maximum possible absolute difference between the tastiness of the two dishes. Can you help the Chef in finding the maximum absolute difference?

It is guaranteed that at least one pair {T1,T2} exist such that T1+T2=S,0≤T1,T2≤N.

Input Format

The first line of input contains a single integer T, denoting the number of testcases. The description of the T testcases follows.
The first and only line of each test case contains two space-separated integers N, S, denoting the maximum tastiness and the sum of tastiness of the two dishes, respectively.

Output Format

For each testcase, output a single line containing the maximum absolute difference between the tastiness of the two dishes.

Constraints
1≤T≤10^3
1≤N≤10^5
1≤S≤2⋅10^5

*/

#include <assert.h>

int
taste(int n, int s)
{
	if (s <= n)
		return s;
	return (n * 2) - s;
}

int
main(void)
{
	assert(taste(3, 1) == 1);
	assert(taste(4, 4) == 4);
	assert(taste(2, 3) == 1);

	return 0;
}
