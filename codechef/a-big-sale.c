/*

Chef recently opened a big e-commerce website where her recipes can be bought online.
It's Chef's birthday month and so she has decided to organize a big sale in which grand discounts will be provided.

In this sale, suppose a recipe should have a discount of x percent and its original price (before the sale) is p.
Statistics says that when people see a discount offered over a product, they are more likely to buy it.
Therefore, Chef decides to first increase the price of this recipe by x% (from p) and then offer a discount of x% to people.

Chef has a total of N types of recipes. For each i (1 ≤ i ≤ N), the number of recipes of this type available for sale is quantityi,
the unit price (of one recipe of this type, before the x% increase) is pricei and the discount offered on each recipe of this type (the value of x) is discounti.

Please help Chef find the total loss incurred due to this sale, if all the recipes are sold out.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the number of recipe types.
N lines follow. The i-th of these lines contains three space-separated integers pricei, quantityi and discounti describing the i-th recipe type.

Output

For each test case, print a single line containing one real number — the total amount of money lost. Your answer will be considered correct if it has an absolute error less than 10-2.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
1 ≤ pricei, quantityi ≤ 100 for each valid i
0 ≤ discounti ≤ 100 for each valid i

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
amount(double a[][3], size_t n)
{
	double p, q, d;
	double r;
	size_t i;

	r = 0;
	for (i = 0; i < n; i++) {
		p = a[i][0];
		q = a[i][1];
		d = a[i][2];
		r += (d * d * p * q) / 10000;
	}
	return r;
}

void
test(double a[][3], size_t n, double r)
{
	double p;

	p = amount(a, n);
	printf("%.7f\n", p);
	assert(fabs(p - r) < 1e-7);
}

int
main(void)
{
	double a1[][3] = {
	    {100, 5, 10},
	    {100, 1, 50},
	};

	double a2[][3] = {
	    {10, 10, 0},
	    {79, 79, 79},
	    {100, 1, 100},
	};

	test(a1, nelem(a1), 30.000000000);
	test(a2, nelem(a2), 3995.0081000);

	return 0;
}
