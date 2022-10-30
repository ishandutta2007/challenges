/*

The exponential generating function (e.g.f.) of a sequence an is defined as the formal power series f(x) = sum [n=0,inf] a[n]/n! * x^n.

When a0=0, we can apply the exponential function exp on this formal power series:

exp(f(x)) = sum[n=0, inf] b[n]/n! * x^n

where
b[0] = 1
b[n] = sum[k=1, n] comb(n-1, k-1)*a[k]*b[n-k] when n > 0

This is the exponential generating function of the sequence b[n]. If all an are integers, then all bn are also integers. So this is a tranformation of integer sequences.

It seems that OEIS call this the Exponential transform. But I can't find a reference to its definition.

Here are some examples on OEIS:

A001477 (the nonnegative integers, 0,1,2,3,4,…) -> A000248 (1,1,3,10,41,…)
A001489 (the nonpositive integers, 0,−1,−2,−3,−4,…) -> A292952 (1,−1,−1,2,9,…)
A000045 (Fibonacci numbers, 0,1,1,2,3,…) -> A256180 (1,1,2,6,21,…)
A160656 (0 and the odd primes, 0,3,5,7,11,…) -> A353079 (1,3,14,79,521,…)
A057427 (0,1,1,1,1,…) -> A000110 (Bell numbers, 1,1,2,5,15,…)
Task
Given a finite integer sequence, compute its Exponential transform.

The length of the input sequence is always greater than 0. Its 0th term is always 0.

If the input sequence has length n, you only need to output the first n terms of the output sequence.

Input and output can be in any reasonable format, e.g., a list, an array, a polynomial, a function that takes i and returns the ith term (0-indexed or 1-indexed), etc.

You may also take the input sequence and an integer i, and output the ith term (0-indexed or 1-indexed) of the output sequence.

This is code-golf, so the shortest code in bytes wins.

Example Python code
This example code uses the above recurrence formula. There are other formulas that might give shorter answers.

import math

def exponential_transform(a):
    b = [0] * len(a)
    b[0] = 1
    for i in range(1, len(a)):
        b[i] = sum(math.comb(i-1, j-1) * a[j] * b[i - j] for j in range(1, i + 1))
    return b

Testcases
[0, 0, 0, 0, 0] -> [1, 0, 0, 0, 0]
[0, 1, 0, -1, 0, 1, 0, -1] -> [1, 1, 1, 0, -3, -8, -3, 56]
[0, 1, 2, 3, 4, 5, 6, 7] -> [1, 1, 3, 10, 41, 196, 1057, 6322]
[0, -1, -2, -3, -4, -5, -6, -7] -> [1, -1, -1, 2, 9, 4, -95, -414]
[0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55] -> [1, 1, 2, 6, 21, 86, 404, 2121, 12264, 77272, 525941]
[0, 3, 5, 7, 11, 13, 17, 19] -> [1, 3, 14, 79, 521, 3876, 31935, 287225]
[0, 1, 1, 1, 1, 1] -> [1, 1, 2, 5, 15, 52]
[0, 1, 2, 5, 15, 52] -> [1, 1, 3, 12, 60, 358]
[0, 1, 3, 12, 60, 358] -> [1, 1, 4, 22, 154, 1304]
[0, 1, 4, 22, 154, 1304] -> [1, 1, 5, 35, 315, 3455]
[0, 1, 5, 35, 315, 3455] -> [1, 1, 6, 51, 561, 7556]

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
dump(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int
factorial(int n)
{
	int i, v;

	v = 1;
	for (i = 2; i <= n; i++)
		v *= i;
	return v;
}

int
comb(int n, int r)
{
	return factorial(n) / (factorial(r) * factorial(n - r));
}

void
exponential_transform(int *a, int *b, size_t n)
{
	size_t i, j;
	int v;

	if (n == 0)
		return;

	memset(b, 0, sizeof(*b) * n);
	b[0] = 1;
	for (i = 1; i < n; i++) {
		v = 0;
		for (j = 1; j < i + 1; j++)
			v += comb(i - 1, j - 1) * a[j] * b[i - j];
		b[i] = v;
	}
}

void
test(int *a, int *b, size_t n)
{
	int p[128];

	exponential_transform(a, p, n);
	dump(p, n);
	assert(!memcmp(p, b, sizeof(*b) * n));
}

int
main(void)
{
	int a1[] = {0, 0, 0, 0, 0};
	int b1[] = {1, 0, 0, 0, 0};

	int a2[] = {0, 1, 0, -1, 0, 1, 0, -1};
	int b2[] = {1, 1, 1, 0, -3, -8, -3, 56};

	int a3[] = {0, 1, 2, 3, 4, 5, 6, 7};
	int b3[] = {1, 1, 3, 10, 41, 196, 1057, 6322};

	int a4[] = {0, -1, -2, -3, -4, -5, -6, -7};
	int b4[] = {1, -1, -1, 2, 9, 4, -95, -414};

	int a5[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
	int b5[] = {1, 1, 2, 6, 21, 86, 404, 2121, 12264, 77272, 525941};

	int a6[] = {0, 3, 5, 7, 11, 13, 17, 19};
	int b6[] = {1, 3, 14, 79, 521, 3876, 31935, 287225};

	int a7[] = {0, 1, 1, 1, 1, 1};
	int b7[] = {1, 1, 2, 5, 15, 52};

	int a8[] = {0, 1, 2, 5, 15, 52};
	int b8[] = {1, 1, 3, 12, 60, 358};

	int a9[] = {0, 1, 3, 12, 60, 358};
	int b9[] = {1, 1, 4, 22, 154, 1304};

	int a10[] = {0, 1, 4, 22, 154, 1304};
	int b10[] = {1, 1, 5, 35, 315, 3455};

	int a11[] = {0, 1, 5, 35, 315, 3455};
	int b11[] = {1, 1, 6, 51, 561, 7556};

	test(a1, b1, nelem(b1));
	test(a2, b2, nelem(b2));
	test(a3, b3, nelem(b3));
	test(a4, b4, nelem(b4));
	test(a5, b5, nelem(b5));
	test(a6, b6, nelem(b6));
	test(a7, b7, nelem(b7));
	test(a8, b8, nelem(b8));
	test(a9, b9, nelem(b9));
	test(a10, b10, nelem(b10));
	test(a11, b11, nelem(b11));

	return 0;
}
