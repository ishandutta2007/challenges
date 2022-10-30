/*

There are N students in a class, where the i-th student has a score of Ai.

The i-th student will boast if and only if the number of students scoring less than or equal Ai is greater than the number of students scoring greater than Ai.

Find the number of students who will boast.

Input Format

The first line contains T - the number of test cases. Then the test cases follow.
The first line of each test case contains a single integer N - the number of students.
The second line of each test case contains N integers A1,A2,…,AN - the scores of the students.

Output Format

For each test case, output in a single line the number of students who will boast.

Constraints
1≤T≤1000
1≤N≤100
0≤Ai≤100

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
boasts(unsigned *a, size_t n)
{
	size_t h[101];
	size_t i;
	unsigned c, r;

	memset(h, 0, sizeof(h));
	for (i = 0; i < n; i++) {
		if (a[i] < nelem(h))
			h[a[i]]++;
	}

	c = r = 0;
	for (i = 0; i < nelem(h); i++) {
		if (h[i]) {
			c += h[i];
			if (c > n - c)
				r += h[i];
		}
	}
	return r;
}

int
main(void)
{
	unsigned a1[] = {100, 100, 100};
	unsigned a2[] = {2, 1, 3};
	unsigned a3[] = {30, 1, 30, 30};

	assert(boasts(a1, nelem(a1)) == 3);
	assert(boasts(a2, nelem(a2)) == 2);
	assert(boasts(a3, nelem(a3)) == 3);

	return 0;
}
