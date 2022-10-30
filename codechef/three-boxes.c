/*

Chef has 3 boxes of sizes A, B, and C respectively.
He puts the boxes in bags of size D (A≤B≤C≤D).
Find the minimum number of bags Chef needs so that he can put each box in a bag.
A bag can contain more than one box if the sum of sizes of boxes in the bag does not exceed the size of the bag.

Input Format

The first line contains T denoting the number of test cases. Then the test cases follow.
Each test case contains four integers A, B, C, and D on a single line denoting the sizes of the boxes and bags.

Output Format

For each test case, output on a single line the minimum number of bags Chef needs.

Constraints
1≤T≤100
1≤A≤B≤C≤D≤100

*/

#include <assert.h>

int
bags(int a, int b, int c, int d)
{
	if (a + b + c <= d)
		return 1;
	if (a + b <= d)
		return 2;
	return 3;
}

int
main(void)
{
	assert(bags(2, 3, 5, 10) == 1);
	assert(bags(1, 2, 3, 5) == 2);
	assert(bags(3, 3, 4, 4) == 3);

	return 0;
}
