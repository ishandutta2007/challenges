/*

Warmup

Given a number n, determine the number of times the digit "1" appears if you write out all numbers from 1 to n inclusive.

f(1) = 1
f(5) = 1
f(10) = 2
f(20) = 12
f(1234) = 689
f(5123) = 2557
f(70000) = 38000
f(123321) = 93395
f(3^35) = 90051450678399649

You should be able to handle large inputs like 3^35 efficiently, meaning much faster than iterating over all numbers from 1 to n. Find f(5^20) before posting your solution. The answer is 15 digits long and the sum of its digits is 74.
Challenge

f(35199981) = 35199981. Efficiently find the sum of all n such that f(n) = n. This should take a fraction of a second, depending on your programming language.

The answer is 11 digits long and the sum of its digits is 53.

(This is a repost of Challenge #45 [difficult], originally posted by u/oskar_s in April 2012. Check that post for hints and more detail.)

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef long long vlong;

// https://oeis.org/A094798
vlong
count(vlong n)
{
	vlong s, t;

	s = 0;
	for (t = 1; t <= n; t *= 10)
		s += min(max(0, (n % (10 * t)) - (t - 1)), t) + t * (n / (10 * t));
	return s;
}

int
main(void)
{
	assert(count(1) == 1);
	assert(count(5) == 1);
	assert(count(10) == 2);
	assert(count(20) == 12);
	assert(count(1234) == 689);
	assert(count(5123) == 2557);
	assert(count(70000ll) == 38000ll);
	assert(count(123321ll) == 93395ll);
	assert(count(35199981ll) == 35199981ll);
	assert(count(95367431640625ll) == 134507752666859ll);
	assert(count(50031545098999707ll) == 90051450678399649ll);

	return 0;
}
