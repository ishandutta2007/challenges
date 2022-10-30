/*

Today is Chef's birthday and he is looking forward to his gift. As usual, the gift is hidden and Chef has to follow a sequence of N instructions to reach it.

Initially, Chef is standing in the cell (0,0) of a two-dimensional grid. The sequence of instructions is given as a string S. If we denote Chef's current cell by (x,y), each character of S corresponds to an instruction as follows:

'L' means to go left, i.e. to the cell (x−1,y)
'R' means to go right, i.e. to the cell (x+1,y)
'U' means to go up, i.e. to the cell (x,y+1)
'D' means to go down, i.e. to the cell (x,y−1)

In addition, Chef should never perform multiple consecutive moves along the same axis of the grid. If there are multiple consecutive instructions to move along the same axis (left/right or up/down), he should perform only the first of these moves.

Find the cell (xg,yg) which contains the hidden gift.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains a single string S with length N.

Output

For each test case, print a single line containing two space-separated integers xg and yg.

Constraints
1≤T≤100
1≤N≤1,000
S contains only characters 'L', 'R', 'U' and 'D'

*/

#include <assert.h>
#include <stdio.h>

typedef struct {
	int x, y;
} Point;

int
direction(int c)
{
	switch (c) {
	case 'L':
	case 'R':
		return 1;
	case 'U':
	case 'D':
		return 2;
	}
	return 0;
}

Point
scrounge(const char *s)
{
	size_t i;
	Point p;

	p.x = p.y = 0;
	for (i = 0; s[i]; i++) {
		p.x += (s[i] == 'R');
		p.x -= (s[i] == 'L');
		p.y += (s[i] == 'U');
		p.y -= (s[i] == 'D');

		while (direction(s[i]) == direction(s[i + 1]))
			i++;
	}
	return p;
}

void
test(const char *s, Point r)
{
	Point p;

	p = scrounge(s);
	printf("%d %d\n", p.x, p.y);
	assert(p.x == r.x);
	assert(p.y == r.y);
}

int
main(void)
{
	test("LLLUR", (Point){0, 1});
	test("LLLRUUD", (Point){-1, 1});
	test("LRULLUDU", (Point){-2, 2});

	return 0;
}
