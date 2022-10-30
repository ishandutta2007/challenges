/*

Create a function that counts how many n-digit numbers have the same sum of the first half and second half of the digits (“lucky” numbers).
The number n is even. For example, for n = 6, the numbers "001010", "112220", "000000" are lucky.

Examples

LuckyTicket(2) ➞ 10

LuckyTicket(4) ➞ 670

LuckyTicket(12) ➞ 39581170420

Notes

    There are checks for n > 10, so watch out for code performance.
    If you have problems finding a productive algorithm, look in the comments, there is one good person who explained the solution algorithm.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef unsigned long long uvlong;

uvlong
binomial(uvlong n, uvlong k)
{
	uvlong i, c;

	if (k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;

	k = min(k, n - k);
	c = 1;
	for (i = 0; i < k; i++)
		c = c * (n - i) / (i + 1);
	return c;
}

// https://oeis.org/A174061
uvlong
luckytickets(uvlong n)
{
	uvlong k, r;
	long s;

	n /= 2;
	s = 1;
	r = 0;
	for (k = 0; k < n; k++) {
		r += s * binomial(2 * n, k) * binomial(11 * n - 1 - 10 * k, 2 * n - 1);
		s = -s;
	}
	return r;
}

int
main(void)
{
	static const uvlong tab[][2] = {
	    {2, 10ull},
	    {4, 670ull},
	    {6, 55252ull},
	    {8, 4816030ull},
	    {10, 432457640ull},
	    {12, 39581170420ull},
	    {14, 3671331273480ull},
	};
	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(luckytickets(tab[i][0]) == tab[i][1]);

	return 0;
}
