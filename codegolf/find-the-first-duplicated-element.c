/*

Given an array a that contains only numbers in the range from 1 to a.length, find the first duplicate number for which the second occurrence has the minimal index.
In other words, if there are more than 1 duplicated numbers, return the number for which the second occurrence has a smaller index than the second occurrence of the other number does.
If there are no such elements, your program / function may result in undefined behaviour.

Example:

For a = [2, 3, 3, 1, 5, 2], the output should be firstDuplicate(a) = 3.

There are 2 duplicates: numbers 2 and 3. The second occurrence of 3 has a smaller index than the second occurrence of 2 does, so the answer is 3.

For a = [2, 4, 3, 5, 1], the output should be firstDuplicate(a) = -1.

This is code-golf, so shortest answer in bytes wins.

BONUS: Can you solve it in O(n) time complexity and O(1) additional space complexity?

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/
int
duplicate(int *a, size_t n)
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		j = abs(a[i]) - 1;
		if (a[j] >= 0)
			a[j] = -a[j];
		else
			return abs(a[i]);
	}
	return -1;
}

int
main(void)
{
	int a1[] = {2, 3, 3, 1, 5, 2};
	int a2[] = {1, 2, 3, 1, 3, 6, 6};
	int a3[] = {2, 4, 3, 5, 1};
	int a4[] = {1, 2, 3, 3};

	assert(duplicate(a1, nelem(a1)) == 3);
	assert(duplicate(a2, nelem(a2)) == 1);
	assert(duplicate(a3, nelem(a3)) == -1);
	assert(duplicate(a4, nelem(a4)) == 3);

	return 0;
}
