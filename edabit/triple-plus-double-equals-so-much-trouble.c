/*

Create a function that takes two integers and returns true if a number repeats three times in a row at any place in num1 AND that same number repeats two times in a row in num2.
Examples

trouble(451999277, 41177722899) ➞ true

trouble(1222345, 12345) ➞ false

trouble(666789, 12345667) ➞ true

trouble(33789, 12345337) ➞ false

Notes

You can expect every test case to contain exactly two integers.

*/

#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>

void
count(uintmax_t v, int d[10])
{
	int c, x, y;

	memset(d, 0, sizeof(*d) * 10);
	while (v) {
		c = 1;
		x = v % 10;
		for (;;) {
			v /= 10;
			y = v % 10;
			if (x != y)
				break;
			c++;
		}

		if (c >= 3)
			d[x] |= 0x2;
		if (c >= 2)
			d[x] |= 0x1;

		if (d[x] == 0x3)
			break;
	}
}

bool
trouble(uintmax_t a, uintmax_t b)
{
	int p[10], q[10], i;

	count(a, p);
	count(b, q);
	for (i = 0; i < 10; i++) {
		if ((p[i] & 0x1) && (q[i] & 0x2))
			return true;
		if ((p[i] & 0x2) && (q[i] & 0x1))
			return true;
	}

	return false;
}

int
main(void)
{
	assert(trouble(UINTMAX_C(451999277), UINTMAX_C(41177722899)) == true);
	assert(trouble(UINTMAX_C(444), UINTMAX_C(44)) == true);
	assert(trouble(UINTMAX_C(1222345), UINTMAX_C(12345)) == false);
	assert(trouble(UINTMAX_C(12345), UINTMAX_C(12345)) == false);
	assert(trouble(UINTMAX_C(888), UINTMAX_C(888)) == true);
	assert(trouble(UINTMAX_C(666789), UINTMAX_C(12345667)) == true);
	assert(trouble(UINTMAX_C(10560002), UINTMAX_C(100)) == true);
	assert(trouble(UINTMAX_C(1), UINTMAX_C(1)) == false);
	assert(trouble(UINTMAX_C(9111922229333339), UINTMAX_C(9559669779)) == false);

	return 0;
}
