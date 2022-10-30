/*

Given a positive integer n, output A076039(n)

from the OEIS.

That is, start with a(1)=1
Then for n>1

a(n) = n*a(n-1) if n > a(n-1)
       floor(a(n-1)/n) otherwise.

Test cases:

1 -> 1
2 -> 2 (2 > 1, so multiply)
3 -> 6 (3 > 2, so multiply)
4 -> 1 (4 < 6, so divide and take the integer part)
5 -> 5 
6 -> 30
17 -> 221
99 -> 12
314 -> 26

More test cases can be found on the OEIS page.

Per usual sequence rules, you can input and output in a generally accepted manner: 1- or 0-based indexing, output an infinite sequence, output the first n
values, output only the nth value, and so forth, but specify that in your answer.

This is code-golf, so shortest code in bytes in each language wins!

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
a(int n)
{
	int m;

	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;

	m = a(n - 1);
	return (n > m) ? n * m : m / n;
}

int
main(void)
{
	static const int tab[][2] = {
	    {1, 1},
	    {2, 2},
	    {3, 6},
	    {4, 1},
	    {5, 5},
	    {6, 30},
	    {17, 221},
	    {99, 12},
	    {314, 26},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(a(tab[i][0]) == tab[i][1]);

	return 0;
}
