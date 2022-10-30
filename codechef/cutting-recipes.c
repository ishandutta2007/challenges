/*

The chef has a recipe he wishes to use for his guests, but the recipe will make far more food than he can serve to the guests.
The chef therefore would like to make a reduced version of the recipe which has the same ratios of ingredients, but makes less food.
The chef, however, does not like fractions. The original recipe contains only whole numbers of ingredients, and the chef
wants the reduced recipe to only contain whole numbers of ingredients as well.
Help the chef determine how much of each ingredient to use in order to make as little food as possible.

*/
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
gcd(int a, int b)
{
	int t;
	while (b != 0) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int
cut(int *a, size_t n)
{
	size_t i;
	int x, y, d;

	x = y = INT_MAX;
	for (i = 0; i < n; i++) {
		if (a[i] <= 0)
			return -1;

		if (a[i] < x) {
			y = (x == INT_MAX) ? a[i] : x;
			x = a[i];
		} else if (a[i] < y && a[i] != x)
			y = a[i];
	}

	d = gcd(x, y);
	for (i = 0; i < n; i++) {
		if (a[i] % d != 0) {
			d = 1;
			break;
		}
	}

	for (i = 0; i < n; i++)
		printf("%d ", a[i] / d);
	printf("\n");

	return 0;
}

int
main(void)
{
	int a[] = {4, 4};
	cut(a, nelem(a));

	int b[] = {2, 3, 4};
	cut(b, nelem(b));

	int c[] = {3, 15, 9, 6};
	cut(c, nelem(c));

	int d[] = {66, 2, 2, 3, 4, 1};
	cut(d, nelem(d));

	int e[] = {30, 40, 60, 50, 20};
	cut(e, nelem(e));

	int f[] = {100, 1100, 10000, 1000};
	cut(f, nelem(f));

	int g[] = {3, 1800, 27, 6};
	cut(g, nelem(g));

	int h[] = {13310};
	cut(h, nelem(h));

	return 0;
}
