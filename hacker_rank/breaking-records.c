/*
Maria plays college basketball and wants to go pro. Each season she maintains a record of her play. She tabulates the number of times she breaks her season record for most points and least points in a game. Points scored in the first game establish her record for the season, and she begins counting from there.

For example, assume her scores for the season are represented in the array scores=[12 24 10 24].
Scores are in the same order as the games played. She would tabulate her results as follows:

                                 Count
Game  Score  Minimum  Maximum   Min Max
 0      12     12       12       0   0
 1      24     12       24       0   1
 2      10     10       24       1   1
 3      24     10       24       1   1

Given Maria's scores for a season, find and print the number of times she breaks her records for most and least points scored during the season.
*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
breakrecords(int *a, size_t n)
{
	size_t i, mi, ma;
	int r[2] = {0};

	if (n < 2)
		goto out;

	mi = ma = a[0];
	for (i = 1; i < n; i++) {
		if (a[i] < mi) {
			r[0]++;
			mi = a[i];
		}
		if (a[i] > ma) {
			r[1]++;
			ma = a[i];
		}
	}
out:
	printf("%d %d\n", r[1], r[0]);
}

int
main(void)
{
	int a[] = {12, 24, 10, 24};
	breakrecords(a, nelem(a));

	int b[] = {10, 5, 20, 20, 4, 5, 2, 25, 1};
	breakrecords(b, nelem(b));

	int c[] = {3, 4, 21, 36, 10, 28, 35, 5, 24, 42};
	breakrecords(c, nelem(c));

	return 0;
}
