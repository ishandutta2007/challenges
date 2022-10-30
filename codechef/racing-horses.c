/*

Chef is very fond of horses. He enjoys watching them race. As expected, he has a stable full of horses.
He, along with his friends, goes to his stable during the weekends to watch a few of these horses race.
Chef wants his friends to enjoy the race and so he wants the race to be close.
This can happen only if the horses are comparable on their skill i.e. the difference in their skills is less.

There are N horses in the stable. The skill of the horse i is represented by an integer S[i].
The Chef needs to pick 2 horses for the race such that the difference in their skills is minimum.
This way, he would be able to host a very interesting race.
Your task is to help him do this and report the minimum difference that is possible between 2 horses in the race.

Input:

First line of the input file contains a single integer T, the number of test cases.
Every test case starts with a line containing the integer N.
The next line contains N space separated integers where the i-th integer is S[i].

Output:

For each test case, output a single line containing the minimum difference that is possible.

Constraints:
1 ≤ T ≤ 10
2 ≤ N ≤ 5000
1 ≤ S[i] ≤ 1000000000

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

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
mindiff(int *a, size_t n)
{
	size_t i;
	int m;

	qsort(a, n, sizeof(*a), cmp);

	m = INT_MAX;
	for (i = 1; i < n; i++)
		m = min(m, a[i] - a[i - 1]);
	return m;
}

int
main(void)
{
	int a1[] = {4, 9, 1, 32, 13};

	assert(mindiff(a1, nelem(a1)) == 3);

	return 0;
}
