/*

In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to closest person.

Note:

1 <= seats.length <= 20000
seats contains only 0s or 1s, at least one 0, and at least one 1.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <inttypes.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

ssize_t
maxdist(int *s, size_t n)
{
	ssize_t a, b, d, l, r, i, m;

	l = -1;
	r = 0;
	d = 0;
	m = n;
	for (i = 0; i < m; i++) {
		if (s[i] == 1)
			l = i;
		else {
			while ((r < m && s[r] == 0) || r < i)
				r++;

			a = (l == -1) ? m : i - l;
			b = (r == m) ? m : r - i;
			d = max(d, min(a, b));
		}
	}

	return d;
}

int
main(void)
{
	int s1[] = {1, 0, 0, 0, 1, 0, 1};
	int s2[] = {1, 0, 0, 0};
	int s3[] = {1, 1, 0, 0, 0, 0, 0, 1};

	printf("%zd\n", maxdist(s1, nelem(s1)));
	printf("%zd\n", maxdist(s2, nelem(s2)));
	printf("%zd\n", maxdist(s3, nelem(s3)));
	return 0;
}
