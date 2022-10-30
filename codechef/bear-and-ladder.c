/*

Bearland has infinitely many cities, numbered starting from 1. Some pairs of cities are connected with bidirectional roads:

There are roads 1-2, 3-4, 5-6, 7-8, and so on (there is a road between cities 2*i+1 and 2*i+2 for every non-negative integer i).
There are roads 1-3, 3-5, 5-7, 7-9, ... (between every two consecutive odd numbers).
There are roads 2-4, 4-6, 6-8, 8-10, ... (between every two consecutive even numbers).
This is how the first few cities and roads between them look like:

You are given Q queries. In each query, for the given pair of different cities a and b, you should check if there is a road between them. For each query, print "YES" or "NO" accordingly.

Input

The first line of the input contains an integer Q, denoting the number of queries.

Each of the following Q lines contains two distinct integers a and b, denoting two cities in one query.

Output

For each query, output a single line containing the answer — "YES" if there is a road between the given cities a and b, and "NO" otherwise (without the quotes).

Constraints
1 ≤ Q ≤ 1000
1 ≤ a, b ≤ 10^9
a ≠ b

*/

#include <assert.h>
#include <stdbool.h>

typedef unsigned long long uvlong;

void
swap(uvlong *a, uvlong *b)
{
	uvlong t;

	t = *a;
	*a = *b;
	*b = t;
}

bool
roadable(uvlong a, uvlong b)
{
	if (a < b)
		swap(&a, &b);

	if (a - b == 2)
		return true;
	if (a - b == 1 && (b & 1))
		return true;
	return false;
}

int
main(void)
{
	assert(roadable(1, 4) == false);
	assert(roadable(4, 3) == true);
	assert(roadable(5, 4) == false);
	assert(roadable(10, 12) == true);
	assert(roadable(1, 3) == true);
	assert(roadable(999999999ULL, 1000000000ULL) == true);
	assert(roadable(17, 2384823ULL) == false);

	return 0;
}
