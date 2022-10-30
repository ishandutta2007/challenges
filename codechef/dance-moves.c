/*

This year Chef is participating in a Dancing competition.
The dance performance will be done on a linear stage marked with integral movess.
Initially, Chef is present at moves X and Chef's dance partner is at moves Y.
Chef can perform two kinds of dance moves.

If Chef is currently at moves k, Chef can:

Moonwalk to moves k+2, or
Slide to moves k−1
Chef wants to find the minimum number of moves required to reach his partner. Can you help him find this number?

Input Format

First line will contain a single integer T, the number of testcases. Then the description of T testcases follows.
Each testcase contains a single line with two space-separated integers X,Y, representing the initial movess of Chef and his dance partner, respectively.

Output Format

For each testcase, print in a separate line, a single integer, the minimum number of moves required by Chef to reach his dance partner.

Constraints
1≤T≤10^3
-10^3≤X,Y≤10^3

*/

#include <assert.h>

int
moves(int x, int y)
{
	int d, p;

	if (y <= x)
		return x - y;

	d = y - x;
	p = d & 1;
	return (d + p) / 2 + p;
}

int
main(void)
{
	assert(moves(3, 8) == 4);
	assert(moves(-11, -5) == 3);
	assert(moves(57, 492) == 219);
	assert(moves(-677, 913) == 795);

	return 0;
}
