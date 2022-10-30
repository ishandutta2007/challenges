/*

It's the soccer match finals in Chefland and as always it has reached the penalty shotouts.
Each team is given 5 shots to make and the team scoring a goal on the maximum number of shots wins the game.
If both the teams' scores are equal, then the game is considered a draw and we would have 2 champions.

Given ten integers A1,A2,…,A10, where the odd indexed integers(A1,A3, A5, A7,A9) represent the outcome of the shots made by team 1 and even indexed integers(A2,A4,A6,A8,A10)
represent the outcome of the shots made by team 2 (here Ai=1 indicates that it's a goal and Ai=0 indicates a miss), determine the winner or find if the game ends in a draw.

Input Format

The first line of input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains ten space-separated integers A1,A2,…,A10.

Output Format

For each test case, print a single line containing one integer - 0 if the game ends in a draw or 1 if the first team wins or 2 if the second team wins.

Constraints
1≤T≤1024
0≤Ai≤1

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
outcome(int *a, size_t n)
{
	size_t i;
	int x, y;

	x = y = 0;
	for (i = 0; i < n; i++) {
		if (!(i & 1))
			x += a[i];
		else
			y += a[i];
	}
	if (x == y)
		return 0;
	if (x > y)
		return 1;
	return 2;
}

int
main(void)
{
	int a1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int a2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
	int a3[] = {1, 0, 1, 0, 0, 0, 0, 0, 0, 0};
	int a4[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0};

	assert(outcome(a1, nelem(a1)) == 0);
	assert(outcome(a2, nelem(a2)) == 2);
	assert(outcome(a3, nelem(a3)) == 1);
	assert(outcome(a4, nelem(a4)) == 1);

	return 0;
}
