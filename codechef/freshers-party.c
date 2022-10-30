/*

You're organising fresher's party today.
You're expecting 'n' freshers and you've already arranged 'm' beer cans.
You want to distribute all the beers among your juniors in such a way that each fresher receives the same number of beer cans.
Note you cannot divide a beer can into halves. Find the minimum number of additional beer cans you must buy so that each fresher receives same number of beer cans. 

*/

#include <stdio.h>

unsigned
more(unsigned n, unsigned m)
{
	if (n == 0)
		return 0;
	if (m <= n)
		return n - m;
	if (m % n == 0)
		return 0;
	return n - (m % n);
}

int
main(void)
{
	printf("%u\n", more(5, 3));
	printf("%u\n", more(10, 5));
	printf("%u\n", more(10, 6));
	printf("%u\n", more(13, 2));
	printf("%u\n", more(23, 23));
	printf("%u\n", more(4, 8));
	printf("%u\n", more(5, 13));
	printf("%u\n", more(5, 16));
	printf("%u\n", more(2, 16));
	printf("%u\n", more(29, 3));
	printf("%u\n", more(290, 300));
	return 0;
}
