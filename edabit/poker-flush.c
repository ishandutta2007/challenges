/*

Create a function that takes in two arrays and determines whether there exists a flush.

    The first array represents the 5 cards dealt on the table.
    The second array represents the 2 cards in your hand. 

Notation: card number and suit (abbreviated as S = Spades, H = Hearts, D = Diamonds, C = Clubs) separated by an underscore.

Examples

checkFlush(["A_S", "J_H", "7_D", "8_D", "10_D"], ["J_D", "3_D"]) ➞ true // diamond flush

checkFlush(["10_S", "7_S", "9_H", "4_S", "3_S"], ["K_S", "Q_S"]) ➞ true // spade flush

checkFlush(["3_S", "10_H", "10_D", "10_C", "10_S"], ["3_S", "4_D"]) ➞ false

Notes

Hint: If there aren't at least 3 cards of the same suit on the table, there is zero chance of there being a flush.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int
si(int c)
{
	switch (c) {
	case 'S':
		return 0;
	case 'H':
		return 1;
	case 'D':
		return 2;
	case 'C':
		return 3;
	}
	return -1;
}

int
scan(const char *s, int h[4])
{
	char *p;
	int i;

	p = strchr(s, '_');
	if (!p)
		return 0;

	i = si(p[1]);
	if (i < 0)
		return 0;

	return ++h[i] >= 5;
}

bool
flush(const char *s[5], const char *t[2])
{
	int i, f, h[4];

	memset(h, 0, sizeof(h));
	for (i = 0; i < 5; i++)
		scan(s[i], h);

	for (i = f = 0; i < 2; i++)
		f |= scan(t[i], h);

	return f != 0;
}

int
main(void)
{
	const char *s1[] = {"A_S", "J_H", "7_D", "8_D", "10_D"};
	const char *t1[] = {"J_D", "3_D"};

	const char *s2[] = {"10_S", "7_S", "9_H", "4_S", "3_S"};
	const char *t2[] = {"K_S", "Q_S"};

	const char *s3[] = {"3_S", "10_H", "10_D", "10_C", "10_S"};
	const char *t3[] = {"3_S", "4_D"};

	const char *s4[] = {"8_H", "10_H", "10_D", "J_H", "10_S"};
	const char *t4[] = {"5_D", "Q_H"};

	assert(flush(s1, t1) == true);
	assert(flush(s2, t2) == true);
	assert(flush(s3, t3) == false);
	assert(flush(s4, t4) == false);

	return 0;
}
