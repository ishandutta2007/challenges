/*

Ken is a fencer with a big problem: he swings too hard!

Whenever Ken gets a new sword, he’s sure to break it sooner rather than later. It’s occurred to him that this habit is costing him quite a bit of money, since he normally buys a new sword whenever his current sword breaks.
However, he’s heard from a fellow club member that he could instead make new swords out of his old swords!

Each bamboo sword Ken uses has four bamboo ’slats’ which help to cushion each blow for the receiving partner. Whenever Ken breaks his sword, he breaks either one, two, three, or all four slats.

When Ken first tried to put a sword together with the remains of two broken swords, he realized that not all slats are equivalent. When the slats are bundled together, they conform to the shape of the slat which sits opposite!

Ken doesn’t want an uncomfortable grip, so he will put only an old slat in a new position if it is of the same or opposite type. There are four possible slats “top” (T), “bottom” (B), “left” (L), and “right” (R).
When looking at a sword head on, these slats form the following configuration:

 T
L R
 B

Input

The input consists of a single test case. On the first line, you are given N, the number of swords Ken has broken. On each of the next N

lines, you are given four characters. The characters correspond to the following slat ordering: TBLR. If the character in a position is 0, then the slat is not broken, and if it is a 1, Ken is out of luck!

Output

Output three numbers: the total number of swords Ken can make, the sum of the numbers of the remaining T and B slats, and the sum of the numbers of the remaining L and R slats, respectively.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

void
swords(const char **s, size_t n, unsigned r[3])
{
	unsigned p[4], tb, lr;
	size_t i, j;

	memset(p, 0, sizeof(p));
	for (i = 0; i < n; i++) {
		for (j = 0; s[i][j] && j < 4; j++)
			p[j] += (s[i][j] == '0');
	}

	tb = p[0] + p[1];
	lr = p[2] + p[3];

	r[0] = min(tb, lr) / 2;
	r[1] = tb - (r[0] * 2);
	r[2] = lr - (r[0] * 2);
}

void
test(const char **s, size_t n, unsigned r[3])
{
	unsigned p[3];

	swords(s, n, p);
	printf("%u %u %u\n", p[0], p[1], p[2]);
	assert(!memcmp(r, p, sizeof(p)));
}

int
main(void)
{
	const char *s1[] = {
	    "0100",
	    "0010",
	    "0110",
	    "1010",
	};

	test(s1, nelem(s1), (unsigned[]){2, 1, 1});

	return 0;
}
