/*

Description

Critical hits work a bit differently in this RPG. If you roll the maximum value on a die, you get to roll the die again and add both dice rolls to get your final score.
Critical hits can stack indefinitely -- a second max value means you get a third roll, and so on. With enough luck, any number of points is possible.

Input

    d -- The number of sides on your die.
    h -- The amount of health left on the enemy.

Output

The probability of you getting h or more points with your die.
Challenge Inputs and Outputs
Input: d 	Input: h 	Output
4 	1 	1
4 	4 	0.25
4 	5 	0.25
4 	6 	0.1875
1 	10 	1
100 	200 	0.0001
8 	20 	0.009765625
Secret, off-topic math bonus round

What's the expected (mean) value of a D4? (if you are hoping for as high a total as possible).

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
probability(int d, int h)
{
	double p;

	for (p = 1; h > d; h -= d)
		p *= 1.0 / d;
	if (h > 0)
		p *= (1.0 + d - h) / d;
	return p;
}

void
test(int d, int h, double r)
{
	double p;

	p = probability(d, h);
	assert(fabs(p - r) < 1e-8);
}

int
main(void)
{
	test(4, 1, 1);
	test(4, 4, 0.25);
	test(4, 5, 0.25);
	test(4, 6, 0.1875);
	test(1, 10, 1);
	test(100, 200, 0.0001);
	test(8, 20, 0.009765625);

	return 0;
}
