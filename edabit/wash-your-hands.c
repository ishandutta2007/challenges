/*

It takes 21 seconds to wash your hands and help prevent the spread of COVID-19.

Create a function that takes the number of times a person washes their hands per day N and
the number of months they follow this routine nM and calculates the duration in minutes and seconds that person spends washing their hands.

Examples

wash_hands(8, 7) ➞ "588 minutes and 0 seconds"

wash_hands(0, 0) ➞ "0 minutes and 0 seconds"

wash_hands(7, 9) ➞ "661 minutes and 30 seconds"

Notes

    Consider a month has 30 days.
    Wash your hands.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
washhands(unsigned n, unsigned m, char *b, size_t l)
{
	unsigned s;

	s = n * 21 * m * 30;
	snprintf(b, l, "%u minutes and %u seconds", s / 60, s % 60);
	return b;
}

void
test(unsigned n, unsigned m, const char *r)
{
	char b[128];

	washhands(n, m, b, sizeof(b));
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(8, 7, "588 minutes and 0 seconds");
	test(0, 0, "0 minutes and 0 seconds");
	test(7, 9, "661 minutes and 30 seconds");
	test(20, 10, "2100 minutes and 0 seconds");
	test(0, 2, "0 minutes and 0 seconds");
	test(13, 3, "409 minutes and 30 seconds");
	test(1, 1, "10 minutes and 30 seconds");
	test(7, 0, "0 minutes and 0 seconds");

	return 0;
}
