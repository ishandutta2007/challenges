/*

Calvin is driving his favorite vehicle on the 101 freeway.
He notices that the check engine light of his vehicle is on, and he wants to service
it immediately to avoid any risks.
Luckily, a service lane runs parallel to the highway.
The service lane varies in width along its length.


You will be given an array of widths at points along the road (indices),
then a list of the indices of entry and exit points.
Considering each entry and exit point pair,
calculate the maximum size vehicle that can travel that segment of the service lane safely.

For example, there are n=4 measurements yielding width=[2 3 2 1].
If our entry index, i=1 and our exit, j=2,
there are two segment widths of 2 and 3 respectively.
The widest vehicle that can fit through both is 2.
If i=2 and j=4 our widths are [3 2 1] which limits vehicle width to 1.

*/
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
lane(int *a, size_t n, size_t i, size_t j)
{
	int v;

	if (n == 0)
		return 0;

	v = -1;
	for (; i <= j && i < n; i++) {
		if (v < 0 || a[i] < v)
			v = a[i];
	}
	return v;
}

int
main(void)
{
	int a[] = {2, 3, 1, 2, 3, 2, 3, 3};
	printf("%d\n", lane(a, nelem(a), 0, 3));
	printf("%d\n", lane(a, nelem(a), 4, 6));
	printf("%d\n", lane(a, nelem(a), 6, 7));
	printf("%d\n", lane(a, nelem(a), 3, 5));
	printf("%d\n", lane(a, nelem(a), 0, 7));
	printf("\n");

	int b[] = {1, 2, 2, 2, 1};
	printf("%d\n", lane(b, nelem(b), 2, 3));
	printf("%d\n", lane(b, nelem(b), 1, 4));
	printf("%d\n", lane(b, nelem(b), 2, 4));
	printf("%d\n", lane(b, nelem(b), 2, 4));
	printf("%d\n", lane(b, nelem(b), 2, 3));

	return 0;
}
