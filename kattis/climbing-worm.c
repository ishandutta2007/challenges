/*

A worm is at the bottom of a pole. It wants to reach the top, but it is too lazy to climb to the top without stopping.
It can crawl up the pole a certain number of inches at a time, falling down a lesser number of inches right after while it rests.
How many times does the worm need to crawl up in order to reach the top of the pole?

Input

The input consists of a single line that contains three integers a,b (0≤b<a≤100), and h, (0<h≤100000) indicating the amount a of inches the worm can climb at a time,
the amount b of inches the worm falls during its resting period, and the height h of the pole, respectively. For the purposes of this problem, the worm is modeled as a point and thus has no length.

Output

Output the number of times the worm must crawl up in order to reach the top of the pole.

*/

#include <assert.h>
#include <stdio.h>

int
climb(int a, int b, int h)
{
	int c, y;

	y = 0;
	for (c = 1;; c++) {
		y += a;
		if (y >= h)
			break;
		y -= b;
	}
	return c;
}

int
main(void)
{
	assert(climb(5, 0, 15) == 3);
	assert(climb(3, 1, 4) == 2);
	return 0;
}
