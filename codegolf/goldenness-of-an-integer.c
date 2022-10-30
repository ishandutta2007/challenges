/*

A positive integer n can be represented as a rectangle with integer sides a, b such that n = a * b. That is, the area represents the number. In general, a and b are not unique for a given n.

As is well known, a rectangle is specially pleasing to the eye (or is it the brain?) when its sides are in the golden ratio, φ = (sqrt(5)+1)/2 ≈ 1.6180339887...

Combining these two facts, the purpose of this challenge is to decompose an integer n into the product of two integers a, b whose ratio is as close as possible to φ (with the usual metric on ℝ).
The fact that φ is irrational implies that there is a unique solution pair (a, b).

The challenge
Given a positive integer n, output positive integers a, b such that a * b = n and the absolute difference between a/b and φ is minimized.

As an example, consider n = 12. The pairs (a, b) that satisfy a * b = n are: (1, 12), (2,6), (3,4), (4,3), (6,2), (12,1). The pair whose ratio is closest to φ is (4,3), which gives 4/3 = 1.333.

Rules
Functions or programs are acceptable.

The numerator (a) should appear first in the output, and the denominator (b) second. Other than that, input and output formats are flexible as usual. For example, the two numbers can be output as strings with any reasonable separator, or as an array.

The code should work in theory for arbitrarily large numbers. In practice, it may be limited by memory or data-type restrictions.

It's sufficient to consider an approximate version of φ, as long as it is accurate up to the third decimal or better. That is, the absolute difference between the true φ and the approximate value should not exceed 0.0005. For example, 1.618 is acceptable.

When using an approximate, rational version of φ there's a small chance that the solution is not unique. In that case you can output any pair a, b that satisfies the minimization criterion.

Shortest code wins.

Test cases
1        ->  1    1
2        ->  2    1
4        ->  2    2
12       ->  4    3
42       ->  7    6
576      ->  32   18
1234     ->  2    617
10000    ->  125  80
199999   ->  1    199999
9699690  ->  3990 2431

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <float.h>

typedef unsigned long long uvlong;

#define PHI 1.61803398874989484820458683436563811772030917980576286213544862

void
goldeness(uvlong n, uvlong *a, uvlong *b)
{
	uvlong i, j;
	double d, m;

	*a = *b = 0;
	m = FLT_MAX;
	for (i = 1; i <= n; i++) {
		if (n % i)
			continue;

		j = n / i;
		d = fabs(PHI - (i * 1.0 / j));
		if (d < m) {
			*a = i;
			*b = j;
			m = d;
		}
	}
}

void
test(uvlong n, uvlong ra, uvlong rb)
{
	uvlong a, b;

	goldeness(n, &a, &b);
	printf("%llu %llu %llu\n", n, a, b);
	assert(a == ra);
	assert(b == rb);
}

int
main(void)
{
	test(1, 1, 1);
	test(2, 2, 1);
	test(4, 2, 2);
	test(12, 4, 3);
	test(42, 7, 6);
	test(576, 32, 18);
	test(1234, 2, 617);
	test(10000ULL, 125ULL, 80ULL);
	test(9699690ULL, 3990ULL, 2431ULL);

	return 0;
}
