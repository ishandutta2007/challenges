/*

The 50-30-20 strategy is a simple way to budget, which involves spending 50% of after-tax income on needs,
30% after tax income on wants, and 20% after-tax income on savings or paying off debt.

Given the after-tax income as ati, what you are supposed to do is to make a function that
will return an object that shows how much a person needs to spend on needs, wants, and savings.

Examples

fiftyThirtyTwenty(10000) ➞ { "Needs": 5000, "Wants": 3000, "Savings": 2000 }

fiftyThirtyTwenty(50000) ➞ { "Needs": 25000, "Wants": 15000, "Savings": 10000 }

fiftyThirtyTwenty(13450) ➞ { "Needs": 6725, "Wants": 4035, "Savings": 2690 }

Notes

N/A

*/

#include <assert.h>
#include <string.h>

void
strategy(unsigned m, unsigned r[3])
{
	r[0] = m * 0.5;
	r[1] = m * 0.3;
	r[2] = m * 0.2;
}

void
test(unsigned m, unsigned r[3])
{
	unsigned p[3];

	strategy(m, p);
	assert(memcmp(r, p, sizeof(p)) == 0);
}

int
main(void)
{
	test(10000, (unsigned[3]){5000, 3000, 2000});
	test(50000, (unsigned[3]){25000, 15000, 10000});
	test(13450, (unsigned[3]){6725, 4035, 2690});
	test(27800, (unsigned[3]){13900, 8340, 5560});
	test(19000, (unsigned[3]){9500, 5700, 3800});
	test(17610, (unsigned[3]){8805, 5283, 3522});
	test(25000, (unsigned[3]){12500, 7500, 5000});
	test(100000, (unsigned[3]){50000, 30000, 20000});
	test(347100, (unsigned[3]){173550, 104130, 69420});

	return 0;
}
