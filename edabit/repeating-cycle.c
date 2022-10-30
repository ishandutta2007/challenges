/*

Below is an example of a repeating cycle.

isRepeatingCycle([1, 2, 3, 1, 2], 3) => true
// Since the first two elements of [1, 2, 3] equals [1, 2]

Below is an example of a non-repeating cycle.

isRepeatingCycle([1, 2, 3, 1, 3], 3) => false
// Since [1, 2, 3] != [1, 3]

You are tasked with writing a function that takes in two inputs: (1) an array of integers; (2) the length of each cycle.
Return the boolean value true if the array is a repeating cycle, and false if the array is a non-repeating cycle.

Notes

    All cycles begin with the first element of the array.
    Return true if the cycle length is greater than the array length.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
isrepeatingcycle(int *a, size_t n, size_t m)
{
	size_t i;

	if (m >= n)
		return 1;

	for (i = 0; i < n; i++) {
		if (a[i % m] != a[i])
			return 0;
	}
	return 1;
}

int
main(void)
{
	int a1[] = {1, 2, 3, 1, 2, 3, 1};
	int a2[] = {1, 2, 3, 4, 2, 3, 1};
	int a3[] = {1, 2, 1, 2, 2};
	int a4[] = {1, 2, 1, 2, 1, 2, 1};
	int a5[] = {1, 2, 1, 2, 1, 2, 1};
	int a6[] = {1, 2, 1, 2, 1, 2, 1};
	int a7[] = {1, 1, 1, 1};
	int a8[] = {1, 2, 1, 9};
	int a9[] = {1, 1, 3, 1, 1};

	printf("%d\n", isrepeatingcycle(a1, nelem(a1), 3));
	printf("%d\n", isrepeatingcycle(a2, nelem(a2), 4));
	printf("%d\n", isrepeatingcycle(a3, nelem(a3), 2));
	printf("%d\n", isrepeatingcycle(a4, nelem(a4), 3));
	printf("%d\n", isrepeatingcycle(a5, nelem(a5), 2));
	printf("%d\n", isrepeatingcycle(a6, nelem(a6), 4));
	printf("%d\n", isrepeatingcycle(a7, nelem(a7), 3));
	printf("%d\n", isrepeatingcycle(a8, nelem(a8), 4));
	printf("%d\n", isrepeatingcycle(a9, nelem(a9), 7));

	return 0;
}
