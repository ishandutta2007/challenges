/*

Given i=sqrt(-1), a base-(i-1)) binary number N with n binary digits from d[0] to d[n-1] satisfies the following equation.

N = d[n-1]*(i-1)^(n-1) + d[n-2]*(i-1)^(n-2) + ... d[1]*(i-1) + d[0]

For example, a decimal number 15 is 100011101 in base-(i−1) since,

(i−1)^(9-1) + (i−1)^(5−1) + (i−1)^(4−1) + (i−1)^(3−1) + (i−1)^(1−1) = 16 + (−4) + (2+2i) + (−2i) + 1 = 15

This is a list of 0 to 9 converted to base-(i−1).

0         0
1         1
2      1100
3      1101
4 111010000
5 111010001
6 111011100
7 111011101
8 111000000
9 111000001
Given a decimal integer as input, convert the input to a base-(i−1) binary number, which is then converted again to decimal as output.

For example,

 15 -> 100011101 -> 285
(in)               (out)
You may assume that the input is always ≥0, and the output will fit in the range of [0,2^31).

Test cases
0 -> 0
1 -> 1
2 -> 12
3 -> 13
4 -> 464
5 -> 465
6 -> 476
7 -> 477
8 -> 448
9 -> 449
2007 -> 29367517
9831 -> 232644061

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
mod(vlong x, vlong m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

// http://oeis.org/A066321
vlong
f(vlong n)
{
	static const vlong tab[] = {0, 1, 12, 13};

	if (n == 0)
		return 0;
	return (16 * f(-floor(n / 4.0))) + tab[mod(n, 4)];
}

int
main(void)
{
	static const vlong tab[] = {
	    0,
	    1,
	    12,
	    13,
	    464,
	    465,
	    476,
	    477,
	    448,
	    449,
	    460,
	    461,
	    272,
	    273,
	    284,
	    285,
	    256,
	    257,
	    268,
	    269,
	    3280,
	    3281,
	    3292,
	    3293,
	    3264,
	    3265,
	    3276,
	    3277,
	    3088,
	    3089,
	    3100,
	    3101,
	    3072,
	    3073,
	    3084,
	    3085,
	    3536,
	    3537,
	    3548,
	    3549,
	    3520,
	    3521,
	    3532,
	    3533,
	    3344,
	    3345,
	    3356,
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(f(i) == tab[i]);

	assert(f(2007) == 29367517LL);
	assert(f(9831) == 232644061LL);

	return 0;
}
