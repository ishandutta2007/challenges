/*

The task is taken from an MIT lecture by Prof. Devadas called You can read minds. A detailed explanation of the trick can be found in the linked video, or in this document. I'll try to explain it in simpler terms.

It turns out this was invented in the 1930's, and is known as the "Five-Card Trick of Fitch Cheney".

The trick goes like this:

Five random cards are chosen from a deck of cards. The audience and your assistant get to see them, but you don't.
Your assistant (with whom you have practiced) will select four of those cards and show them to you in a specific order.
Note that the hidden card is not randomly picked from the 5 cards. The assistant picks a/the card that will make the trick work.
You will deduce, based on the information you can gather from the four cards what the fifth card is.

How?

Keep the following two points in mind:

When choosing 5 random cards, you are guaranteed that at least two cards have the same suit1.

The image below shows a circle with all the ranks2. Since it's a circle, it's possible to count: J, Q, K, A, 2, 3 (i.e. modular counting).
You are guaranteed that the hidden card does not have the same rank as the first, since they will be of the same suit (explained below).
It's always possible to choose the first card and the hidden cards such that the hidden card is between 1 and 6 ranks higher than the first (when counting in circles).
If the first card is 1, then the hidden card will be 2,3,4,5,6 or 7. If the first card is J, then the hidden card will be Q,K,A,2,3 or 4 and so on.

Card ranks from A up to K arranged in a circle

The algorithm:
The first card: This card will have the same suit as the hidden card. The card will also be the reference point you'll use when figuring out the rank of the hidden card.

The 2nd, 3rd and 4th cards decodes a value in the inclusive range 1 ... 6. We'll call the three cards S, M, L (smallest card, middle card, largest card). The values will be encoded like this (lexicographic order):

S M L   -> 1
S L M   -> 2
M S L   -> 3
M L S   -> 4
L S M   -> 5
L M S   -> 6
So, if the rank of the first card is 5, and the remaining three cards have ranks 4 Q 7 (they are ordered S L M), then the last card has rank 5+2=7. You may choose if the ace should be the highest or lowest card, as long as it's consistent.

If several cards share rank, then the suit will determine the order, where C < D < H < S.

Input format:

The four cards will be given as H3 (three of hearts), DK (King of diamonds) and so on. You may choose to take the input the other way around as 3H and KD instead.

The input can be on any convenient format, but you can't combine the list of suits in one variable and the list of ranks in another. 'D5', 'H3' .. and [['D',5],['H',3] ... are both OK, but 'DHCH',[5,3,1,5] is not.
You can't use numbers instead of letters, except for T.

Output
The hidden card, in the same format as the input.

Example

Let's do a walkthrough:

Input:

D3 S6 H3 H9
We know the hidden card is a diamond, since the first card is a diamond. We also know that the rank is 4,5,6,7,8 or 9 since the rank of the first card is 3.

The remaining cards are ordered 6,3,9 ==> M,S,L, which encodes the value 3. The hidden card is therefore 3+3=6 of diamonds, thus the output should be D6.

Test cases:

C3 H6 C6 S2
C9            # The order is LMS (H6 > C6, and 2 < 6). 3+6=9

SQ S4 S3 ST   # (ST = S10. Format is optional)
S2            # The order is MSL. 12+3=2

HA CA DA SA
H2            # The order is SML. 14+1=2

This is code-golf, so the shortest solution in each language wins. Explanations are encouraged!

1 There are four suits (Clubs, Diamonds, Hearts and Spades).

2 There are 13 ranks, 2,3,4,5,6,7,8,9,10,J,Q,K,A. You may choose to use T instead of 10.

*/

#define _XOPEN_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	unsigned suit;
	unsigned rank;
} Card;

static const char suitstr[] = "CDHS";
static const char rankstr[] = "23456789TJQKA";

char *
card2str(Card *c, char *b)
{
	unsigned s, r;

	s = c->suit;
	r = c->rank;
	if (s < nelem(suitstr) - 1 && r < nelem(rankstr) - 1)
		sprintf(b, "%c%c", suitstr[s], rankstr[r]);
	else
		sprintf(b, "??");
	return b;
}

int
str2card(Card *c, const char *s)
{
	char *p, *q;

	memset(c, 0, sizeof(*c));
	p = strchr(suitstr, s[0]);
	if (!p)
		return -1;

	q = strchr(rankstr, s[1]);
	if (!q)
		return -1;

	c->suit = p - suitstr;
	c->rank = q - rankstr;

	return 0;
}

int
readcards(const char *s, Card *c, size_t n)
{
	char b[128];
	char *p, *t, *sp;
	size_t i;

	memset(c, 0, sizeof(*c) * n);

	snprintf(b, sizeof(b), "%s", s);
	p = b;
	for (i = 0; i < n; i++) {
		t = strtok_r(p, " ", &sp);
		if (!t || str2card(c + i, t) < 0)
			return -1;

		p = NULL;
	}
	return 0;
}

int
cmp(const void *a, const void *b)
{
	const int *x, *y;
	int i;

	x = a;
	y = b;
	for (i = 2; i >= 0; i--) {
		if (x[i] < y[i])
			return -1;
		if (x[i] > y[i])
			return 1;
	}
	return 0;
}

int
lexicographic(Card c[3])
{
	static const int ltab[][3] = {
	    {0, 1, 2},
	    {0, 2, 1},
	    {1, 0, 2},
	    {1, 2, 0},
	    {2, 0, 1},
	    {2, 1, 0},
	};

	int p[3][3];
	size_t i, j;

	for (i = 0; i < nelem(p); i++) {
		p[i][0] = i;
		p[i][1] = c[i].suit;
		p[i][2] = c[i].rank;
	}

	qsort(p, nelem(p), sizeof(*p), cmp);

	for (i = 0; i < nelem(ltab); i++) {
		for (j = 0; j < 3; j++) {
			if (ltab[i][j] != p[j][0])
				break;
		}
		if (j == 3)
			return i + 1;
	}
	return -1;
}

char *
readmind(const char *s, char *b)
{
	Card c[4], h;
	int o;

	sprintf(b, "??");
	if (readcards(s, c, nelem(c)) < 0)
		return b;

	h = c[0];
	o = lexicographic(c + 1);
	if (o < 0)
		return b;

	h.rank = (h.rank + o) % 13;
	return card2str(&h, b);
}

void
test(const char *s, const char *r)
{
	char b[128];

	readmind(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("D3 S6 H3 H9", "D6");
	test("C3 H6 C6 S2", "C9");
	test("SQ S4 S3 ST", "S2");
	test("HA CA DA SA", "H2");

	return 0;
}
