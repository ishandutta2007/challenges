/*

In India, every individual is charged with income tax on the total income each year.
This tax is applied to specific ranges of income, which are called income tax slabs.
The slabs of income tax keep changing from year to year. This fiscal year (2020-21), the tax slabs and their respective tax rates are as follows:

Total income (in rupees)	Tax rate

up to Rs. 250,000	0%
from Rs. 250,001 to Rs. 500,000	5%
from Rs. 500,001 to Rs. 750,000	10%
from Rs. 750,001 to Rs. 1,000,000	15%
from Rs. 1,000,001 to Rs. 1,250,000	20%
from Rs. 1,250,001 to Rs. 1,500,000	25%
above Rs. 1,500,000	30%

See the sample explanation for details on how the income tax is calculated.

You are given Chef's total income: N rupees (Rs.). Find his net income.
The net income is calculated by subtracting the total tax (also called tax reduction) from the total income.
Note that you do not need to worry about any other kind of tax reductions, only the one described above.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.

Output

For each test case, print a single line containing one integer — Chef's net income.

Constraints
1≤T≤10^3
0≤N≤10^7
N is a multiple of 100

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef unsigned long long uvlong;

uvlong
income(uvlong n)
{
	static const uvlong tab[][3] = {
	    {250000ULL, 500000ULL, 5},
	    {500000ULL, 750000ULL, 10},
	    {750000ULL, 1000000ULL, 15},
	    {1000000ULL, 1250000ULL, 20},
	    {1250000ULL, 1500000ULL, 25},
	    {1500000ULL, ULLONG_MAX, 30},
	};

	uvlong r, s, t;
	size_t i;

	r = 0;
	for (i = 0; i < nelem(tab); i++) {
		if (n <= tab[i][0])
			break;

		s = min(n, tab[i][1]) - tab[i][0];
		t = (s / 100) * tab[i][2];
		r += t;
	}
	return n - r;
}

int
main(void)
{
	assert(income(600000ULL) == 577500ULL);
	assert(income(250000ULL) == 250000ULL);

	return 0;
}
