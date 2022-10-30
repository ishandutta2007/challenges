/*

There are N positions in a queue. Given a binary string S of length N, where Si= '1' denotes, there is a person standing in the ith position.

The distance between two people standing in the ith and jth positions respectively in the queue is ∣i−j∣, where ∣x∣ denotes the absolute value of x.
Now, two people are considered to be friends if they are at a distance less than or equal to K.

Let's say, there are M people, P1,P2,…,PM standing one after another in a queue such that for each 1≤i<M, Pi and Pi+1 are friends, then all the M people are considered to be in a friend group.

For example, consider the string S= "1101001" and K=2.

Let's denote the people standing in the 1st, 2nd, 4th and 7th positions in the queue by P1,P2,P3,P4 respectively.
Now, P1 and P2 are friends as the distance between them is 1, P2 and P3 are also friends as the distance between them is 2.
P4 is not friend with anyone. Hence P1,P2,P3 form a friend group and P4 forms a separate friend group.

Now each person can move one position right or one position left or stay in the same position.
However, they can't move out of the queue. Find the minimum number of friend groups they can form if they move optimally.

It is possible that there is more than one person standing in the same position after the movements.

Input Format

The first line of input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two integers N,K.
The second line of each test case contains a string S.

Output Format

For each test case, print a single line containing one integer - the minimum number of friend groups.

Constraints
1≤T≤5⋅10^4
1≤N≤10^5
0≤K≤N
S contains only characters '0` and '1'
The sum of N over all test cases does not exceed 10^6.

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

size_t
groups(const char *s, size_t k)
{
	size_t c, i, l;
	int f;

	l = 0;
	f = 0;
	c = 0;
	for (i = 0; s[i]; i++) {
		if (s[i] == '0')
			continue;

		if (f != 0 && i - l <= k + 1)
			l = min(l + k, i + 1);
		else {
			f = 1;
			c = c + 1;
			l = i + 1;
		}
	}
	return c;
}

int
main(void)
{
	assert(groups("010010", 2) == 1);
	assert(groups("1001", 0) == 2);
	assert(groups("1101001", 2) == 1);

	return 0;
}
