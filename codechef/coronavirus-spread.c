/*

There are N people on a street (numbered 1 through N). For simplicity, we'll view them as points on a line. For each valid i, the position of the i-th person is Xi.

It turns out that exactly one of these people is infected with the virus COVID-19, but we do not know which one.
The virus will spread from an infected person to a non-infected person whenever the distance between them is at most 2.
If we wait long enough, a specific set of people (depending on the person that was infected initially) will become infected; let's call the size of this set the final number of infected people.

Your task is to find the smallest and largest value of the final number of infected people, i.e. this number in the best and in the worst possible scenario.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-seperated integers X1,X2,…,XN.

Output

For each test case, print a single line containing two space-separated integers ― the minimum and maximum possible final number of infected people.

Constraints
1≤T≤2,000
2≤N≤8
0≤Xi≤10 for each valid i
X1<X2<…<XN

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

void
cases(int *a, size_t n, size_t p[2])
{
	size_t c, i, l, r;

	p[0] = SIZE_MAX;
	p[1] = 0;
	for (i = 0; i < n; i++) {
		l = i;
		while (l > 0 && abs(a[l] - a[l - 1]) <= 2)
			l--;

		r = i;
		while (r < n - 1 && abs(a[r] - a[r + 1]) <= 2)
			r++;

		c = (r - l + 1);

		p[0] = min(p[0], c);
		p[1] = max(p[1], c);
	}
}

void
test(int *a, size_t n, size_t r[2])
{
	size_t p[2];

	cases(a, n, p);
	printf("%zu %zu\n", p[0], p[1]);
	assert(!memcmp(r, p, sizeof(p)));
}

int
main(void)
{
	int a1[] = {3, 6};
	size_t r1[] = {1, 1};

	int a2[] = {1, 3, 5};
	size_t r2[] = {3, 3};

	int a3[] = {1, 2, 5, 6, 7};
	size_t r3[] = {2, 3};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);

	return 0;
}
