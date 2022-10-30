/*

Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

Note:

    A.length == 4
    0 <= A[i] <= 9



*/
#include <stdio.h>
#include <string.h>

char *
largesttime(int a[4], char *b, size_t n)
{
	static const int l[4] = {2, 3, 5, 9};
	int i, j, k, m, v, t[4], r[4];

	if (n == 0)
		return b;
	b[0] = '\0';

	memmove(t, a, sizeof(t));
	for (i = 0, k = 4; i < 4; i++) {
		v = -1;
		for (j = 0; j < k; j++) {
			if (t[j] >= v && t[j] <= l[i]) {
				v = t[j];
				m = j;
			}
		}
		if (v < 0)
			break;
		r[i] = v;
		t[m] = t[--k];
	}
	if (i == 4)
		snprintf(b, n, "%d%d:%d%d", r[0], r[1], r[2], r[3]);
	return b;
}

int
main(void)
{
	char b[8];
	
	int t1[4] = {1, 2, 3, 4};
	printf("%s\n", largesttime(t1, b, sizeof(b)));

	int t2[4] = {5, 5, 5, 5};
	printf("%s\n", largesttime(t2, b, sizeof(b)));

	int t3[4] = {1, 2, 5, 9};
	printf("%s\n", largesttime(t3, b, sizeof(b)));

	return 0;
}
