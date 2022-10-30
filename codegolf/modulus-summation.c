/*

I call this sequence "the Jesus sequence", because it is the sum of mod.</pun>

For this sequence, you take all the positive integers m less than the input n, and take the sum of n modulo each m. In other words:

an=∑m=1n−1nmodm

For example, take the term 14:

14 % 1 = 0
14 % 2 = 0
14 % 3 = 2
14 % 4 = 2
14 % 5 = 4
14 % 6 = 2
14 % 7 = 0
14 % 8 = 6
14 % 9 = 5
14 % 10 = 4
14 % 11 = 3
14 % 12 = 2
14 % 13 = 1
0+0+2+2+4+2+0+6+5+4+3+2+1=31

Your goal here is to write a function that implements this sequence. You should take the sequence term (this will be a positive integer from 1 to 231) as the only input, and output the value of that term. This is OEIS A004125.

As always, standard loopholes apply and the shortest answer in bytes wins!

*/

#include <stdio.h>

typedef unsigned long long uvlong;

// https://oeis.org/A004125
uvlong
modsum(uvlong n)
{
	uvlong i, r;

	r = 0;
	for (i = 1; i < n; i++)
		r += n % i;
	return r;
}

int
main(void)
{
	uvlong i;

	for (i = 1; i < 100; i++)
		printf("%llu\n", modsum(i));

	return 0;
}
