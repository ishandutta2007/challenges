/*

Definition1

    A Kolakoski sequence is a self-describing infinite sequence {kn} of alternating blocks of 1's and 2's, given by the following rules:

        k0 = 1
        kn = the length of the (n+1)'th block

The Task

Given a positive integer n, generate the first n elements of the Kolakoski sequence.
Details

Input will be provided as a single command line argument n. Please write a full program that will print the first n elements of the Kolakoski sequence (in order) to STDOUT, with each element separated by your favorite whitespace.
Scoring

Lets count source code bytes this time with all whitespace included. Fewest number of bytes wins. In the event of a tie, the solution with the earliest submission time wins.

The Sequence

1, 2, 2, 1, 1, 2, 1, 2, 2, 1, 2, 2, 1, 1, 2, 1, 1, 2, 2, 1, 2, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 1, 2, 1, 2, 2, 1, 2, 2, 1, 1, 2, 1, 2, 2, 1, 2, 1, 1, 2, 1, 1, 2, 2, 1, 2, 2, 1, 1, 2, 1, 2, 2, 1, 2, 2, 1, 1, 2, 1, 1, 2, 1, 2, 2, 1, 2, 1, 1, 2, 2, 1, 2, 2, 1, 1, 2, 1, 2, 2, 1, 2, 2, 1, 1, 2, 1, 1, 2, 2, 1, 2, 1, 1, 2, 1, 2, 2, ...

References

    John Smith, Ariel Scolnicov, yark. "Kolakoski sequence" (version 3). PlanetMath.org. Freely available at http://planetmath.org/KolakoskiSequence.html.
    The Online Encyclopedia of Integer Sequences http://oeis.org/A000002

Other resources

    Kolakoski Sequence at Wikipedia http://en.wikipedia.org/wiki/Kolakoski_sequence
    Kolakoski Sequence at Wolfram MathWorld http://mathworld.wolfram.com/KolakoskiSequence.html

*/

#include <stdio.h>

typedef long long vlong;

typedef struct {
	vlong x, y;
} kolakoski_t;

void
initkolakoski(kolakoski_t *kl)
{
	kl->x = kl->y = -1;
}

vlong
nextkolakoski(kolakoski_t *kl)
{
	vlong f, r;

	r = 2 - (kl->x & 1);
	f = kl->y & ~(kl->y + 1);
	kl->x ^= f;
	kl->y = (kl->y + 1) | (f & (kl->x >> 1));
	return r;
}

int
main(void)
{
	kolakoski_t kl[1];
	vlong i;

	initkolakoski(kl);
	for (i = 0; i < 50; i++)
		printf("%lld %lld\n", i, nextkolakoski(kl));
	printf("\n");

	return 0;
}
