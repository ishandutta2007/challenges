/*

Chef decided to buy a new tablet. His budget is B, so he cannot buy a tablet whose price is greater than B.
Other than that, he only has one criterion — the area of the tablet's screen should be as large as possible.
Of course, the screen of a tablet is always a rectangle.

Chef has visited some tablet shops and listed all of his options. In total, there are N available tablets, numbered 1 through N.
For each valid i, the i-th tablet has width Wi, height Hi and price Pi.

Help Chef choose a tablet which he should buy and find the area of such a tablet's screen, or determine that he cannot buy any tablet.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and B.
N lines follow. For each i (1≤i≤N), the i-th of these lines contains three space-separated integers Wi, Hi and Pi.

Output

For each test case, print a single line. If Chef cannot buy any tablet, it should contain the string "no tablet" (without quotes). Otherwise, it should contain a single integer — the maximum area of the screen of a tablet Chef can buy.

Constraints
1≤T≤100
1≤N≤100
1≤B≤1,000,000
1≤Pi≤1,000,000 for each valid i
1≤Wi,Hi≤10,000 for each valid i

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
tablet(int a[][3], size_t n, int b)
{
	size_t i;
	int r;

	r = -1;
	for (i = 0; i < n; i++) {
		if (a[i][2] <= b)
			r = max(r, a[i][0] * a[i][1]);
	}
	return r;
}

int
main(void)
{
	int a1[][3] = {
	    {3, 4, 4},
	    {5, 5, 7},
	    {5, 2, 5},
	};

	int a2[][3] = {
	    {3, 6, 8},
	    {5, 4, 9},
	};

	int a3[][3] = {
	    {5, 5, 10},
	};

	assert(tablet(a1, nelem(a1), 6) == 12);
	assert(tablet(a2, nelem(a2), 6) == -1);
	assert(tablet(a3, nelem(a3), 10) == 25);

	return 0;
}
