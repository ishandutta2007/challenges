/*

Mona has created a method to sort an array in ascending order.

Starting from the left of the array, she compares numbers by pairs. If the first pair is ordered [smaller number, larger number], she moves on.
If the first pair is ordered [larger number, smaller number], she swaps the two integers before moving on to the next pair.
She repeats this process until she reaches the end of the array.

Then, she moves back to the beginning of the array and repeats this process until the entire array is sorted.

If the unsorted array is: [3, 9, 7, 4], she will perform the following steps (note Swaps here refers to cumulative swaps):

    She starts with the first pair.
    [3, 9] is in order, move on. Array: [3, 9, 7, 4]. Swaps: 0.
    [9, 7] is not. Swap. Array: [3, 7, 9, 4]. Swaps: 1
    [9, 4] is not. Swap. Array: [3, 7, 4, 9]. Swaps: 2
    Check if array is sorted. It is not, so start over at first pair.
    [3, 7] is in order, move on. Array: [3, 7, 4, 9]. Swaps: 2
    [7, 4] is not. Swap. Array: [3, 4, 7, 9]. Swaps: 3.
    [7, 9] is in order, move on. Array: [3, 4, 7, 9]. Swaps: 3.
    Check if array is sorted. It is. End.

Sorting the array [3, 9, 7, 4] takes her 3 swaps. Write a function that takes in an unsorted array and returns the number of swaps it takes for the array to be sorted according to Mona's algorithm.
Examples

numberOfSwaps([5, 4, 3]) ➞ 3

numberOfSwaps([1, 3, 4, 5]) ➞ 0

numberOfSwaps([5, 4, 3, 2]) ➞ 6

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swap(int *x, int *y)
{
	int t;

	t = *y;
	*y = *x;
	*x = t;
}

size_t
mona(int *a, size_t n)
{
	size_t i, j, r;

	r = 0;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(&a[i], &a[j]);
				r++;
			}
		}
	}
	return r;
}

int
main(void)
{
	int a1[] = {3, 9, 7, 4};
	int a2[] = {5, 4, 3};
	int a3[] = {5, 4, 3, 2};
	int a4[] = {1, 2, 4, 3};
	int a5[] = {1, 2, 5, 4, 3};
	int a6[] = {1, 3, 4, 5};
	int a7[] = {1, 2};

	assert(mona(a1, nelem(a1)) == 3);
	assert(mona(a2, nelem(a2)) == 3);
	assert(mona(a3, nelem(a3)) == 6);
	assert(mona(a4, nelem(a4)) == 1);
	assert(mona(a5, nelem(a5)) == 3);
	assert(mona(a6, nelem(a6)) == 0);
	assert(mona(a7, nelem(a7)) == 0);

	return 0;
}
