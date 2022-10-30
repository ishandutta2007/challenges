/*

Given the participants' score sheet for your University Sports Day, you are required to find the runner-up score.
You are given n scores. Store them in a list and find the score of the runner-up.

*/
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
runnerup(int *a, size_t n)
{
	size_t i;
	int x, y;

	if (n < 2)
		return 0;

	x = y = a[0];
	for (i = 1; i < n; i++) {
		if (y < a[i])
			y = a[i];
		if (x < y && y > a[i])
			x = a[i];
	}
	return x;
}

int
main(void)
{
	int a[] = {2, 3, 6, 6, 5};
	printf("%d\n", runnerup(a, nelem(a)));

	int b[] = {1, 23425, 434, 535, 21, 4, 560};
	printf("%d\n", runnerup(b, nelem(b)));
	return 0;
}
