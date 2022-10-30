/*

Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Note:
You may assume the greed factor is always positive.
You cannot assign more than one cookie to one child. 

*/
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x = *(int *)a;
	int y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

size_t
assign(int *a, size_t na, int *c, size_t nc)
{
	size_t i, j;

	qsort(a, na, sizeof(*a), cmp);
	qsort(c, nc, sizeof(*c), cmp);

	for (i = j = 0; i < na && j < nc; j++) {
		if (a[i] <= c[j])
			i++;
	}
	return i;
}

int
main(void)
{
	int a1[] = {1, 2, 3};
	int c1[] = {1, 1};
	printf("%zu\n", assign(a1, nelem(a1), c1, nelem(c1)));

	int a2[] = {1, 2};
	int c2[] = {1, 2, 3};
	printf("%zu\n", assign(a2, nelem(a2), c2, nelem(c2)));

	return 0;
}
