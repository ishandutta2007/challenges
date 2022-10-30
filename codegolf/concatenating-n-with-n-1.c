/*

Introduction
OEIS sequence A127421 is the sequence of numbers whose decimal expansion is a concatenation of 2 consecutive increasing non-negative numbers.
Put simply, every number in the sequence is formed by putting together n with n+1 for some non-negative, integer value of n. The first several terms are:

1, 12, 23, 34, 45, 56, 67, 78, 89, 910, 1011, 1112, 1213, 1314, 1415, 1516, 1617, 1718, 1819, 1920, 2021, 2122, 2223, 2324, 2425, 2526, 2627, 2728, 2829, 2930, 3031, 3132, 3233, 3334, 3435, 3536, 3637, 3738, 3839, 3940, 4041, 4142, 4243, 4344, 4445, 4546, …

Challenge
Given a single positive integer n, print the first n entries of OEIS sequence A127421 in increasing order.

Input and output can be in any acceptable format. Strings or numbers are fine for output.
Leading zeroes are not permitted.
Either a full program or function is permitted.
For the purposes of this challenge, n will be positive and under 100.
Standard loopholes are disallowed by default.
This question is code golf, so lowest byte-count wins.
Here is some sample input and output:

1 => 1
2 => 1, 12
3 => 1, 12, 23
10 => 1, 12, 23, 34, 45, 56, 67, 78, 89, 910
If you have any questions, don't hesitate to ask. Good luck.

P.S this is my first challenge, so hopefully this all makes sense.

EDIT: Removed output restriction to allow numbers or strings.

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef unsigned long long uvlong;

size_t
seq(uvlong n, uvlong *r)
{
	char b[sizeof(n) * CHAR_BIT];
	uvlong i;

	for (i = 0; i < n; i++) {
		if (i == 0)
			snprintf(b, sizeof(b), "%llu", i + 1);
		else
			snprintf(b, sizeof(b), "%llu%llu", i, i + 1);
		r[i] = strtoull(b, NULL, 10);
	}
	return n;
}

void
print(uvlong *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%llu ", a[i]);
	printf("\n");
}

void
test(uvlong n)
{
	uvlong r[128];

	seq(n, r);
	print(r, n);
}

int
main(void)
{
	test(50);
	return 0;
}
