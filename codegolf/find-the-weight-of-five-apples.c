/*

Problem
John bought 5 apples. You are given the weights of every group of four apples, and must then find the weights of the apples themselves.

For example, if all apples without the first one weigh 798 g, without the second - 794 g, without the third - 813 g, without the fourth - 806 g, and without the fifth - 789 g, the weights are 202, 206, 187, 194, and 211.

Rules
You need to specify the weight of each apple in one line separated by a space like 1 2 3 4 5
The solution of the problem by enumeration is allowed
Сonsider the number of points as follows: the number of code bytes. The lower the number of points, the better.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
weight(int a[5], int w[5])
{
	int s;
	int i;

	s = 0;
	for (i = 0; i < 5; i++)
		s += a[i];
	s /= 4;

	for (i = 0; i < 5; i++)
		w[i] = abs(s - a[i]);
}

void
test(int a[5], int r[5])
{
	int w[5];

	weight(a, w);
	print(w, 5);
	assert(!memcmp(r, w, sizeof(w)));
}

int
main(void)
{
	int a1[] = {798, 794, 813, 806, 789};
	int r1[] = {202, 206, 187, 194, 211};

	test(a1, r1);

	return 0;
}
