/*

WW3 is near and Gru wants to recruit minions for his team.
Gru went to the planet of minions to recruit minions, he saw that there are two villages separated by a river.
He cannot recruit minions from both villages because then his team will have internal conflicts.

Gru is now in a dilemma about which village to recruit as he wants to have the strongest possible team.

You are given coordinates of houses on the planet. Each house has exactly one minion and his power is given.
The planet of minion is considered as a 2-D plane and the river is denoted by a straight line ( y=mx+c ).
Note: None of the houses are situated on the river.

Input:

First-line will contain N, number of houses.
Second-line will contain two integers, m and c denoting the river.
Next N lines will have exactly 3 integers X[i],Y[i],P[i] denoting the coordinates of houses and the power of minion in that house

Output:

Print the maximum power of the team which Gru can recruit.

Constraints
1≤N≤10^5
−10^4≤m,c≤10^4
−10^4≤X[i],Y[i]≤10^4
1≤P[i]≤10^4

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
maxpower(int a[][3], size_t n, int m, int c)
{
	int v, x, y;
	size_t i;

	x = y = 0;
	for (i = 0; i < n; i++) {
		v = a[i][1] - (m * a[i][0]) + c;
		if (v > 0)
			x += a[i][2];
		else
			y += a[i][2];
	}
	return max(x, y);
}

int
main(void)
{
	int a1[][3] = {
	    {0, 5, 5},
	    {0, 6, 5},
	    {0, -8, 20},
	};

	assert(maxpower(a1, nelem(a1), 1, 0) == 20);
	return 0;
}
