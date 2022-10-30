/*

Introduction

It was just a normal day, here at your military base. Suddenly, you looked up to see a bomb falling down from the sky! You need to create a program to predict where it will fall, and tell you the location.
Challenge

You will be given a bomb in the form of Start-X Start-Y X-velocity Y-velocity. You can assume that they will all be positive integers.
0 is a valid input only for Start-x and Start-y. The bomb starts with x Start-x, and y Start-y.
Each "frame" (no graphical output required), the bomb will move x-velocity units right, then y-velocity units down.
Continue doing this until the bomb reaches y of 0 or below. Then, output what it's x was when it hit the ground.

Test Cases

1

Input:0 10 2 2

Output:10

2

Input:5 4 3 2

Output:11

3

Input:11,8,7,3

Output:32

This is code-golf, so shortest answer in bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
landing(int sx, int sy, int vx, int vy)
{
	return sx + vx * ceil(1.0 * sy / vy);
}

int
main(void)
{
	assert(landing(0, 10, 2, 2) == 10);
	assert(landing(5, 4, 3, 2) == 11);
	assert(landing(11, 8, 7, 3) == 32);

	return 0;
}
