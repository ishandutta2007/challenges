/*

Chef has been searching for a good motivational movie that he can watch during his exam time.
His hard disk has X GB of space remaining. His friend has N movies represented with (Si,Ri) representing (space required, IMDB rating).
Help Chef choose the single best movie (highest IMDB rating) that can fit in his hard disk.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and X.
N lines follow. For each valid i, the i-th of these lines contains two space-separated integers Si and Ri.

Output

For each test case, print a single line containing one integer - the highest rating of an IMDB movie which Chef can store in his hard disk.

Constraints
1≤T≤10
1≤N≤5⋅10^4
1≤X≤10^9
1≤Si,Ri≤109 for each valid i
X≥Si for atleast one valid i

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
highest(int a[][2], size_t n, int x)
{
	size_t i;
	int s, r;
	int v;

	v = 0;
	for (i = 0; i < n; i++) {
		s = a[i][0];
		r = a[i][1];
		if (s <= x && v < r)
			v = r;
	}
	return v;
}

int
main(void)
{
	int a1[][2] = {
	    {1, 1},
	};

	int a2[][2] = {
	    {1, 50},
	    {2, 100},
	};

	int a3[][2] = {
	    {1, 51},
	    {3, 100},
	    {2, 50},
	};

	assert(highest(a1, nelem(a1), 1) == 1);
	assert(highest(a2, nelem(a2), 2) == 100);
	assert(highest(a3, nelem(a3), 2) == 51);

	return 0;
}
