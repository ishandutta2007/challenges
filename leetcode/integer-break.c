/*

Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

Note: You may assume that n is not less than 2 and not larger than 58.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

long
intbreakdp(long n)
{
	long *p, i, j, r;

	if (n <= 0)
		return 0;
	if (n <= 3)
		return n - 1;

	p = calloc(n + 1, sizeof(*p));
	if (!p)
		return -1;

	for (i = 0; i <= n; i++)
		p[i] = 1;

	for (i = 2; i < n; i++) {
		for (j = i; j <= n; j++)
			p[j] = max(p[j], p[j - i] * i);
	}

	r = p[n];
	free(p);
	return r;
}

// product is maximum when the splitted numbers are only 3s
// if numbers can't be splitted into only 3s, use one 4 or one 2
long
intbreakclosed(long n)
{
	if (n <= 0)
		return 0;
	if (n <= 3)
		return n - 1;
	if (n % 3 == 0)
		return pow(3, n / 3);
	if (n % 3 == 1)
		return 4 * pow(3, n / 3 - 1);
	return 2 * pow(3, n / 3);
}

int
main(void)
{
	long i;

	for (i = 0; i <= 58; i++)
		printf("%ld %ld %ld\n", i, intbreakdp(i), intbreakclosed(i));
	return 0;
}
