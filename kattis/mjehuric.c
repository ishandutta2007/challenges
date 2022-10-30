/*

Goran has five wooden pieces arranged in a sequence.
There is a number between 1 and 5 inscribed on every piece, so that every number appears on exactly one of the five pieces.
Goran wants to order the pieces to form the sequence 1,2,3,4,5 and does it like this:

    If the number on the first piece is greater than the number on the second piece, swap them.

    If the number on the second piece is greater than the number on the third piece, swap them.

    If the number on the third piece is greater than the number on the fourth piece, swap them.

    If the number on the fourth piece is greater than the number on the fifth piece, swap them.

    If the pieces don’t form the sequence 1,2,3,4,5, go to step 1.

Write a program that, given the initial ordering of the pieces, outputs the ordering after each swap.

Input

The first line contains five integers separated by single spaces, the ordering of the pieces. The numbers will be between 1
and 5 (inclusive) and there will be no duplicates. The initial ordering will not be 1,2,3,4,5.

Output

After any two pieces are swapped, output the ordering of the pieces, on a single line separated by spaces.

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

int
sorted(int *a, size_t n)
{
	size_t i;

	for (i = 1; i < n; i++) {
		if (a[i] < a[i - 1])
			return 0;
	}
	return 1;
}

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i + 1 < n)
			printf(" ");
	}
	printf("\n");
}

void
sort1(int *a, size_t n)
{
	size_t i;
	int f;

	f = 0;
	for (i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			swap(a + i, a + i - 1);
			print(a, n);
			f = 1;
		}
	}

	if (!f)
		print(a, n);
}

void
sortdance(int *a, size_t n)
{
	do {
		sort1(a, n);
	} while (!sorted(a, n));
	printf("\n");
}

int
main(void)
{
	int a1[] = {2, 1, 5, 3, 4};
	int a2[] = {2, 3, 4, 5, 1};
	int a3[] = {5, 4, 3, 2, 1};
	int a4[] = {1, 2, 3, 4, 5};

	sortdance(a1, nelem(a1));
	sortdance(a2, nelem(a2));
	sortdance(a3, nelem(a3));
	sortdance(a4, nelem(a4));

	return 0;
}
