/*

Marc loves cupcakes, but he also likes to stay fit.
Each cupcake has a calorie count, and Marc can walk a distance to expend those calories.
If Marc has eaten j cupcakes so far, after eating a cupcake with c calories
he must walk at least 2^j*c miles to maintain his weight.


For example, if he eats 3 cupcakes with calorie counts in the following order: [5, 10, 7],
the miles he will need to walk are 2^0*5 + 2^1*10 + 2^2*7.
This is not the minimum, though, so we need to test other orders of consumption.
In this case, our minimum miles is calculated as 2^0*10 + 2^1*7 + 2^2*5.

Given the individual calorie counts for each of the cupcakes,
determine the minimum number of miles Marc must walk to maintain his weight.
Note that he can eat the cupcakes in any order.

*/
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x > y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int
cakewalk(int *a, size_t n)
{
	size_t i;
	int w;

	qsort(a, n, sizeof(*a), cmp);

	w = 0;
	for (i = 0; i < n; i++)
		w += a[i] * (1UL << i);
	return w;
}

int
main(void)
{
	int a[] = {5, 10, 7};
	printf("%d\n", cakewalk(a, nelem(a)));

	int b[] = {1, 3, 2};
	printf("%d\n", cakewalk(b, nelem(b)));

	int c[] = {7, 4, 9, 6};
	printf("%d\n", cakewalk(c, nelem(c)));

	return 0;
}
