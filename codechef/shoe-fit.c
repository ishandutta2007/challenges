/*

You have three shoes of the same size lying around. Each shoe is either a left shoe (represented using 0) or a right shoe (represented using 1).
Given A, B, C, representing the information for each shoe, find out whether you can go out now, wearing one left shoe and one right shoe.

Input Format

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, three integers A, B, C.

Output Format

For each test case, output in a single line the answer: 1 if it's possible to go out with a pair of shoes and 0 if not.

Constraints
1≤T≤8
0≤A,B,C≤1

*/

#include <assert.h>

int
fit(int a, int b, int c)
{
	if (a == 0 && (b == 1 || c == 1))
		return 1;
	if (a == 1 && (b == 0 || c == 0))
		return 1;
	return 0;
}

int
main(void)
{
	assert(fit(0, 0, 0) == 0);
	assert(fit(0, 1, 1) == 1);
	assert(fit(1, 0, 1) == 1);

	return 0;
}
