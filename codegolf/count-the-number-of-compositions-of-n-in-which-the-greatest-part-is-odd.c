/*

A composition of an integer n is a representation of n as a sum of positive integers. For example the eight compositions of 4 are as follows:

4, 3 + 1, 1 + 3, 2 + 2, 2 + 1 + 1, 1 + 2 + 1, 1 + 1 + 2, 1 + 1 + 1 + 1.
The challenge is to output the number of compositions of n in which the greatest part is odd.

The sequence has generating function

Sum[0, Inf] ((1 - x)^2 * x^(2n - 1)) / ((1 - 2^x + x^(2n-1))*(1 - 2x + x^(2n)))

You only need to do this for n up to 33.

Your code should output the following numbers in order.

1 1
2 1
3 2
4 3
5 7
6 14
7 30
8 62
9 129
10 263
11 534
12 1076
13 2160
14 4318
15 8612
16 17145
17 34097
18 67764
19 134638
20 267506
21 531606
22 1056812
23 2101854
24 4182462
25 8327263
26 16588973
27 33066080
28 65945522
29 131588128
30 262702054
31 524699094
32 1048433468
33 2095744336
You only need to output the second column, not the first.

The numbers are taken directly from OEIS A103421 .

*/

#include <assert.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef unsigned long long uvlong;

uvlong
gen(uvlong n, uvlong m)
{
	uvlong i, r;

	r = 0;
	for (i = 0; i < n; i++)
		r += gen(i, max(m, n - i));
	return (r) ? r : m % 2;
}

/*

@xnor:

An exponential solution that implicitly generates all compositions by deciding at each branch how to split the current value n into the first part n-k and remaining parts adding to k.
Tracks the running maximum m, and when the initial n is exhausted, returns m%2 to indicate if the maximum part was odd.

*/

uvlong
composition(uvlong n)
{
	return gen(n, 0);
}

int
main(void)
{
	static const uvlong tab[] = {
	    1ULL,
	    1ULL,
	    2ULL,
	    3ULL,
	    7ULL,
	    14ULL,
	    30ULL,
	    62ULL,
	    129ULL,
	    263ULL,
	    534ULL,
	    1076ULL,
	    2160ULL,
	    4318ULL,
	    8612ULL,
	    17145ULL,
	    34097ULL,
	    67764ULL,
	    134638ULL,
	    267506ULL,
	    531606ULL,
	    1056812ULL,
	    2101854ULL,
	    4182462ULL,
	    8327263ULL,
	    16588973ULL,
	    33066080ULL,
	    65945522ULL,
	    131588128ULL,
	    262702054ULL,
	    524699094ULL,
	    1048433468ULL,
	    2095744336ULL,
	};

	uvlong i;

	for (i = 0; i < nelem(tab); i++)
		assert(composition(i + 1) == tab[i]);

	return 0;
}
