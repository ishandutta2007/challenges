/*

Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
Find the two elements that appear only once. You can return the answer in any order.

Follow up: Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Example 2:

Input: nums = [-1,0]
Output: [-1,0]

Example 3:

Input: nums = [0,1]
Output: [1,0]



Constraints:

    1 <= nums.length <= 30000
     Each integer in nums will appear twice, only two integers will appear once.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
singlenumber(int *a, size_t n, int r[2])
{
	size_t i;
	int v, b;

	v = 0;
	for (i = 0; i < n; i++)
		v ^= a[i];
	b = v & ~(v - 1);

	r[0] = r[1] = 0;
	for (i = 0; i < n; i++) {
		if (a[i] & b)
			r[0] ^= a[i];
		else
			r[1] ^= a[i];
	}
}

void
test(int *a, size_t n, int r[2])
{
	int p[2];

	singlenumber(a, n, p);
	assert((p[0] == r[0] && p[1] == r[1]) ||
	       (p[0] == r[1] && p[1] == r[0]));
}

int
main(void)
{
	int a1[] = { 1, 2, 1, 3, 2, 5 };
	int r1[] = { 3, 5 };

	int a2[] = { -1, 0 };
	int r2[] = { -1, 0 };

	int a3[] = { 0, 1 };
	int r3[] = { 1, 0 };

	int a4[] = { 2, 3, 7, 9, 11, 2, 3, 11 };
	int r4[] = { 7, 9 };

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(a4, nelem(a4), r4);

	return 0;
}
