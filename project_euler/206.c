/*

Find the unique positive integer whose square has the form 1_2_3_4_5_6_7_8_9_0,
where each “_” is a single digit.

*/

#include <stdio.h>
#include <math.h>

typedef unsigned long long uvlong;

int
verify(uvlong n)
{
	uvlong i;

	for (i = 0; n; n /= 100) {
		if ((n % 10) != i)
			return 0;
		i = (i == 0) ? 9 : (i - 1);
	}
	return 1;
}

uvlong
solve(void)
{
	static const uvlong A = 1020304050607080990ull;
	static const uvlong B = 1929394959697989990ull;

	uvlong i, j;

	i = sqrt(A);
	j = sqrt(B);
	for (; i <= j; i++) {
		if (verify(i * i))
			return i;
	}

	return 0;
}

int
main(void)
{
	printf("%llu\n", solve());
	return 0;
}
