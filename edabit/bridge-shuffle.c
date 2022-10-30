/*

Create a function to bridge shuffle two arrays. To bridge shuffle, you interleave the elements from both arrays in an alternating fashion, like so:

Array 1 = ["A", "A", "A"]
Array 2 = ["B", "B", "B"]

Shuffled Array = ["A", "B", "A", "B", "A", "B"]

This can still work with two arrays of uneven length. We simply tack on the extra elements from the longer array, like so:

Array 1 = ["C", "C", "C", "C"]
Array 2 = ["D"]

Shuffled Array = ["C", "D", "C", "C", "C"]

Create a function that takes in two arrays and returns the bridge-shuffled array.
Examples

bridgeShuffle(["A", "A", "A"], ["B", "B", "B"]) ➞ ["A", "B", "A", "B", "A", "B"]

bridgeShuffle(["C", "C", "C", "C"], ["D"]) ➞ ["C", "D", "C", "C", "C"]

bridgeShuffle([1, 3, 5, 7], [2, 4, 6]) ➞ [1, 2, 3, 4, 5, 6, 7]

Notes

    Elements in both arrays can be strings or integers.
    If two arrays are of unequal length, add the additional elements of the longer array to the end of the shuffled array.
    Always start your shuffle with the first element of Array 1.

*/

#include <stdio.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
bridge(int *a, int *b, size_t na, size_t nb, int *p)
{
	size_t i, j, k;

	for (i = j = k = 0; i < na + nb;) {
		if (j < na)
			p[i++] = a[j++];
		if (k < nb)
			p[i++] = b[k++];
	}
}

void
test(int *a, int *b, size_t na, size_t nb, int *p)
{
	size_t i;

	bridge(a, b, na, nb, p);
	printf("[");
	for (i = 0; i < na + nb; i++) {
		if (isalpha(p[i]))
			printf("%c", p[i]);
		else
			printf("%d", p[i]);
		if (i + 1 < na + nb)
			printf(" ");
	}
	printf("]\n");
}

int
main(void)
{
	int p[80];

	int a1[] = { 'A', 'A', 'A' };
	int b1[] = { 'B', 'B', 'B' };

	int a2[] = { 'C', 'C', 'C' };
	int b2[] = { 'D' };

	int a3[] = { 1, 3, 5, 7 };
	int b3[] = { 2, 4, 6 };

	int a4[] = { 10, 9, 8 };
	int b4[] = { 1, 2, 3, 4 };

	int a5[] = { 'h', 'h', 'h' };
	int b5[] = { 'a', 'a', 'a' };

	int a6[] = { 1 };
	int b6[] = { 2, 5, 15, -23, 7, 57, 658, 2 };

	test(a1, b1, nelem(a1), nelem(b1), p);
	test(a2, b2, nelem(a2), nelem(b2), p);
	test(a3, b3, nelem(a3), nelem(b3), p);
	test(a4, b4, nelem(a4), nelem(b4), p);
	test(a5, b5, nelem(a5), nelem(b5), p);
	test(a6, b6, nelem(a6), nelem(b6), p);

	return 0;
}
