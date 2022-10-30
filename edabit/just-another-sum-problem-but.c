/*

Ok, the challenge is kind of easy, right?

The problem is not adding, the problem is that the numbers are not in order, create a function that organizes the numbers and adds the numbers in the range between X and Y.

Here is an example:

X = -10 | Y=1

So this will be the range of numbers:

-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1

This will be your result:

-54

Remember, X and Y are disorganized, so to get to the result you know what you have to do.

Examples

just_another_sum_problem(-10, 1) ➞ -54

just_another_sum_problem(-20, 5) ➞ -195

just_another_sum_problem(90, 45) ➞ 3105

Notes

Check out the Resources tab if you need some help :)

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef long long vlong;

vlong
sigma(vlong n)
{
	return n * (n + 1) / 2;
}

vlong
sign(vlong n)
{
	return (n < 0) ? -1 : 1;
}

vlong
sum(vlong a, vlong b)
{
	vlong sa, sb;

	sa = sign(a);
	sb = sign(b);
	if (sa != sb)
		return sa * sigma(llabs(a)) + sb * sigma(llabs(b));
	return sigma(max(a, b)) - sigma(min(a, b) - 1);
}

int
main(void)
{
	assert(sum(1, -10) == -54);
	assert(sum(-20, 5) == -195);
	assert(sum(-40, 20) == -610);
	assert(sum(20, -100) == -4840);
	assert(sum(-15, 3) == -114);
	assert(sum(-8, 4) == -26);

	assert(sum(13, -1000000000ll) == -500000000499999909ll);
	assert(sum(7, 1000000000ll) == 500000000499999979ll);

	assert(sum(90, 45) == 3105);
	assert(sum(100, 58) == 3397);
	assert(sum(65, 48) == 1017);
	assert(sum(2, 3) == 5);
	assert(sum(89, 256) == 28980);
	assert(sum(302, 56) == 44213);

	return 0;
}
