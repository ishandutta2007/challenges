/*

You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps.

In how many distinct ways can you climb to the top?

*/

#include <stdio.h>

long
ways(long n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	return ways(n - 1) + ways(n - 2);
}

long
fib(long n)
{
	long i, a, b, r;

	a = 0;
	b = 1;
	r = 0;
	for (i = 0; i < n; i++) {
		r = a + b;
		a = b;
		b = r;
	}
	return r;
}

int
main(void)
{
	long i;
	for (i = 0; i <= 32; i++)
		printf("%ld %ld %ld\n", i, ways(i), fib(i));
	return 0;
}
