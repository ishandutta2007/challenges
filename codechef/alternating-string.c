/*

A binary string is called alternating if no two adjacent characters of the string are equal. Formally, a binary string T of length M is called alternating if Ti≠Ti+1 for each 1≤i<M.

For example, 0, 1, 01, 10, 101, 010, 1010 are alternating strings while 11, 001, 1110 are not.

You are given a binary string S of length N. You would like to rearrange the characters of S such that the length of the longest alternating substring of S is maximum. Find this maximum value.

A binary string is a string that consists of characters 0 and 1.
A string a is a substring of a string b if a can be obtained from b by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

Input Format
The first line of input contains an integer T, denoting the number of test cases. The T test cases then follow:
The first line of each test case contains an integer N.
The second line of each test case contains the binary string S.

Output Format
For each test case, output the maximum possible length of the longest alternating substring of S after rearrangement.

Constraints
1≤T≤10^4
1≤N≤10^5
S contains only the characters 0 and 1.
Sum of N over all test cases does not exceed 2⋅10^5

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
maximum(const char *s)
{
	size_t i;
	int z, o;

	z = o = 0;
	for (i = 0; s[i]; i++) {
		z += (s[i] == '0');
		o += (s[i] == '1');
	}
	return 2 * min(z, o) + (z != o);
}

int
main(void)
{
	assert(maximum("110") == 3);
	assert(maximum("1010") == 4);
	assert(maximum("0000") == 1);
	assert(maximum("1101101") == 5);

	return 0;
}
