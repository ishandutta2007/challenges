/*

This challenge, while probably trivial in most "standard" languages, is addressed to those languages which are so esoteric, low-level, and/or difficult to use that are very rarely seen on this site.
It should provide an interesting problem to solve, so this is your occasion to try that weird language you've read about!

The task
Take two natural numbers a and b as input, and output two other numbers: the result of the integer division a/b, and the remainder of such division (a%b).

This is code-golf: shortest answer (in bytes), for each language, wins!

Input/Output

0<=a<=255, 1<=b<=255. Each of your inputs (and outputs too) will fit in a single byte.
You may choose any format you like for both input and output, as long as the two numbers are clearly distinguishable (e.g. no printing the two results together without a delimiter)

Examples

a,b->division,remainder
5,7->0,5
5,1->5,0
18,4->4,2
255,25->10,5

Note: Builtins that return both the result of the division and the remainder are forbidden. At least show us how your language deals with applying two functions to the same arguments.

Note 2: As always, an explanation of how your code works is very welcome, even if it looks readable to you it may not be so for someone else!

*/

#include <assert.h>
#include <stdio.h>

int
div(int a, int b, int *q, int *r)
{
	if (b == 0)
		return 0;

	*q = a / b;
	*r = a % b;
	if (*r < 0)
		*r += b;
	return 1;
}

void
test(int a, int b, int rq, int rr)
{
	int q, r;

	assert(div(a, b, &q, &r));
	assert(q == rq);
	assert(r == rr);
}

int
main(void)
{
	test(5, 7, 0, 5);
	test(5, 1, 5, 0);
	test(18, 4, 4, 2);
	test(255, 25, 10, 5);

	return 0;
}
