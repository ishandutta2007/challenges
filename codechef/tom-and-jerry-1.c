/*

There is a grid of size 10^5×10^5, covered completely in railway tracks. Tom is riding in a train, currently in cell (a,b), and Jerry is tied up in a different cell (c,d), unable to move.
The train has no breaks. It shall move exactly K steps, and then its fuel will run out and it shall stop.
In one step, the train must move to one of its neighboring cells, sharing a side. Tom can’t move without the train, as the grid is covered in tracks. Can Tom reach Jerry’s cell after exactly K steps?

Note: Tom can go back to the same cell multiple times.

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, five integers a,b,c,d,K.

Output

For each testcase, output in a single line "YES" if Tom can reach Jerry's cell in exactly K moves and "NO" if not.

You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤10^5
0≤a,b,c,d≤10^5
(a,b)≠(c,d)
1≤K≤2⋅10^5

*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

bool
reachable(int a, int b, int c, int d, int k)
{
	int p;

	p = abs(a - c) + abs(b - d);
	return k >= p && ((k & 1) == (p & 1));
}

int
main(void)
{
	assert(reachable(1, 1, 2, 2, 2) == true);
	assert(reachable(1, 1, 2, 3, 4) == false);
	assert(reachable(1, 1, 1, 0, 3) == true);

	return 0;
}
