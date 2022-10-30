/*

Check out the resources on the page's right side to learn more about merge sort. The video tutorial is by Gayle Laakmann McDowell,
author of the best-selling interview book Cracking the Coding Interview.

In an array, arr, the elements at indices i and j (where i<j) form an inversion if arr[i]>arr[j].
In other words, inverted elements arr[i] and arr[j] are considered to be "out of order". To correct an inversion, we can swap adjacent elements.

For example, consider the dataset arr=[2, 4, 1]. It has two inversions: (4,1) and (2,1).
To sort the array, we must perform the following two swaps to correct the inversions: 

Given d datasets, print the number of inversions that must be swapped to sort each dataset on a new line.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

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
merge(int *a, int *b, size_t s, size_t m, size_t e, size_t *iv)
{
	size_t i, c, l, r;

	for (i = s; i <= e; i++)
		b[i] = a[i];

	c = s;
	l = s;
	r = m + 1;
	while (l <= m && r <= e) {
		if (b[l] <= b[r])
			a[c++] = b[l++];
		else {
			a[c++] = b[r++];
			*iv += m + 1 - l;
		}
	}

	while (l <= m)
		a[c++] = b[l++];
}

void
split(int *a, int *b, size_t s, size_t e, size_t *iv)
{
	size_t m;

	if (s < e) {
		m = (s + e) / 2;
		split(a, b, s, m, iv);
		split(a, b, m + 1, e, iv);
		merge(a, b, s, m, e, iv);
	}
}

size_t
mergesort(int *a, size_t n)
{
	int *b;
	size_t iv;

	iv = 0;
	b = calloc(n, sizeof(*b));
	if (b == NULL)
		return SIZE_MAX;
	split(a, b, 0, n - 1, &iv);
	free(b);
	return iv;
}

int
main(void)
{
	int a[] = {2, 4, 1};
	printf("%zu\n", mergesort(a, nelem(a)));

	int b[] = {1, 1, 1, 2, 2};
	printf("%zu\n", mergesort(b, nelem(b)));

	int c[] = {2, 1, 3, 1, 2};
	printf("%zu\n", mergesort(c, nelem(c)));

	return 0;
}
