/*

Here is the sequence I'm talking about:

{1, 4, 5, 9, 10, 11, 16, 17, 18, 19, 25, 26, 27...}
Starting from 1, keep 1, drop the next 2, keep the next 2, drop 3, keep 3 and so on. Yes, it's on OEIS (A064801), too!

The Challenge

Given an integer n>0, find the nth term of the above sequence

Test Cases

Input -> Output
1->1
22->49
333->683
4444->8908
12345->24747
This is code golf so the shortest answer in bytes wins! Good luck!

*/

#include <assert.h>
#include <math.h>

long
keepdrop(long n)
{
	long m, t;

	if (n <= 0)
		return 0;

	t = floor((-1 + sqrt(8 * n - 7)) / 2);
	m = (t + 2) * (t + 1) / 2;
	return n + m - 1;
}

int
main(void)
{
	assert(keepdrop(1) == 1);
	assert(keepdrop(22) == 49);
	assert(keepdrop(333) == 683);
	assert(keepdrop(4444) == 8908);
	assert(keepdrop(12345) == 24747L);

	return 0;
}
