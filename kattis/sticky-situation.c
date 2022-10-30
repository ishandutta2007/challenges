/*

While on summer camp, you are playing a game of hide-and-seek in the forest.
You need to designate a “safe zone”, where, if the players manage to sneak there without being detected, they beat the seeker.
It is therefore of utmost importance that this zone is well-chosen.

You point towards a tree as a suggestion, but your fellow hide-and-seekers are not satisfied.
After all, the tree has branches stretching far and wide, and it will be difficult to determine whether a player has reached the safe zone.
They want a very specific demarcation for the safe zone. So, you tell them to go and find some sticks, of which you will use three to mark a non-degenerate triangle (i.e. with strictly positive area) next to the tree which will count as the safe zone.
After a while they return with a variety of sticks, but you are unsure whether you can actually form a triangle with the available sticks.

Can you write a program that determines whether you can make a triangle with exactly three of the collected sticks?

Input

The first line contains a single integer N, with 3≤N≤20000, the number of sticks collected.
Then follows one line with N positive integers, each less than 260, the lengths of the sticks which your fellow campers have collected.

Output

Output a single line containing a single word: possible if you can make a non-degenerate triangle with three sticks of the provided lengths, and impossible if you can not.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x > y)
		return 1;
	return 0;
}

const char *
nondegenerate(int *a, size_t n)
{
	size_t i;

	qsort(a, n, sizeof(*a), cmp);
	for (i = 2; i < n; i++) {
		if (a[i - 2] + a[i - 1] > a[i])
			return "possible";
	}
	return "impossible";
}

void
test(int *a, size_t n, const char *r)
{
	const char *p;

	p = nondegenerate(a, n);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	int a1[] = {1, 1, 1};
	int a2[] = {3, 1, 10, 5, 15};

	test(a1, nelem(a1), "possible");
	test(a2, nelem(a2), "impossible");

	return 0;
}
