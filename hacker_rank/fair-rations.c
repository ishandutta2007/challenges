/*

You are the benevolent ruler of Rankhacker Castle, and today you're distributing bread.
Your subjects are in a line, and some of them already have some loaves.
Times are hard and your castle's food stocks are dwindling, so you must distribute as few loaves as possible according to the following rules:

Every time you give a loaf of bread to some person i,
you must also give a loaf of bread to the person immediately in front of
or behind them in the line (i.e., i+1 persons  or i-1).

After all the bread is distributed, each person must have an even number of loaves.
Given the number of loaves already held by each citizen, find and print the minimum number of loaves you must
distribute to satisfy the two rules above. If this is not possible, print NO.

For example, the people in line have loaves B=[4 5 6 7].
We can first give a loaf to i=3 and i=4 so B=[4 5 7 8].
Next we give a loaf to i=2 and i=3 and have B=[4 6 8 8] which satisfies our conditions.
We had to distribute 4 loaves.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
rations(int *a, size_t n)
{
	size_t i;
	int c, s, t;

	if (n == 0) {
		printf("0\n");
		return;
	}

	c = s = t = 0;
	for (i = 0; i < n - 1; i++) {
		if (a[i] == 0)
			s = 2;
		else if (a[i] & 1)
			s = 1;
		else
			s = 0;

		a[i] += s;
		a[i + 1] += s;
		t += a[i];
		c += 2 * s;
	}
	t += a[i];

	if (t & 1)
		printf("NO\n");
	else
		printf("%d\n", c);
}

int
main(void)
{
	int a[] = {4, 5, 6, 7};
	rations(a, nelem(a));

	int b[] = {2, 3, 4, 5, 6};
	rations(b, nelem(b));

	int c[] = {1, 2};
	rations(c, nelem(c));

	int d[] = {0, 0};
	rations(d, nelem(d));

	int e[] = {0, 1, 2};
	rations(e, nelem(e));

	int f[] = {1, 3, 654, 24};
	rations(f, nelem(f));

	return 0;
}
