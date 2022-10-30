/*

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swap(unsigned *a, unsigned *b)
{
	unsigned t;

	t = *a;
	*a = *b;
	*b = t;
}

// https://en.wikipedia.org/wiki/Dutch_national_flag_problem
void
dnf(unsigned *a, size_t n)
{
	size_t i, j;
	unsigned m;

	m = 1;
	i = j = 0;
	while (j < n) {
		if (a[j] < m) {
			swap(&a[i], &a[j]);
			i++;
			j++;
		} else if (a[j] > m) {
			swap(&a[j], &a[n - 1]);
			n--;
		} else
			j++;
	}
}

void
print(unsigned *a, size_t n)
{
	size_t i;

	printf("[");
	for (i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i + 1 < n)
			printf(",");
	}
	printf("]\n");
}

void
test(unsigned *a, size_t n)
{
	print(a, n);
	dnf(a, n);
	print(a, n);
	printf("\n");
}

int
main(void)
{
	unsigned a1[] = {2, 0, 2, 1, 1, 0};
	unsigned a2[] = {1, 2, 0, 1, 0, 2, 0, 0, 1, 0, 2, 1};
	unsigned a3[] = {0};
	unsigned a4[] = {1, 2, 0};
	test(a1, nelem(a1));
	test(a2, nelem(a2));
	test(a3, nelem(a3));
	test(a4, nelem(a4));
	test(a4, 0);
	return 0;
}
