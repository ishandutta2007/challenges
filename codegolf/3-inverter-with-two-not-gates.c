/*

Introduction
I recently came across an oral exam where the candidates were asked to find a logical circuit than can negate 3 inputs A,B,C using only two NOT gates.

The question also specified that such a circuit is unique up to removal of useless gates and reordering inputs/outputs. The candidates were asked to prove this assertion by writing a piece of code that generates all such circuits.

Challenge
No inputs whatsoever are given.

The program must output all logical circuits using unlimited AND and OR gates but only two NOT gates which take in three inputs which map to three outputs. The outputs should be the negation of each input.

The outputted circuits should not have any redundant/trivial gates (gates that always output the same thing) or unused gates (whose output doesn't influence the outcome).

The program should use no precalculated or cached data.

Output format is left up to the coders.

The winner will be determined by the fastest algorithm. Since input doesn't scale, whoever has the least loops and calculations wins. Please remember your code must not cache or use any precalculated data.

Example Input and Output
Input:

N/A

Output:

R    = (A & B) | (A & C) | (B & C)
notR = !R
S    = (notR & (A | B | C)) | (A & B & C)
notS = !S

notA = (notR & notS) | (notR & S & (B | C)) | (R & notS & (B & C))
notB = (notR & notS) | (notR & S & (A | C)) | (R & notS & (A & C))
notC = (notR & notS) | (notR & S & (A | B)) | (R & notS & (A & B))

*/

#include <assert.h>
#include <stdio.h>

void
not3(int a, int b, int c, int *na, int *nb, int *nc)
{
	int r, s, nr, ns;

	r = (a & b) | (a & c) | (b & c);
	nr = !r;
	s = (nr & (a | b | c)) | (a & b & c);
	ns = !s;

	*na = (nr & ns) | (nr & s & (b | c)) | (r & ns & (b & c));
	*nb = (nr & ns) | (nr & s & (a | c)) | (r & ns & (a & c));
	*nc = (nr & ns) | (nr & s & (a | b)) | (r & ns & (a & b));
}

int
main(void)
{
	int a, b, c;
	int na, nb, nc;
	int i;

	for (i = 0; i < 8; i++) {
		a = i & 1;
		b = (i >> 1) & 1;
		c = (i >> 2) & 1;

		not3(a, b, c, &na, &nb, &nc);
		assert(a == !na);
		assert(b == !nb);
		assert(c == !nc);
	}

	return 0;
}
