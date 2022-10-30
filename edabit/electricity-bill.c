/*

Create a function that takes number of units consumed by the customer and returns calculated Electricity Bill as per following conditions:

    First 100 Units will be charged at $1/unit.
    Next 100 Units will be charged at $2/unit.
    Next 100 Units will be charged at $3/unit.
    Next 200 Units will be charged at $4/unit.
    Next Units will be charged at $5/unit.
    10% tax to be added in final amount.
    Extra $15 to be added for Meter Charge.

Examples

electricityBill(100) ➞ 125
// 100 units at $1/unit = 100,
// 10% Tax = 10,
// $15 for Meter Charge = 15,
// Electricity Bill = 100 + 10 + 15

electricityBill(225) ➞ 427.5
// 100 units at $1/unit = 100, 100 units at $2/unit = 200, 25 units at $3/unit = 75
// 10% Tax = 37.5,
// 15$ for Meter Charge = 15,
// Electricity Bill = 100 + 200 + 75 + 22.5 + 15 = 427.50

electricityBill(300) ➞ 675
// 100 units at $1/unit = 100, 100 units at $2/unit = 200, 100 units at $3/unit = 300
// 10% Tax = 60,
// 15$ for Meter Charge = 15,
// Electricity Bill = 100 + 200 + 300 + 60 + 15 = 675

Notes

Return final calculated Electricity Bill rounded up to two decimal places.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

double
clamp(double x, double a, double b)
{
	if (x < a)
		return a;
	if (x > b)
		return b;
	return x;
}

double
ebill(double u)
{
	static const double tab[] = {
	    100,
	    100,
	    100,
	    200,
	};

	double r;
	size_t i;

	r = 0;
	for (i = 0; i < nelem(tab); i++) {
		r += clamp(u, 0, tab[i]) * (i + 1);
		u -= tab[i];
	}
	r += max(0, u) * (i + 1);
	r = (r * 1.1) + 15;

	return r;
}

void
test(double n, double r)
{
	assert(fabs(ebill(n) - r) < 1e-2);
}

int
main(void)
{
	test(100, 125);
	test(225, 427.5);
	test(300, 675);
	test(500, 1555);
	test(1000, 4305);
	test(133.17, 197.98);
	test(33.31, 51.65);
	test(471.67, 1430.35);
	test(532.56, 1734.08);
	test(111.11, 149.45);

	return 0;
}
