/*

The plus-minus sequence
The plus-minus sequence is one that starts with two seeds, a(0) and b(0).
Each iteration of this sequence is the addition and subtraction of the previous two members of the sequence.
That is, a(N) = a(N-1) + b(N-1) and b(N) = a(N-1) - b(N-1).

Objective Produce the plus-minus sequence, in infinitude or the first K steps given K. You may do this using an infinite output program, a generator, or a function/program that gives the first K steps.
The output order does not matter, so long as it is consistent. (I.e., b(K) a(K) or a(K) b(K), with some non-numeric, non-newline separator in between.) The output must start with the input.

Test cases
For inputs 10 2 (of a(0) b(0), this is a possible output for the first K approach (or a subsection of the infinite approach):

10     2
12     8
20     4
24     16
40     8
48     32
80     16
96     64
160    32
192    128
320    64
384    256
640    128
768    512
1280   256
1536   1024
2560   512
3072   2048
5120   1024
6144   4096
10240  2048
12288  8192
20480  4096
24576  16384
40960  8192
49152  32768
81920  16384
98304  65536
For inputs 2 20 10 (a(0) b(0) k):

2     20
22   -18
4     40
44   -36
8     80
88   -72
16    160
176  -144
32    320
352  -288

*/

#include <stdio.h>

typedef long long vlong;

void
next(vlong *a, vlong *b)
{
	vlong xa, xb;

	xa = *a + *b;
	xb = *a - *b;
	*a = xa;
	*b = xb;
}

void
test(vlong a, vlong b, vlong k)
{
	vlong i;

	for (i = 0; i < k; i++) {
		printf("%lld %lld\n", a, b);
		next(&a, &b);
	}
	printf("\n");
}

int
main(void)
{
	test(10, 2, 28);
	test(2, 20, 10);

	return 0;
}
