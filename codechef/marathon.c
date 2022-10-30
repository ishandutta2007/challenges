/*

Chefland is holding a virtual marathon for the categories 10 km, 21 km and 42 km having prizes A,B,C (A<B<C) respectively to promote physical fitness.
In order to claim the prize in a particular category the person must cover the total distance for that category within D days.
Also a single person cannot apply in multiple categories.

Given the maximum distance d km that Chef can cover in a single day, find the maximum prize that Chef can win at the end of D days.
If Chef can't win any prize, print 0.

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, five integers D,d,A,B,C.

Output

For each test case, output in a single line the answer to the problem.

Constraints
1≤T≤50
1≤D≤10
1≤d≤5
1≤A<B<C≤10^5

*/

#include <assert.h>

int
prize(int D, int d, int a, int b, int c)
{
	int t;

	t = D * d;
	if (t >= 42)
		return c;
	if (t >= 21)
		return b;
	if (t >= 10)
		return a;
	return 0;
}

int
main(void)
{
	assert(prize(1, 1, 1, 2, 3) == 0);
	assert(prize(10, 1, 1, 2, 3) == 1);
	assert(prize(10, 3, 1, 2, 3) == 2);

	return 0;
}
