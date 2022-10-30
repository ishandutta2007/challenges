/*

You have a pack of 5 randomly numbered cards, which can range from 0-9. You can win if you can produce a higher two-digit number from your cards, than your opponent. Return True if your cards win that round.

Worked Example

win_round([2, 5, 2, 6, 9], [3, 7, 3, 1, 2]) ➞ True
# Your cards can make the number 96
# Your opponent can make the number 73
# You win the round since 96 > 73

Examples

win_round([2, 5, 2, 6, 9], [3, 7, 3, 1, 2]) ➞ True

win_round([1, 2, 3, 4, 5], [9, 8, 7, 6, 5]) ➞ False

win_round([4, 3, 4, 4, 5], [3, 2, 5, 4, 1]) ➞ False

Notes

Return False if you and your opponent reach the same maximum number (see example #3).

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

unsigned
dmax(unsigned a[5])
{
	unsigned r[2];
	int i;

	r[0] = a[0];
	r[1] = 0;
	for (i = 1; i < 5; i++) {
		if (r[0] <= a[i]) {
			r[1] = r[0];
			r[0] = a[i];
		} else if (r[1] < a[i])
			r[1] = a[i];
	}
	return r[0] * 10 + r[1];
}

bool
won(unsigned a[5], unsigned b[5])
{
	return dmax(a) > dmax(b);
}

int
main(void)
{
	assert(won((unsigned[]){2, 5, 2, 6, 9}, (unsigned[]){3, 7, 3, 1, 2}) == true);
	assert(won((unsigned[]){1, 2, 3, 4, 5}, (unsigned[]){9, 8, 7, 6, 5}) == false);
	assert(won((unsigned[]){4, 3, 4, 4, 5}, (unsigned[]){3, 2, 5, 4, 1}) == false);
	assert(won((unsigned[]){3, 2, 8, 9, 4}, (unsigned[]){0, 7, 9, 3, 1}) == true);
	assert(won((unsigned[]){1, 4, 9, 2, 1}, (unsigned[]){3, 7, 7, 8, 7}) == true);
	assert(won((unsigned[]){6, 5, 5, 8, 5}, (unsigned[]){6, 2, 5, 2, 5}) == true);
	assert(won((unsigned[]){5, 3, 5, 9, 2}, (unsigned[]){5, 9, 2, 8, 0}) == false);
	assert(won((unsigned[]){3, 2, 0, 3, 5}, (unsigned[]){7, 5, 8, 6, 2}) == false);
	assert(won((unsigned[]){4, 1, 0, 2, 9}, (unsigned[]){3, 5, 5, 2, 8}) == true);
	assert(won((unsigned[]){9, 8, 7, 3, 4}, (unsigned[]){5, 3, 4, 7, 9}) == true);
	assert(won((unsigned[]){3, 3, 3, 9, 9}, (unsigned[]){9, 0, 0, 6, 6}) == true);
	assert(won((unsigned[]){3, 2, 8, 2, 0}, (unsigned[]){8, 5, 4, 5, 7}) == false);
	assert(won((unsigned[]){6, 2, 6, 8, 0}, (unsigned[]){7, 6, 3, 2, 9}) == false);
	assert(won((unsigned[]){8, 3, 5, 3, 5}, (unsigned[]){5, 5, 4, 4, 6}) == true);
	assert(won((unsigned[]){4, 0, 7, 7, 7}, (unsigned[]){8, 6, 7, 6, 3}) == false);
	assert(won((unsigned[]){5, 4, 8, 4, 8}, (unsigned[]){6, 6, 9, 3, 6}) == false);
	assert(won((unsigned[]){8, 1, 2, 6, 5}, (unsigned[]){2, 6, 7, 1, 8}) == false);
	assert(won((unsigned[]){9, 3, 8, 8, 6}, (unsigned[]){3, 1, 7, 9, 3}) == true);
	assert(won((unsigned[]){7, 2, 3, 0, 3}, (unsigned[]){1, 7, 9, 9, 9}) == false);
	assert(won((unsigned[]){2, 7, 4, 6, 5}, (unsigned[]){2, 3, 1, 5, 6}) == true);
	assert(won((unsigned[]){1, 7, 6, 3, 3}, (unsigned[]){8, 0, 7, 1, 1}) == false);
	assert(won((unsigned[]){5, 1, 6, 4, 7}, (unsigned[]){0, 7, 0, 1, 0}) == true);
	assert(won((unsigned[]){6, 0, 9, 5, 9}, (unsigned[]){4, 0, 3, 2, 5}) == true);
	assert(won((unsigned[]){1, 1, 7, 0, 5}, (unsigned[]){0, 0, 4, 7, 2}) == true);
	assert(won((unsigned[]){3, 3, 8, 3, 8}, (unsigned[]){8, 8, 4, 5, 5}) == false);
	assert(won((unsigned[]){4, 4, 2, 3, 4}, (unsigned[]){3, 6, 1, 5, 7}) == false);
	assert(won((unsigned[]){4, 0, 4, 0, 1}, (unsigned[]){2, 5, 1, 4, 1}) == false);
	assert(won((unsigned[]){5, 0, 1, 7, 5}, (unsigned[]){6, 9, 7, 2, 7}) == false);
	assert(won((unsigned[]){6, 1, 1, 4, 2}, (unsigned[]){6, 4, 7, 1, 2}) == false);
	assert(won((unsigned[]){8, 3, 5, 8, 4}, (unsigned[]){0, 8, 7, 8, 7}) == false);

	return 0;
}
