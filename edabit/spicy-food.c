/*

The facts are:

    You've just finished dinner.
    You love spicy food but your friend hates it.

Given your friend's unfortunate taste preferences, you decide to split the bill only for non-spicy items. You will pay in full for the spicy dishes.

Given two ordered arrays, one classifying the dishes as spicy vs. non-spicy and the other listing their prices, write a function that outputs an array where the first element is how much you pay and the second element is how much your friend pays.

billSplit(["S", "N", "S", "S"], [13, 18, 15, 4]) ➞ [41, 9]

// Since:
// You pay: [13, 9, 15, 4] = 41
// Friend pays: [0, 9, 0, 0] = 9

Examples

billSplit(["N", "S", "N"], [10, 10, 20]) ➞ [25, 15]
// You pay for half of both "N" dishes (5 + 10) and entirely pay for the "S" dish (10).

billSplit(["N", "N"], [10, 10]) ➞ [10, 10]

billSplit(["S", "N"], [41, 10]) ➞ [46, 5]

Notes

    The dishes are in the same order for both input arrays.
    Remember to output an array in this order: [your payment, friend's payment]
    The array will contain at least one non-spicy dish N (you're not going to let your poor friend go hungry, are you?).
    Express both payments as integers.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
billsplit(const char *f, const int *b, size_t n, int p[2])
{
	double t[2], v;
	size_t i;

	t[0] = t[1] = 0;
	for (i = 0; i < n; i++) {
		if (f[i] == 'S')
			t[0] += b[i];
		else if (f[i] == 'N') {
			v = b[i] / 2.0;
			t[0] += v;
			t[1] += v;
		} else
			return -1;
	}
	p[0] = t[0];
	p[1] = t[1];
	return 0;
}

int
main(void)
{
	static const struct {
		size_t len;
		char type[32];
		int bill[32];
		int pay[2];
	} tab[] = {
		{ 4, { 'S', 'N', 'S', 'S' }, { 13, 18, 15, 4 }, { 41, 9 } },
		{ 3, { 'N', 'S', 'N' }, { 10, 10, 20 }, { 25, 15 } },
		{ 2, { 'N', 'N' }, { 10, 10 }, { 10, 10 } },
		{ 2, { 'S', 'N' }, { 41, 10 }, { 46, 5 } },
		{ 5, { 'S', 'S', 'S', 'N', 'N' }, { 8, 9, 8, 7, 7 }, { 32, 7 } },
		{ 4, { 'N', 'N', 'N', 'S' }, { 40, 20, 20, 10 }, { 50, 40 } },
	};

	size_t i;
	int p[2];

	for (i = 0; i < nelem(tab); i++) {
		assert(billsplit(tab[i].type, tab[i].bill, tab[i].len, p) == 0);
		assert(memcmp(p, tab[i].pay, sizeof(p)) == 0);
	}
	return 0;
}
