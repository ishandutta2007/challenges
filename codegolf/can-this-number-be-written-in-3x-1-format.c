/*

Challenge:

Create a program that accepts a positive integer and checks if it can be written in the form of (3^x)-1, where X is another positive integer.

If it can, output X

If it can't, output -1 or a falsy statement.

Example inputs/outputs

Input:

2

It can be written as (3^1) - 1, so we output x which is 1

Output:

1

Input:

26

26 can be written as (3^3) - 1, so we output x (3)

Output:

3

Input:

1024

1024 can't be written in the form of (3^x) - 1, so we output -1

Output:

-1

This is code-golf so least amount of bytes wins

Related OEIS: A024023

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
is3xm1(int n)
{
	long p, v;

	p = log(n + 1) / log(3);
	v = pow(3, p) - 1;
	return (v == n) ? p : -1;
}

int
main(void)
{
	assert(is3xm1(2) == 1);
	assert(is3xm1(26) == 3);
	assert(is3xm1(1024) == -1);

	return 0;
}
