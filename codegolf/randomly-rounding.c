/*

Input a decimal number, round it to integer. It randomly round up or round down based on its fractional part.

If input x is an integer, the program should output it as is. If input x is non-integer, the program has x−⌊x⌋ probability output ⌈x⌉, and 1−(x−⌊x⌋) probability output ⌊x⌋.

In the above formula, ⌊i⌋ means rounding i down to integer; ⌈i⌉ means rounding i up to integer.

Examples

For input 2.4, it has 60% probability outputs 2, and 40% probability outputs 3.
For input 3.9, it has 10% probability outputs 3, and 90% probability outputs 4.
For input 0.5, it has 50% probability outputs 0, and 50% probability outputs 1.
For input -5.25, it has 75% probability outputs -5, and 25% probability outputs -6.
For input 8, it has 100% probability outputs 8, and 0% probability outputs 7 or 9.

Rules

To make the challenge easier. A reasonable error in probability is allowed.
For any input −100<x<100, the probability error should less than 0.01%.
You may assume your language built-in random number generator is perfectly fair.
You may assume the input / output value fits your languages decimal number types, as long as this not trivialize the challenge.
As usual, this is code-golf. So shortest code wins.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int
rndround(double x)
{
	double f, p;

	f = floor(x);
	p = x - f;
	if (p == 0 || p <= drand48())
		return x;
	return ceil(x);
}

int
main(void)
{
	srand48(time(NULL));

	printf("%d\n", rndround(10.4));
	printf("%d\n", rndround(9.5));

	return 0;
}
