/*

Chefu is Chef's little brother, he is 12 years old and he is new to competitive programming.

Chefu is practicing very hard to become a very skilled competitive programmer and win gold medal in IOI.

Now Chefu is participating in a contest and the problem that he is trying to solve states:

Given an array A of N integers, find any i, j such that i < j and Ai + Aj is maximum possible unfortunately,
there's no much time left before the end of the contest, so Chefu doesn't have time to think of correct solution, so instead,
he wrote a solution that selects a random pair (i, j) (i < j) and output Ai + Aj. each pair is equiprobable to be selected.

Now Chefu wants your help to calculate the probability that his solution will pass a particular input.

Input

First line contains an integer T denoting the number of test-cases.

First line of each test-case contains a single integer N

Second line of each test-case contains N space-separated integers A1 A2 ... AN

Output

For each test-case output a single line containing a single number denoting the probability that Chefu's solution to output a correct answer. your answer will be accepted if the absolute difference between it and correct answer is less than 1e-6

Constraints
1 ≤ T ≤ 100
2 ≤ N ≤ 100
1 ≤ Ai ≤ 1,000

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
probability(unsigned *a, size_t n)
{
	unsigned c, l;
	unsigned m, v;
	size_t i, j;

	c = m = l = 0;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			v = a[i] + a[j];
			if (v > m) {
				m = v;
				c = 1;
			} else if (v == m)
				c++;
		}
		l += (n - i - 1);
	}

	return (l) ? c * 1.0 / l : 0;
}

void
test(unsigned *a, size_t n, double r)
{
	double p;

	p = probability(a, n);
	printf("%f\n", p);
	assert(fabs(r - p) < 1e-8);
}

int
main(void)
{
	unsigned a1[] = {3, 3, 3, 3};
	unsigned a2[] = {1, 1, 1, 2, 2, 2};
	unsigned a3[] = {1, 2, 2, 3};

	test(a1, nelem(a1), 1.00000000);
	test(a2, nelem(a2), 0.20000000);
	test(a3, nelem(a3), 0.33333333);

	return 0;
}
