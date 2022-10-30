// finds the maximum sum you can make from a subsequence in a sequence of integers
// dumbest way is O(n^3), you can optimize it by keeping a running
// sum which is O(n^2), this implements an O(n) algorithm
// which is while going through the array keep the max of the running
// sum, if the running sum ever becomes negative, reset the current count
// of running sum to 0 because we know whatever comes after it will be negative

#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
subseq(const int *array, size_t size)
{
	int max, cur;
	size_t i;

	max = INT_MIN;
	cur = 0;
	for (i = 0; i < size; i++) {
		cur += array[i];
		if (max < cur)
			max = cur;
		if (cur < 0)
			cur = 0;
	}

	return max;
}

int
main(void)
{
	static const int array[][10] = {
	    {1, 2, 3, 4, 5},
	    {-1, 2, 3, 4, 5},
	    {5, 4, 1, -3, 2, 4, 2, 1, 39, -48},
	};

	int max;
	size_t i;

	for (i = 0; i < nelem(array); i++) {
		max = subseq(array[i], nelem(array[i]));
		printf("%d\n", max);
	}
	return 0;
}
