/*

In the popular show “Dinner for Five”, five contestants compete in preparing culinary delights.
Every evening one of them makes dinner and each of other four then grades it on a scale from 1 to 5.
The number of points a contestant gets is equal to the sum of grades they got.
The winner of the show is of course the contestant that gets the most points.

Write a program that determines the winner and how many points they got.

Input

Five lines, each containing 4 integers, the grades a contestant got. The contestants are numbered 1 to 5 in the order in which their grades were given.

Output

Output on a single line the winner’s number and their points, separated by a space. The input data will guarantee that the solution is unique.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
grade(unsigned a[][4], size_t n, unsigned r[2])
{
	size_t i, j, k;
	unsigned m, v;

	k = 0;
	m = 0;
	for (i = 0; i < n; i++) {
		v = 0;
		for (j = 0; j < 4; j++)
			v += a[i][j];

		if (v > m) {
			k = i;
			m = v;
		}
	}

	r[0] = k + 1;
	r[1] = m;
}

void
test(unsigned a[][4], size_t n, unsigned r[2])
{
	unsigned p[2];

	grade(a, n, p);
	printf("%u %u\n", p[0], p[1]);
	assert(!memcmp(r, p, sizeof(p)));
}

int
main(void)
{
	unsigned a1[][4] = {
	    {5, 4, 4, 5},
	    {5, 4, 4, 4},
	    {5, 5, 4, 4},
	    {5, 5, 5, 4},
	    {4, 4, 4, 5},
	};
	unsigned r1[] = {4, 19};

	unsigned a2[][4] = {
	    {4, 4, 3, 3},
	    {5, 4, 3, 5},
	    {5, 5, 2, 4},
	    {5, 5, 5, 1},
	    {4, 4, 4, 4},
	};
	unsigned r2[] = {2, 17};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);

	return 0;
}
