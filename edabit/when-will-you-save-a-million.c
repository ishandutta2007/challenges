/*

You landed your dream job. They pay in geometric progression (see resources).
In your first month of work, you will get your first paycheck firstMonth.
For every month after, your paycheck will be multiplier times bigger than the previous paycheck.

Create a function that takes the firstMonth's paycheck and the multiplier and returns the number of months it took for you to save up more than one million.
The problem assumes you save 100% of every paycheck.

Examples

millionInMonth(10, 2) ➞ 17

millionInMonth(100, 1.01) ➞ 464

millionInMonth(50, 100) ➞ 4
// Month 1 = 50 (paycheck 50)
// Month 2 = 5050 (paycheck 5,000 + 50 already saved)
// Month 3 = 505050 (paycheck 500,000 + 5,050 already saved)
// Month 4 = 50505050 (paycheck 50,000,000 + 505,050 already saved)

Notes

    Don't forget to return the result in the number of months.
    Return when your savings are greater than 1,000,000.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
million(unsigned p, double m)
{
	double u, v;
	int r;

	if (p == 0)
		return -1;

	v = 0;
	u = p;
	for (r = 0; v < 1e6; r++) {
		v += u;
		u *= m;
	}
	return r;
}

int
main(void)
{
	assert(million(10, 2) == 17);
	assert(million(5, 2) == 18);
	assert(million(2, 5) == 10);
	assert(million(20, 4) == 9);
	assert(million(50, 100) == 4);
	assert(million(1, 1.01) == 926);
	assert(million(15, 2) == 17);
	assert(million(20, 2) == 16);
	assert(million(100, 1.1) == 73);
	assert(million(100, 1.01) == 464);
	assert(million(666, 6) == 5);
	assert(million(11, 11) == 6);
	assert(million(1, 2) == 20);
	assert(million(2, 2) == 19);
	assert(million(3, 2) == 19);
	assert(million(4, 2) == 18);
	assert(million(5, 2) == 18);

	return 0;
}
