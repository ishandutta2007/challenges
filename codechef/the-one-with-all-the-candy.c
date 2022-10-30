/*

Monica decides that she would like to get to know the neighbours in the apartment better.
She makes a batch of wonderful chocolates and hangs them on the door in a basket hoping that her neighbors will take some and they can meet.
The neighbours (including Joey) eventually go crazy over the candy and demand more.
Eventually, she keeps a bowl full of chocolates at the door for the last time.

There are N neighbours. The ith neigbhour has initial energy equal to Ai.
There is one bowl filled with chocolates. The neighbours are made to stand in a row and the bowl is passed around by obeying the following rules:

Any person can hold the bowl initially.
If the person holding the bowl has positive energy, he/she passes the bowl to the person on the immediate right of him/her.
The rightmost person in the row passes the bowl to the leftmost person in the row.
The act of passing the bowl takes 1 second.
If the person holding the bowl has non-positive energy, he/she drops the bowl.
After each pass, the energy of the person reduces by 1.
Among all possible ways in which the N neighbours start the game, find the maximum time until the bowl is dropped.

Input Format

First line will contain T, number of testcases. Then the testcases follow.
First line of each testcase contains one integer N.
Second line of each testcase contains of N integers, denoting the elements of array A.

Output Format

For each testcase, output in a single line the maximum time until the bowl is dropped.

Constraints
1≤T≤100
1≤N≤10^5
0≤A[i]≤10^6
Sum of N over all test cases does not exceed 2⋅10^5

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int
droptime(int *a, size_t n)
{
	size_t i;

	qsort(a, n, sizeof(*a), cmp);
	for (i = 0; i < n; i++) {
		if (a[i] > a[0])
			return a[0] * n + n - i;
	}
	return 0;
}

int
main(void)
{
	int a1[] = {2, 1, 1};
	int a2[] = {0, 5, 0};
	int a3[] = {3, 0, 2, 1};

	assert(droptime(a1, nelem(a1)) == 4);
	assert(droptime(a2, nelem(a2)) == 1);
	assert(droptime(a3, nelem(a3)) == 3);

	return 0;
}
