/*

Sam's house has an apple tree and an orange tree that yield an abundance of fruit.
In the diagram below, the red region denotes his house, where s is the start point, and t is the endpoint.
The apple tree is to the left of his house, and the orange tree is to its right.
You can assume the trees are located on a single point,
where the apple tree is at point a, and the orange tree is at point b.

When a fruit falls from its tree, it lands d units of distance from its tree of origin along the x-axis.
A negative value of d means the fruit fell d units to the tree's left, and a positive value of d means it falls d units to the tree's right.

Given the value of d for m apples and n oranges,
determine how many apples and oranges will fall on Sam's house (i.e., in the inclusive range )?

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
countfall(int s, int t, int a, int b, int *ap, size_t nap, int * or, size_t nor)
{
	size_t i, ca, co;
	int v;

	ca = 0;
	for (i = 0; i < nap; i++) {
		v = a + ap[i];
		if (s <= v && v <= t)
			ca++;
	}

	co = 0;
	for (i = 0; i < nor; i++) {
		v = b + or [i];
		if (s <= v && v <= t)
			co++;
	}

	printf("%zu\n", ca);
	printf("%zu\n", co);
}

int
main(void)
{
	int a[] = {2, 3, -4};
	int b[] = {3, -2, -4};
	countfall(7, 10, 4, 12, a, nelem(a), b, nelem(b));

	int c[] = {-2, 2, 1};
	int d[] = {5, -6};
	countfall(7, 11, 5, 15, c, nelem(c), d, nelem(d));

	return 0;
}
