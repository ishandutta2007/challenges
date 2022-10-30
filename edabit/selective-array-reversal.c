/*

Create a function that takes an array and a number and selectively reverse the order of the array based on the number you're given (second argument). If you're given the arguments [1,2,3,4,5,6] and 2, you would return the array [2,1, 4,3, 6,5].
Examples

selReverse([1,2,3,4,5,6], 2) ➞ [2,1, 4,3, 6,5]

selReverse([2,4,6,8,10,12,14,16], 3) ➞ [6,4,2, 12,10,8, 16,14]

selReverse([5,7,2,6,0,4,6], 100) ➞ [6,4,0,6,2,7,5]

Notes

    If the array you're given can't be broken up into equal parts, just reverse the remaining numbers (see 2nd expample).
    If len exceeds the array length, reverse everything.
    If len is zero, return the original array.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

void
rev(int *a, size_t n)
{
	size_t i;
	int t;

	for (i = 0; i < n / 2; i++) {
		t = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = t;
	}
}

int *
selrev(int *a, size_t n, size_t l)
{
	size_t i;

	if (l == 0)
		return a;

	for (i = 0; i < n; i += l)
		rev(&a[i], min(n - i, l));

	return a;
}

void
test(int *a, size_t n, size_t l, int *b)
{
	selrev(a, n, l);
	assert(memcmp(a, b, sizeof(*b) * n) == 0);
}

int
main(void)
{
	int a1[] = { 1, 2, 3, 4, 5, 6 };
	int b1[] = { 2, 1, 4, 3, 6, 5 };

	int a2[] = { 2, 4, 6, 8, 10, 12, 14, 16 };
	int b2[] = { 6, 4, 2, 12, 10, 8, 16, 14 };

	int a3[] = { 5, 7, 2, 6, 0, 4, 6 };
	int b3[] = { 6, 4, 0, 6, 2, 7, 5 };

	int a4[] = { 6, 0, 0, 0, 3, 8, 9, 7, 1 };
	int b4[] = { 1, 7, 9, 8, 3, 0, 0, 0, 6 };

	int a5[] = { 12, 54, 67, 34, 65, 34, 33 };
	int b5[] = { 12, 54, 67, 34, 65, 34, 33 };

	int a6[] = { 12, 54, 67, 34, 65, 34, 33 };
	int b6[] = { 12, 54, 67, 34, 65, 34, 33 };

	int a7[] = { 22, 13, 22, 13, 13, 22, 22, 13 };
	int b7[] = { 13, 13, 22, 13, 22, 13, 22, 22 };

	int a8[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int b8[] = { 2, 1, 4, 3, 6, 5, 8, 7, 10, 9 };

	int a9[] = { 1 };
	int b9[] = { 1 };

	int a10[] = { 1, 2 };
	int b10[] = { 2, 1 };

	test(a1, nelem(a1), 2, b1);
	test(a2, nelem(a2), 3, b2);
	test(a3, nelem(a3), 100, b3);
	test(a4, nelem(a4), 9, b4);
	test(a5, nelem(a5), 0, b5);
	test(a6, nelem(a6), 1, b6);
	test(a7, nelem(a7), 5, b7);
	test(a8, nelem(a8), 2, b8);
	test(a9, nelem(a9), 1, b9);
	test(a10, nelem(a10), 2, b10);

	return 0;
}
