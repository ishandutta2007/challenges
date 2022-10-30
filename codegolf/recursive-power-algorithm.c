/*

Have a look at my (javascript) version of a O(log(n)) x^n algorithm:

function pow(x,n)
{
     return n==0?1:n==1?x:n==2?x*x:pow(pow(x,(n-n%2)/2),2)*(n%2==0?1:x);
}

Can you get it shorter?

*/

#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
ipow(uvlong x, uvlong n)
{
	uvlong s;

	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	if (n == 2)
		return x * x;

	s = (n & 1) ? x : 1;
	return s * ipow(ipow(x, (n - (n & 1)) / 2), 2);
}

int
main(void)
{
	uvlong i;

	for (i = 0; i <= 20; i++) {
		printf("%llu %llu %llu %llu %llu\n",
		       i, ipow(2, i), ipow(3, i), ipow(4, i), ipow(5, i));
	}

	return 0;
}
