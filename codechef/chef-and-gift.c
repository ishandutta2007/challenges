/*

Today is chef's friend's birthday. He wants to give a gift to his friend. So he was desperately searching for some gift here and there.
Fortunately, he found an array a of size n lying around. The array contains positive integers. Chef's friend likes even numbers very much.
So for the gift, chef will choose a consecutive non-empty segment of the array. The segment should contain exactly k even integers.
Though it can have any number of odd integers. He will then pick that segment and gift it to his friend.
But there is a problem. It might not be always possible for the chef to choose such a segment. Please tell whether it is possible for chef to select some gift or not?

Input

First line of the input contains a single integer T denoting number of test cases.
For each test case, first line contains two space separated integers n, k.
Next line contains n space separated integers denoting content of array a.
It is also guaranteed that all the numbers in the array a are distinct.

Output

For each test case, print a single line containing "YES" or "NO" (without quotes) corresponding to the situation.

Constraints
1 ≤ T ≤ 10
1 ≤ n ≤ 50
0 ≤ k ≤ n
1 ≤ a i ≤ 100

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
possible(int *a, size_t n, size_t k)
{
	size_t c, i;

	c = 0;
	for (i = 0; i < n; i++)
		c += !(a[i] & 1);

	if (k == 0 && c == n)
		return false;
	return c >= k;
}

int
main(void)
{
	int a1[] = {1, 2};
	int a2[] = {2, 6, 5};
	int a3[] = {2, 4, 5};
	int a4[] = {1, 2, 4, 5};

	assert(possible(a1, nelem(a1), 1) == true);
	assert(possible(a2, nelem(a2), 2) == true);
	assert(possible(a3, nelem(a3), 3) == false);
	assert(possible(a4, nelem(a4), 2) == true);

	return 0;
}
