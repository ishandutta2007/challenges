/*

Consider a grid from (0,0) in the bottom-left corner to (m,n) in the top-right corner. You begin at (0,0), and can only move in one of these three ways:

Directly north (+0,+1),
Directly east (+1,+0), or
Directly north-east (+1,+1)
How many different paths are there from your start at (0,0) to (m,n)?

For example, if you're trying to reach (3,3), there are 63 different paths:

This value is given by D(m,n), the Delannoy numbers. One formula for these numbers is

D(m,n) =
         1 if m=0 or n=0,
         D(m−1,n)+D(m−1,n−1)+D(m,n−1) otherwise

Others can be found on the Wikipedia page

You are to take two non-negative integers n and m and output D(m,n). This is code-golf, so the shortest code in bytes wins

You may input and output in any convenient manner, and you may assume that no part of the calculation exceeds your language's integer maximum.

Test cases
[m, n] -> D(m, n)
[5, 8] -> 13073
[5, 7] -> 7183
[3, 9] -> 1159
[8, 6] -> 40081
[8, 8] -> 265729
[1, 7] -> 15
[7, 0] -> 1
[11, 6] -> 227305
[0, 4] -> 1

And all possible outputs for 0≤n,m≤7:

[m, n] -> D(m, n)
[0, 0] -> 1
[0, 1] -> 1
[0, 2] -> 1
[0, 3] -> 1
[0, 4] -> 1
[0, 5] -> 1
[0, 6] -> 1
[0, 7] -> 1
[0, 8] -> 1
[1, 0] -> 1
[1, 1] -> 3
[1, 2] -> 5
[1, 3] -> 7
[1, 4] -> 9
[1, 5] -> 11
[1, 6] -> 13
[1, 7] -> 15
[1, 8] -> 17
[2, 0] -> 1
[2, 1] -> 5
[2, 2] -> 13
[2, 3] -> 25
[2, 4] -> 41
[2, 5] -> 61
[2, 6] -> 85
[2, 7] -> 113
[2, 8] -> 145
[3, 0] -> 1
[3, 1] -> 7
[3, 2] -> 25
[3, 3] -> 63
[3, 4] -> 129
[3, 5] -> 231
[3, 6] -> 377
[3, 7] -> 575
[3, 8] -> 833
[4, 0] -> 1
[4, 1] -> 9
[4, 2] -> 41
[4, 3] -> 129
[4, 4] -> 321
[4, 5] -> 681
[4, 6] -> 1289
[4, 7] -> 2241
[4, 8] -> 3649
[5, 0] -> 1
[5, 1] -> 11
[5, 2] -> 61
[5, 3] -> 231
[5, 4] -> 681
[5, 5] -> 1683
[5, 6] -> 3653
[5, 7] -> 7183
[5, 8] -> 13073
[6, 0] -> 1
[6, 1] -> 13
[6, 2] -> 85
[6, 3] -> 377
[6, 4] -> 1289
[6, 5] -> 3653
[6, 6] -> 8989
[6, 7] -> 19825
[6, 8] -> 40081
[7, 0] -> 1
[7, 1] -> 15
[7, 2] -> 113
[7, 3] -> 575
[7, 4] -> 2241
[7, 5] -> 7183
[7, 6] -> 19825
[7, 7] -> 48639
[7, 8] -> 108545
[8, 0] -> 1
[8, 1] -> 17
[8, 2] -> 145
[8, 3] -> 833
[8, 4] -> 3649
[8, 5] -> 13073
[8, 6] -> 40081
[8, 7] -> 108545
[8, 8] -> 265729

*/

#include <assert.h>

typedef unsigned long long uvlong;

// https://oeis.org/A008288
uvlong
delannoy(uvlong m, uvlong n)
{
	if (m == 0 || n == 0)
		return 1;
	return delannoy(m - 1, n) + delannoy(m - 1, n - 1) + delannoy(m, n - 1);
}

int
main(void)
{
	assert(delannoy(5, 8) == 13073ULL);
	assert(delannoy(5, 7) == 7183ULL);
	assert(delannoy(3, 9) == 1159ULL);
	assert(delannoy(8, 6) == 40081ULL);
	assert(delannoy(8, 8) == 265729ULL);
	assert(delannoy(1, 7) == 15ULL);
	assert(delannoy(7, 0) == 1ULL);
	assert(delannoy(11, 6) == 227305ULL);
	assert(delannoy(0, 4) == 1ULL);

	return 0;
}
