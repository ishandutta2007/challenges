/*

Among many of the Catland club kittens it is important to keep a paw on the pulse of the latest fashions and trends in order to stay hip.
When a new number is discovered in Catland, its coolness is primarily determined by its meow factor.
For a positive integer n, its meow factor is the largest integer m such that n is evenly divisible by m nine times (once for each life of a cat).
We say that n is divisible by m nine times if, starting with n, you can divide it by m without a remainder,
take the result of the division and again divide it by m without a remainder, and so on, dividing by m nine times in total.

While some cats are naturally chic and have an innate ability to see the meow factor of numbers,
others who struggle to stay in vogue can not even tell the difference between 3584 and 4711 (the former clearly having a higher meow factor).
Can you help those poor unfortunate cats lacking a sense of style, by writing a program to determine the meow factor of a number?

Input

The input contains a single integer n (1≤n≤2^63-1).

Output

Output the meow factor of n.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long uvlong;

uvlong
meowfactor(uvlong n)
{
	uvlong p, i;

	for (i = 128; i > 0; i--) {
		p = pow(i, 9);
		if (p <= n && n % p == 0)
			return i;
	}
	return 1;
}

int
main(void)
{
	assert(meowfactor(3584) == 2);
	assert(meowfactor(4711) == 1);

	return 0;
}
