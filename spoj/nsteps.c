/*

Starting from point (0,0) on a plane, we have written all non-negative integers 0, 1, 2,... as shown in the figure. For example, 1, 2, and 3 has been written at points (1,1), (2,0), and (3, 1) respectively and this pattern has continued.

You are to write a program that reads the coordinates of a point (x, y), and writes the number (if any) that has been written at that point. (x, y) coordinates in the input are in the range 0...10000.

Input
The first line of the input is N, the number of test cases for this problem. In each of the N following lines, there is x, and y representing the coordinates (x, y) of a point.

Output
For each point in the input, write the number written at that point or write No Number if there is none.

Example

Input:
3
4 2
6 6
3 4

Output:
6
12
No Number

*/

#include <assert.h>

int
steps(int x, int y)
{
	int xp, yp;
	int n;

	xp = yp = 0;
	for (n = 0; x != xp || y != yp; n++) {
		if (x <= xp && y <= yp)
			return -1;

		switch (n & 3) {
		case 0:
		case 2:
			xp += 1;
			yp += 1;
			break;
		case 1:
			xp += 1;
			yp -= 1;
			break;
		case 3:
			xp -= 1;
			yp += 1;
			break;
		}
	}

	return n;
}

int
main(void)
{
	assert(steps(4, 2) == 6);
	assert(steps(6, 6) == 12);
	assert(steps(7, 5) == 11);
	assert(steps(3, 4) == -1);
	assert(steps(1, 1) == 1);
	assert(steps(2, 5) == -1);
	assert(steps(9, 3) == -1);
	assert(steps(4, 4) == 8);

	return 0;
}
