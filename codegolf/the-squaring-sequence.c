/*

Each term in the squaring sequence, xn, is created by taking xn−1, squaring it, and removing all but the first four digits.

The sequence always begins with x1=1111. Squaring this yields 1234321, so x2=1234

The first few terms are:

1111
1234
1522
2316
5363
...
The Challenge
Your task is to, given a non-negative integer n, calculate xn. You may submit a full program which performs I/O, or a function which takes n as a parameter.

Your solution can be zero or one indexed, as long as you specify which.

Because all the terms in this sequence are shorter than 5 digits, your code should be as short as possible too. Standard code-golf loopholes apply.

May the best golfer win!

Test Cases
Note: These are 1-indexed.

1   -> 1111
8   -> 6840
15  -> 7584
20  -> 1425
80  -> 4717

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
rev(uvlong n)
{
	uvlong r;

	for (r = 0; n; n /= 10)
		r = (r * 10) + (n % 10);
	return r;
}

uvlong
next(uvlong n)
{
	uvlong r;

	r = rev(n * n);
	r = rev(r % 10000);
	while (r && r < 1000)
		r *= 10;
	return r;
}

uvlong
seq(uvlong n)
{
	uvlong i, r;

	r = 1111;
	for (i = 1; i < n; i++)
		r = next(r);
	return r;
}

int
main(void)
{
	assert(seq(1) == 1111);
	assert(seq(2) == 1234);
	assert(seq(3) == 1522);
	assert(seq(4) == 2316);
	assert(seq(5) == 5363);
	assert(seq(8) == 6840);
	assert(seq(15) == 7584);
	assert(seq(20) == 1425);
	assert(seq(80) == 4717);

	return 0;
}
