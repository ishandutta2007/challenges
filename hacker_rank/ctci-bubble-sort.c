/*

Consider the following version of Bubble Sort:

for (int i = 0; i < n; i++) {
	for (int j = 0; j < n - 1; j++) {
		// Swap adjacent elements if they are in decreasing order
		if (a[j] > a[j + 1]) {
			swap(a[j], a[j + 1]);
		}
	}
}

Given an array of integers, sort the array in ascending order using the Bubble Sort algorithm above. Once sorted, print the following three lines:

Array is sorted in numSwaps swaps, where numSwaps is the number of swaps that took place.
First Element: firstElement, where firstElement is the first element in the sorted array.
Last Element: lastElement, where lastElement is the last element in the sorted array.

Hint: To complete this challenge, you must add a variable that keeps a running tally of all swaps that occur during execution. 

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

void
countswap(int *a, size_t n)
{
	size_t i, j, w;

	if (n == 0)
		return;

	w = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
				w++;
			}
		}
	}

	printf("Array is sorted in %zu swaps.\n", w);
	printf("First Element: %d\n", a[0]);
	printf("Last Element: %d\n", a[n - 1]);
	printf("\n");
}

int
main(void)
{
	int a1[] = {6, 4, 1};
	int a2[] = {1, 2, 3};
	int a3[] = {3, 2, 1};
	int a4[] = {4, 2, 3, 1};
	countswap(a1, nelem(a1));
	countswap(a2, nelem(a2));
	countswap(a3, nelem(a3));
	countswap(a4, nelem(a4));
	return 0;
}
