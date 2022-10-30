/*

Binomial transform is a transform on a finite or infinite integer sequence, which yields another integer sequence. The binomial transform of a sequence {an}

is given by

sn=∑k=0n(−1)k(nk)ak

It has an interesting property that applying the transform twice will yield the original, i.e. the transform is an involution.
Example

Take the sequence 1, 3, 9, 27, 81. The binomial transform of this sequence is computed as follows:

s0 = a0 = 1
s1 = a0 - a1 = -2
s2 = a0 - 2a1 + a2 = 4
s3 = a0 - 3a1 + 3a2 - a3 = -8
s4 = a0 - 4a1 + 6a2 - 4a3 + a4 = 16

So the binomial transform of 1, 3, 9, 27, 81 is 1, -2, 4, -8, 16. Verifying that the binomial transform of 1, -2, 4, -8, 16 is indeed 1, 3, 9, 27, 81 is left as an exercise to the reader.
Task

Compute the binomial transform of a given finite integer sequence.

Standard code-golf rules apply. The shortest code in bytes wins.
Test cases

Note that each test case works in both directions, i.e. if the left side is given as input, then the right side must be output, and vice versa.

[0] <-> [0]
[20, 21] <-> [20, -1]
[1, 3, 9, 27, 81] <-> [1, -2, 4, -8, 16]
[20, 21, 6, 15, 8, 48] <-> [20, -1, -16, -40, -80, -183]
[0, 1, 2, 3, 4, 5, 6] <-> [0, -1, 0, 0, 0, 0, 0]
[0, 1, 1, 2, 3, 5, 8, 13, 21]
    <-> [0, -1, -1, -2, -3, -5, -8, -13, -21]
[1, 1, 0, -1, -1, 0, 1, 1, 0, -1, -1, 0]
    <-> [1, 0, -1, -1, 0, 1, 1, 0, -1, -1, 0, 1]


*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

long
binomial(long n, long k)
{
	long i, c;

	if (k < 0 || k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;

	k = min(k, n - k);
	c = 1;
	for (i = 0; i < k; i++)
		c = c * (n - i) / (i + 1);
	return c;
}

void
transform(long *a, size_t n, long *p)
{
	size_t i, j;
	long r, s;

	for (i = 0; i < n; i++) {
		r = 0;
		s = 1;
		for (j = 0; j <= i; j++) {
			r += binomial(i, j) * a[j] * s;
			s = -s;
		}
		p[i] = r;
	}
}

void
test(long *a, long *b, size_t n)
{
	long p[128], q[128];

	transform(a, n, p);
	transform(p, n, q);
	assert(!memcmp(q, a, sizeof(*a) * n));
	assert(!memcmp(p, b, sizeof(*b) * n));
}

int
main(void)
{
	long a1[] = {1, 3, 9, 27, 81};
	long b1[] = {1, -2, 4, -8, 16};

	long a2[] = {0};
	long b2[] = {0};

	long a3[] = {20, 21};
	long b3[] = {20, -1};

	long a4[] = {20, 21, 6, 15, 8, 48};
	long b4[] = {20, -1, -16, -40, -80, -183};

	long a5[] = {0, 1, 2, 3, 4, 5, 6};
	long b5[] = {0, -1, 0, 0, 0, 0, 0};

	long a6[] = {0, 1, 1, 2, 3, 5, 8, 13, 21};
	long b6[] = {0, -1, -1, -2, -3, -5, -8, -13, -21};

	long a7[] = {1, 1, 0, -1, -1, 0, 1, 1, 0, -1, -1, 0};
	long b7[] = {1, 0, -1, -1, 0, 1, 1, 0, -1, -1, 0, 1};

	test(a1, b1, nelem(a1));
	test(a2, b2, nelem(a2));
	test(a3, b3, nelem(a3));
	test(a4, b4, nelem(a4));
	test(a5, b5, nelem(a5));
	test(a6, b6, nelem(a6));
	test(a7, b7, nelem(a7));

	return 0;
}
