/*

At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you, and order one at a time (in the order specified by bills).

Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.
You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Return true if and only if you can provide every customer with correct change.

Examples

lemonade([5, 5, 5, 10, 20]) ➞ true

lemonade([5, 5, 10, 10, 20]) ➞ false

lemonade([10, 10]) ➞ false

lemonade([5, 5, 10]) ➞ true

Notes

    You don't have any change in hand at first.
    bills is an integer array.
    bills[i] will be either 5, 10, or 20.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
refund(unsigned v, size_t i, unsigned p[3])
{
	static const unsigned tab[] = {
	    5,
	    10,
	    20,
	};

	for (v -= 5; v && i; i--) {
		while (v >= tab[i - 1] && p[i - 1]) {
			v -= tab[i - 1];
			p[i - 1]--;
		}
	}
	p[i]++;
	return v == 0;
}

bool
lemonade(unsigned *a, size_t n)
{
	unsigned p[3];
	size_t i;

	memset(p, 0, sizeof(p));
	for (i = 0; i < n; i++) {
		switch (a[i]) {
		case 5:
		case 10:
		case 20:
			if (!refund(a[i], a[i] / 10, p))
				return false;
			break;
		default:
			return false;
		}
	}
	return true;
}

int
main(void)
{
	unsigned a1[] = {5, 5, 5, 10, 20};
	unsigned a2[] = {5, 5, 10};
	unsigned a3[] = {10, 10};
	unsigned a4[] = {5, 5, 5, 20};
	unsigned a5[] = {5, 5, 10, 10, 20};
	unsigned a6[] = {5, 5, 5, 5, 10, 5, 10, 10, 10, 20};
	unsigned a7[] = {5, 10, 5, 5, 5, 20, 5, 10, 5, 5, 10, 20};
	unsigned a8[] = {5, 10, 5, 5, 5, 20, 5, 10, 20, 5, 10, 20, 10};

	assert(lemonade(a1, nelem(a1)) == true);
	assert(lemonade(a2, nelem(a2)) == true);
	assert(lemonade(a3, nelem(a3)) == false);
	assert(lemonade(a3, nelem(a3)) == false);
	assert(lemonade(a4, nelem(a4)) == true);
	assert(lemonade(a5, nelem(a5)) == false);
	assert(lemonade(a6, nelem(a6)) == true);
	assert(lemonade(a7, nelem(a7)) == true);
	assert(lemonade(a8, nelem(a8)) == false);

	return 0;
}
