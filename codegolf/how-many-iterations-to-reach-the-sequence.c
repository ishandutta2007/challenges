/*

Let's define a function f which, given a positive integer x, returns the sum of:

x
the smallest digit in the decimal representation of x
the highest digit in the decimal representation of x

    (which may be the same as the smallest one)

For instance:

    f(1)=1+1+1=3

f(135)=135+1+5=141
f(209)=209+0+9=218

We now define the sequence ak=fk(1). That is to say:

a1=1
ak=f(ak−1)
for k>1

The first few terms are:

1, 3, 9, 27, 36, 45, 54, 63, 72, 81, 90, 99, 117, 125, 131, 135, 141, 146, ...

Challenge

Given a positive integer x, you must return the smallest n such that fn(x) belongs to the sequence. Or in other words: how many times f should be applied consecutively to turn x

into a term of the sequence.

You can assume that you'll never be given an input for which no solution exists. (Although I suspect that this can't happen, I didn't attempt to prove it.)

You may also use 1-based indices (returning n+1 instead of n). Please make it clear in your answer if you do so.

Standard code-golf rules apply.
Examples

    Given x=45, the answer is 0 because x is already a term of the sequence (a6=45).
Given x=2, the answer is 3 because 3 iterations are required: f(2)=2+2+2=6, f(6)=6+6+6=18, f(18)=18+1+8=27=a4. Or more concisely: f3(2)=27.

(These are the 0-based results. The answers would be 1 and 4 respectively if 1-based indices are used.)

Test cases

Input : 0-based output

1     : 0
2     : 3
4     : 15
14    : 16
18    : 1
45    : 0
270   : 0
465   : 67
1497  : 33

*/

#include <stdio.h>
#include <limits.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef unsigned long long uvlong;

void
digits(uvlong n, uvlong *lo, uvlong *hi)
{
	uvlong v;

	*lo = ULLONG_MAX;
	*hi = 0;
	do {
		v = n % 10;
		*lo = min(*lo, v);
		*hi = max(*hi, v);
	} while (n /= 10);
}

uvlong
f(uvlong x)
{
	uvlong a, b;

	digits(x, &a, &b);
	return x + a + b;
}

uvlong
seq(uvlong n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return f(seq(n - 1));
}

int
main(void)
{
	uvlong i;

	for (i = 1; i < 1000; i++)
		printf("%llu\n", seq(i));

	return 0;
}
