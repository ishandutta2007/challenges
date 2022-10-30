/*

Chef and his girlfriend are going to have a promenade. They are walking along the straight road which consists of segments placed one by one.
Before walking Chef and his girlfriend stay at the beginning of the first segment, they want to achieve the end of the last segment.

There are few problems:

At the beginning Chef should choose constant integer - the velocity of mooving. It can't be changed inside one segment.
The velocity should be decreased by at least 1 after achieving the end of some segment.
There is exactly one shop on each segment. Each shop has an attractiveness.
If it's attractiveness is W and Chef and his girlfriend move with velocity V then if V < W girlfriend will run away into the shop and the promenade will become ruined.
Chef doesn't want to lose her girl in such a way, but he is an old one, so you should find the minimal possible velocity at the first segment to satisfy all conditions.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the number of segments. The second line contains N space-separated integers W1, W2, ..., WN denoting the attractiveness of shops.

Output

For each test case, output a single line containing the minimal possible velocity at the beginning.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
1 ≤ Wi ≤ 10^6

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

unsigned
velocity(unsigned *a, size_t n)
{
	unsigned r;
	size_t i;

	r = 0;
	for (i = 0; i < n; i++)
		r = max(r, a[i] + i);
	return r;
}

int
main(void)
{
	unsigned a1[] = {6, 5, 4, 3, 2};
	unsigned a2[] = {3, 4, 3, 1, 1};

	assert(velocity(a1, nelem(a1)) == 6);
	assert(velocity(a2, nelem(a2)) == 5);

	return 0;
}
