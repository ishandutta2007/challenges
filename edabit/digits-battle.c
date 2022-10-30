/*

Starting from the left side of an integer, adjacent digits pair up in "battle" and the larger digit wins.
If two digits are the same, they both lose. A lone digit automatically wins.

Create a function that returns the victorious digits.

To illustrate:

battleOutcome(578921445) ➞ 7925
// [57]: 7 wins; [89] 9 wins; [21] 2 wins;
// [44] neither wins; 5 (automatically) wins

Examples

battleOutcome(32531) ➞ 351
// 3 deffeats 2, 5 defeats 3, 1 is a single.

battleOutcome(111) ➞ 1
// 1 and 1 tie, so neither move on, last 1 is a single.

battleOutcome(78925) ➞ 895

Notes

    There are no winners in a battle with equal digits (neither should be printed).
    If the length of the number is odd, the lone digit should be printed at the end of the number.

*/

#include <assert.h>
#include <stdio.h>
#include <inttypes.h>

uintmax_t
battle(uintmax_t x)
{
	char b[sizeof(x) * 8], p[sizeof(b)];
	int i, j, n;

	n = snprintf(b, sizeof(b), "%ju", x);
	for (i = j = 0; i + 1 < n; i += 2) {
		if (b[i] > b[i + 1])
			p[j++] = b[i];
		else if (b[i] < b[i + 1])
			p[j++] = b[i + 1];
	}
	if (i < n)
		p[j++] = b[n - 1];
	p[j] = '\0';

	return strtoumax(p, NULL, 10);
}

int
main(void)
{
	assert(battle(UINTMAX_C(32531)) == UINTMAX_C(351));
	assert(battle(UINTMAX_C(111)) == UINTMAX_C(1));
	assert(battle(UINTMAX_C(5289)) == UINTMAX_C(59));
	assert(battle(UINTMAX_C(76811)) == UINTMAX_C(781));
	assert(battle(UINTMAX_C(3245196)) == UINTMAX_C(3596));
	assert(battle(UINTMAX_C(93552129)) == UINTMAX_C(929));
	assert(battle(UINTMAX_C(3)) == UINTMAX_C(3));

	return 0;
}
