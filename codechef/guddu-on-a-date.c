/*

Guddu likes a girl that loves playing with numbers. She agreed to go on a date with Guddu, but only if he can solve the following problem:

An integer is round if it is greater than 0 and the sum of its digits in decimal representation is a multiple of 10. Find the N-th smallest round integer.

However, Guddu does not like playing with numbers at all and he is unable to solve this problem, so he begs you to solve it for him. In return, he will definitely give you a treat.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.

Output

For each test case, print a single line containing the N-th round integer. It is guaranteed that this number is smaller than 264.

Constraints
1≤T≤10^5
1≤N≤10^18

*/

#include <assert.h>

typedef long long vlong;

vlong
nsr(vlong n)
{
	vlong s, v;

	s = 0;
	for (v = n; v; v /= 10)
		s += v % 10;
	return (n * 10) + ((10 - (s % 10)) % 10);
}

int
main(void)
{
	assert(nsr(2) == 28);

	return 0;
}
