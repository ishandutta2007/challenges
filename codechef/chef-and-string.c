/*

There are N students standing in a row and numbered 1 through N from left to right.
You are given a string S with length N, where for each valid i, the i-th character of S is 'x' if the i-th student is a girl or 'y' if this student is a boy.
Students standing next to each other in the row are friends.

The students are asked to form pairs for a dance competition.
Each pair must consist of a boy and a girl.
Two students can only form a pair if they are friends.
Each student can only be part of at most one pair.
What is the maximum number of pairs that can be formed?

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single string S.

Output

For each test case, print a single line containing one integer ― the maximum number of pairs.

Constraints
1≤T≤100
1≤N≤10^5
|S|=N
S contains only characters 'x' and 'y'
the sum of N over all test cases does not exceed 3⋅10^5

*/

#include <assert.h>
#include <stdio.h>

size_t
maxpairs(const char *s)
{
	size_t i, r;
	int p;

	r = 0;
	p = 1;
	for (i = 0; s[i] && s[i + 1]; i++) {
		if (s[i] != s[i + 1] && p) {
			r = r + 1;
			p = 0;
		} else
			p = 1;
	}
	return r;
}

int
main(void)
{
	assert(maxpairs("xy") == 1);
	assert(maxpairs("xyxxy") == 2);
	assert(maxpairs("yy") == 0);

	return 0;
}
