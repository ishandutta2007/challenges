/*

Steve and Maurice have racing snails. They each have three, a slow s, medium m and fast f one. Although Steve's snails are all a bit stronger than Maurice's, Maurice has a trick up his sleeve. His plan is

    Round 1: [s, f] Sacrifice his slowest snail against Steve's fastest.
    Round 2: [m, s] Use his middle snail against Steve's slowest.
    Round 3: [f, m] Use his fastest snail against Steve's middle.

Create a function that determines whether Maurice's plan will work by outputting true if Maurice wins 2/3 games.

The function inputs:

    Array 1: [s, m, f] for Maurice.
    Array 2: [s, m, f] for Steve.

Examples

mauriceWins([3, 5, 10], [4, 7, 11]) ➞ true
// Since the matches are (3, 11), (5, 4) and (10, 7), Maurice wins 2 out of 3.

mauriceWins([6, 8, 9], [7, 12, 14]) ➞ false
// Since the matches are (6, 14), (8, 7) and (9, 12), Steve wins 2 out of 3.

mauriceWins([1, 8, 20], [2, 9, 100]) ➞ true

Notes

    Maurice wins if his competing snail's speed strictly exceeds Steve's snail's speed.
    Steve will always play in this order: [f, s, m].
    The order you'll get the snails is always in ascending order.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
win(int a[3], int b[3])
{
	int r;

	r = a[0] > b[2];
	r += a[1] > b[0];
	r += a[2] > b[1];
	return r >= 2;
}

int
main(void)
{
	int a1[] = {3, 5, 10};
	int b1[] = {4, 7, 11};

	int a2[] = {6, 8, 9};
	int b2[] = {7, 12, 14};

	int a3[] = {1, 8, 20};
	int b3[] = {2, 9, 100};

	int a4[] = {1, 2, 3};
	int b4[] = {2, 3, 4};

	int a5[] = {2, 4, 10};
	int b5[] = {3, 9, 11};

	int a6[] = {3, 8, 13};
	int b6[] = {5, 11, 15};

	assert(win(a1, b1) == true);
	assert(win(a2, b2) == false);
	assert(win(a3, b3) == true);
	assert(win(a4, b4) == false);
	assert(win(a5, b5) == true);
	assert(win(a6, b6) == true);

	return 0;
}
