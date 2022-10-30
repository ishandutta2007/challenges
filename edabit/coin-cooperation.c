/*

Let's say that there exists a machine that gives out free coins, but with a twist!

Separating two people is a wall, and this machine is placed in such a way that both people are able to access it.
Spending a coin in this machine will give the person on the other side 3 coins and vice versa.

If both people continually spend coins for each other (SHARING), then they'll both gain a net profit of 2 coins per turn.
However, there is always the possibility for someone to act selfishly (STEALING): they spend no coins, yet they still receive the generous 3 coin gift from the other person!

Here's an example of Red taking advantage of Green! Red chose to betray

The Challenge

Assuming that both people start with 3 coins each, create a function that calculates both people's final number of coins. You will be given two arrays of strings, with each string being the words "share" or "steal".

Examples

getCoinBalances(["share"], ["share"]) ➞ [5, 5]
// Both people spend one coin, and receive 3 coins each.

getCoinBalances(["steal"], ["share"]) ➞ [6, 2]
// Person 1 gains 3 coins, while person 2 loses a coin.

getCoinBalances(["steal"], ["steal"]) ➞ [3, 3]
// Neither person spends any coins and so no one gets rewarded.

getCoinBalances(["share", "share", "share"], ["steal", "share", "steal"]) ➞ [3, 11]

Notes

    No tests will include a negative number of coins.
    All words will be given in lowercase.
    This challenge is adapted from a famous game theory example called the Prisoner's Dilemma, which you can learn more about in the Resources tab.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
change(const char *s, unsigned *x, unsigned *y)
{
	if (!strcmp(s, "share") && *x) {
		*x -= 1;
		*y += 3;
	}
}

void
balance(const char **s, const char **t, size_t n, unsigned r[2])
{
	size_t i;

	r[0] = r[1] = 3;
	for (i = 0; i < n; i++) {
		change(s[i], &r[0], &r[1]);
		change(t[i], &r[1], &r[0]);
	}
}

void
test(const char **s, const char **t, size_t n, unsigned r[2])
{
	unsigned p[2];

	balance(s, t, n, p);
	printf("%u %u\n", p[0], p[1]);
	assert(!memcmp(r, p, sizeof(p)));
}

int
main(void)
{
	const char *s1[] = {"share"};
	const char *t1[] = {"share"};
	unsigned r1[] = {5, 5};

	const char *s2[] = {"steal"};
	const char *t2[] = {"share"};
	unsigned r2[] = {6, 2};

	const char *s3[] = {"share"};
	const char *t3[] = {"steal"};
	unsigned r3[] = {2, 6};

	const char *s4[] = {"steal"};
	const char *t4[] = {"steal"};
	unsigned r4[] = {3, 3};

	const char *s5[] = {"share", "share", "share"};
	const char *t5[] = {"steal", "share", "steal"};
	unsigned r5[] = {3, 11};

	const char *s6[] = {"share", "share", "steal", "share"};
	const char *t6[] = {"steal", "steal", "steal", "steal"};
	unsigned r6[] = {0, 12};

	const char *s7[] = {"steal", "steal", "steal"};
	const char *t7[] = {"share", "share", "share"};
	unsigned r7[] = {12, 0};

	const char *s8[] = {"share", "share"};
	const char *t8[] = {"share", "share"};
	unsigned r8[] = {7, 7};

	const char *s9[] = {"share", "steal", "steal", "steal"};
	const char *t9[] = {"share", "share", "steal", "share"};
	unsigned r9[] = {11, 3};

	const char *s10[] = {"share", "share", "steal", "share"};
	const char *t10[] = {"steal", "share", "steal", "steal"};
	unsigned r10[] = {3, 11};

	const char *s11[] = {"steal", "steal", "steal", "steal"};
	const char *t11[] = {"steal", "steal", "steal", "steal"};
	unsigned r11[] = {3, 3};

	const char *s12[] = {"steal", "share", "steal", "steal"};
	const char *t12[] = {"share", "share", "steal", "steal"};
	unsigned r12[] = {8, 4};

	const char *s13[] = {"steal", "steal"};
	const char *t13[] = {"share", "share"};
	unsigned r13[] = {9, 1};

	const char *s14[] = {"steal", "share"};
	const char *t14[] = {"share", "steal"};
	unsigned r14[] = {5, 5};

	test(s1, t1, nelem(s1), r1);
	test(s2, t2, nelem(s2), r2);
	test(s3, t3, nelem(s3), r3);
	test(s4, t4, nelem(s4), r4);
	test(s5, t5, nelem(s5), r5);
	test(s6, t6, nelem(s6), r6);
	test(s7, t7, nelem(s7), r7);
	test(s8, t8, nelem(s8), r8);
	test(s9, t9, nelem(s9), r9);
	test(s10, t10, nelem(s10), r10);
	test(s11, t11, nelem(s11), r11);
	test(s12, t12, nelem(s12), r12);
	test(s13, t13, nelem(s13), r13);
	test(s14, t14, nelem(s14), r14);

	return 0;
}
