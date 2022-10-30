/*

Chef has two positive integers A and B. He can tamper with them by choosing a digit in the decimal representation of A and a digit in the decimal representation of B and swapping these digits.
This operation may be performed at most once.

Find the maximum possible sum of the resulting numbers which Chef can obtain.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers A and B.

Output
For each test case, print a single line containing one integer ― the maximum sum.

Constraints
1≤T≤1,000
1≤A,B≤99

*/

#include <assert.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int
maxsum(int a, int b)
{
	int a1, a2;
	int b1, b2;
	int r;

	a1 = a / 10;
	a2 = a % 10;
	b1 = b / 10;
	b2 = b % 10;

	r = a + b;
	if (a1 != 0)
		r = max(r, (b1 * 10) + (b2 * 10) + a1 + a2);
	if (b1 != 0)
		r = max(r, (a1 * 10) + (a2 * 10) + b1 + b2);
	return r;
}

int
main(void)
{
	assert(maxsum(13, 82) == 104);
	assert(maxsum(9, 24) == 96);
	assert(maxsum(20, 30) == 50);

	return 0;
}
