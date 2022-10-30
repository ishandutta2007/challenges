/*

Alice and Bob each created one problem for HackerRank.
A reviewer rates the two challenges, awarding points on a scale from 1 to 100 for three categories:
problem clarity, originality, and difficulty.

We define the rating for Alice's challenge to be the triplet (a[0], a[1], a[2]),
and the rating for Bob's challenge to be the triplet (b[0],b[1],b[2]).

Your task is to find their comparison points by comparing a[0] with b[0], a[1] with b[1], and a[2] with b[2].

If a[i] > b[i], then Alice is awarded 1 point.
If a[i] < b[i], then Bob is awarded 1 point.
If a[i] == b[i], then neither person receives a point.
Comparison points is the total points a person earned.

Given a and b, determine their respective comparison points.

*/
#include <stdio.h>

void
cmp(int r[2], int a[3], int b[3])
{
	int i;

	r[0] = r[1] = 0;
	for (i = 0; i < 3; i++) {
		if (a[i] > b[i])
			r[0]++;
		else if (a[i] < b[i])
			r[1]++;
	}
	printf("%d %d\n", r[0], r[1]);
}

int
main(void)
{
	int a[] = {1, 2, 3};
	int b[] = {3, 2, 1};
	int r[2];
	cmp(r, a, b);

	int c[] = {5, 6, 7};
	int d[] = {3, 6, 10};
	cmp(r, c, d);

	int e[] = {17, 28, 30};
	int f[] = {99, 16, 6};
	cmp(r, e, f);

	return 0;
}
