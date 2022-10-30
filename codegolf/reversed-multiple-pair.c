/*

Intro
Two numbers are a reversed multiple pair if they satisfy the following property:

a⋅b=reversed((a−1)⋅b)

Here, reversed() means to reverse the digits of a number (e. g 123 becomes 321.)

Example
a=6,b=9,6⋅9=54,5⋅9=45

As you can see, 45 is the reversed version of 54.

Task
Given two integers, a and b, output if these two numbers is a reversed multiple pair.

Test Cases
6 9 => True
4 5 => False
3 2178 => True
34 2079 => True
7 8 => False
600 100 => False
46 1089 => True
817 503 => False
6 9009 => True
321 81 => False
10 1089 => False
Shortest code wins!

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int
rev(int n)
{
	int s, v;

	s = (n >= 0) ? 1 : -1;
	n = abs(n);
	for (v = 0; n; n /= 10)
		v = (v * 10) + (n % 10);
	return v * s;
}

bool
rmp(int a, int b)
{
	return (a * b) == rev((a - 1) * b);
}

int
main(void)
{
	assert(rmp(6, 9) == true);
	assert(rmp(4, 5) == false);
	assert(rmp(3, 2178) == true);
	assert(rmp(34, 2079) == true);
	assert(rmp(7, 8) == false);
	assert(rmp(600, 100) == false);
	assert(rmp(46, 1089) == true);
	assert(rmp(817, 503) == false);
	assert(rmp(6, 9009) == true);
	assert(rmp(321, 81) == false);
	assert(rmp(10, 1089) == false);

	return 0;
}
