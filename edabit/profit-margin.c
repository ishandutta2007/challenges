/*

Create a function that calculates the profit margin given cost_price and sales_price.
Return the result as a percentage formated string, and rounded to one decimals.
To calculate profit margin you subtract the cost from the sales price, then divide by salesprice.

Examples

profit_margin(50, 50) ➞ "0.0%"

profit_margin(28, 39) ➞ "28.2%"

profit_margin(33, 84) ➞ "60.7%"

Notes

    Remember to return the result as a percentage formated string.
    Only one decimal should be included.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *
profitmargin(unsigned c, unsigned s, char *b, size_t n)
{
	double r;

	if (s == 0)
		return NULL;

	r = (s * 1.0 - c) * 100.0 / s;
	snprintf(b, n, "%.1f%%", r);
	return b;
}

void
test(unsigned c, unsigned s, const char *r)
{
	char b[128];

	profitmargin(c, s, b, sizeof(b));
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(50, 50, "0.0%");
	test(28, 39, "28.2%");
	test(33, 84, "60.7%");
	test(10, 15, "33.3%");
	test(75, 40, "-87.5%");
	test(55, 55, "0.0%");
	test(30, 50, "40.0%");
	test(9999, 10001, "0.0%");
	test(33, 84, "60.7%");

	return 0;
}
