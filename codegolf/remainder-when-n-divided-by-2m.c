/*

Write the shortest code to find the remainder when an input number N is divided by 2^M. You cannot use /,* and % operator.

Input Specification
Number of test cases followed by a pair of integers on each line.

Sample Input
1
150 6

Sample Output
22

Limits
1<T<1000
1<N<2^31
1<B<31

Time Limit
1 Sec

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned long long uvlong;

uvlong
rem(uvlong n, uvlong m)
{
	return n & ~(~0ull << m);
}

int
main(void)
{
	uvlong n, m, i;

	srand(time(NULL));

	assert(rem(150, 6) == 22);
	assert(rem(2485, 3) == 5);
	assert(rem(1ull << 31, 1) == 0);
	for (i = 0; i < 1000; i++) {
		n = rand();
		m = rand() & 31;
		assert(rem(n, m) == (n % (1ull << m)));
	}

	return 0;
}
