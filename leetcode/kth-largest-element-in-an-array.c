/*

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element. 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

 

Constraints:

    1 <= k <= nums.length <= 104
    -104 <= nums[i] <= 104

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swap(int *x, int *y)
{
	int t;

	t = *y;
	*y = *x;
	*x = t;
}

int
cmp(int x, int y)
{
	if (x > y)
		return -1;
	if (x == 0)
		return 0;
	return 1;
}

size_t
partition(int *a, size_t l, size_t r, int (*cmp)(int, int))
{
	size_t i, j;
	int v;

	v = a[r];
	for (i = j = l; r && j <= r - 1; j++) {
		if (cmp(a[j], v) <= 0)
			swap(&a[i++], &a[j]);
	}
	swap(&a[i], &a[r]);
	return i;
}

// https://www.geeksforgeeks.org/quickselect-algorithm/
int
kth(int *a, size_t l, size_t r, size_t k, int (*cmp)(int, int))
{
	size_t i;

	if (!(0 < k && k <= r - l + 1))
		return INT_MIN;

	i = partition(a, l, r, cmp);
	if (i - l == k - 1)
		return a[i];
	if (i - l > k - 1)
		return kth(a, l, i - 1, k, cmp);
	return kth(a, i + 1, r, k - i + l - 1, cmp);
}

void
test(int *a, size_t n, size_t k, int r)
{
	assert(kth(a, 0, n - 1, k, cmp) == r);
}

int
main(void)
{
	int a1[] = {3, 2, 1, 5, 6, 4};
	int a2[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
	int a3[] = {1, 2, 3, 4, 5, 6, 7};

	test(a1, nelem(a1), 2, 5);
	test(a2, nelem(a2), 4, 4);
	test(a3, nelem(a3), 3, 5);
	test(a3, nelem(a3), 1, 7);
	test(a3, nelem(a3), 7, 1);

	return 0;
}
