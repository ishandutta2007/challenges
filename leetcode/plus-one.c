/*

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
plusone(int *a, size_t n)
{
	size_t i;
	int c;

	if (n == 0)
		return;

	c = 1;
	for (i = n - 1;; i--) {
		a[i] += c;
		if (a[i] >= 10)
			a[i] %= 10;
		else
			break;

		if (i == 0)
			break;
	}
}

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int
main(void)
{
	int a[] = {1, 2, 3};
	plusone(a, nelem(a));
	print(a, nelem(a));

	int b[] = {4, 3, 2, 1};
	plusone(b, nelem(b));
	print(b, nelem(b));

	int c[] = {0, 9, 9, 9};
	plusone(c, nelem(c));
	print(c, nelem(c));

	int d[] = {1, 0, 9, 9};
	plusone(d, nelem(d));
	print(d, nelem(d));

	int e[] = {0};
	plusone(e, nelem(e));
	print(e, nelem(e));

	return 0;
}
