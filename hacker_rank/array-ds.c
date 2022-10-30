/*
An array is a type of data structure that stores elements of the same type in a contiguous block of memory.
In an array A of size N, each memory location has some unique index, i (where 0 <= i <= N), that can be referenced as A[i]
(you may also see it written as Ai).

Given an array A of N integers, print each element in reverse order as a single line of space-separated integers.

Note: If you've already solved our C++ domain's Arrays Introduction challenge, you may want to skip this.
*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
printrev(int *a, size_t n)
{
	size_t i;

	if (n == 0)
		return;

	for (i = n - 1;; i--) {
		printf("%d ", a[i]);
		if (i == 0)
			break;
	}
	printf("\n");
}

int
main(void)
{
	int a[] = {1, 4, 3, 2};
	printrev(a, nelem(a));

	int b[] = {8546, 3, 646, 2, 356, 2, 14, 253, 6, 75};
	printrev(b, nelem(b));
	return 0;
}
