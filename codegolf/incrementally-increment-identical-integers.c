/*

Given an ascending-sorted array of possibly duplicated integers, your goal is to increment each number by a counter, starting at 0, that resets for each group.

Spec:

Any numbers may be negative (but if so, they'll be at the beginning, because the array is sorted),
The array will have at least one element,
There may be any number of integers in one group
The groups of numbers have nothing to do with one another
To demonstrate:

[1, 1, 1, 1, 10, 10, 20, 20, 20, 30, 40, 40, 40, 40]
should become this

[1, 2, 3, 4, 10, 11, 20, 21, 22, 30, 40, 41, 42, 43]
because

  1 1 1 1   10 10   20 20 20   30   40 40 40 40
+ 0 1 2 3    0  1    0  1  2    0    0  1  2  3
  -------   -----   --------   --   -----------
  1 2 3 4   10 11   20 21 22   30   40 41 42 43

Test cases
input -> output
[1, 2, 3] -> [1, 2, 3]
[1, 1, 2, 2, 3, 3] -> [1, 2, 2, 3, 3, 4]
[0, 0, 0, 0, 0] -> [0, 1, 2, 3, 4]
[1, 1, 10, 10, 100, 100, 100, 100] -> [1, 2, 10, 11, 100, 101, 102, 103]
[-5, -5, -5, -5, -4, 4, 4, 4, 4, 9, 9] -> [-5, -4, -3, -2, -4, 4, 5, 6, 7, 9, 10]
[1, 1, 1, 1, 2, 2] -> [1, 2, 3, 4, 2, 3]

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
inc(int *a, size_t n)
{
	size_t i, j;
	int c;

	for (i = 0; i < n;) {
		j = i + 1;
		while (j < n && a[i] == a[j])
			j++;

		for (c = 0; i < j; c++, i++)
			a[i] += c;
	}
}

void
test(int *a, size_t n, int *r)
{
	inc(a, n);
	print(a, n);
	assert(!memcmp(a, r, sizeof(*r) * n));
}

int
main(void)
{
	int a1[] = {1, 1, 1, 1, 10, 10, 20, 20, 20, 30, 40, 40, 40, 40};
	int r1[] = {1, 2, 3, 4, 10, 11, 20, 21, 22, 30, 40, 41, 42, 43};

	int a2[] = {1, 2, 3};
	int r2[] = {1, 2, 3};

	int a3[] = {0, 0, 0, 0, 0};
	int r3[] = {0, 1, 2, 3, 4};

	int a4[] = {1, 1, 10, 10, 100, 100, 100, 100};
	int r4[] = {1, 2, 10, 11, 100, 101, 102, 103};

	int a5[] = {-5, -5, -5, -5, -4, 4, 4, 4, 4, 9, 9};
	int r5[] = {-5, -4, -3, -2, -4, 4, 5, 6, 7, 9, 10};

	int a6[] = {1, 1, 1, 1, 2, 2};
	int r6[] = {1, 2, 3, 4, 2, 3};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(a4, nelem(a4), r4);
	test(a5, nelem(a5), r5);
	test(a6, nelem(a6), r6);

	return 0;
}
