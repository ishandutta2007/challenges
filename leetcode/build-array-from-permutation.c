/*

Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.

A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).

Example 1:

Input: nums = [0,2,1,5,3,4]
Output: [0,1,2,4,5,3]
Explanation: The array ans is built as follows: 
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
    = [0,1,2,4,5,3]

Example 2:

Input: nums = [5,0,1,2,3,4]
Output: [4,5,0,1,2,3]
Explanation: The array ans is built as follows:
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
    = [4,5,0,1,2,3]

Constraints:

    1 <= nums.length <= 1000
    0 <= nums[i] < nums.length
    The elements in nums are distinct.

Follow-up: Can you solve it without using an extra space (i.e., O(1) memory)?

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
build(int *a, size_t n, int *p)
{
	size_t i;

	for (i = 0; i < n; i++)
		p[i] = a[a[i]];
}

void
test(int *a, size_t n, int *r)
{
	int p[128];

	build(a, n, p);
	assert(!memcmp(p, r, sizeof(*r) * n));
}

int
main(void)
{
	int a1[] = {0, 2, 1, 5, 3, 4};
	int r1[] = {0, 1, 2, 4, 5, 3};

	int a2[] = {5, 0, 1, 2, 3, 4};
	int r2[] = {4, 5, 0, 1, 2, 3};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);

	return 0;
}
