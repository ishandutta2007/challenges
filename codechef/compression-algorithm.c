/*

Mr. X has come up with a new string compression algorithm. Consider a string of length N which contains up to K distinct characters.
The compression algorithm works as follows: Replace each maximal contiguous substring containing only one distinct character (repeated an arbitrary number of times) and replace it by 2 values: the character and the length of the substring.

For example, the string "aabbaaa" will be compressed to "a, 2, b, 2, a, 3". Thus the length of the compressed string is 6.

Since Mr. X is living in advanced times, the length of any integer is considered to be 1. For example, if a string is compressed to "a, 111, b, 13", then its length after compression is considered to be 4.

To test his algorithm, he needs to know the expected length of the compressed string for given N and K if the input string is randomly uniformly chosen from all possibilities. He wants to run this experiment multiple times for different N, K and needs your help.

Input

The first line of the input contains an integer T denoting the number of queries. The description of T test cases follows.

The first and only line of each test case contains two integers N and K denoting the number of letters in the input string and the maximum number of distinct characters that can be present in the string.

Output

For each test case, output a single line containing the expected length of the compressed string. Your answer will be considered correct if the absolute error is less than 10-2

Constraints
1 ≤ T ≤ 10^5
1 ≤ N, K ≤ 10^9

*/

#include <assert.h>

double
distinct(int n, int k)
{
	double r;

	r = (n - 1) * (k - 1);
	r /= k;
	r += 1;
	r *= 2;
	return r;
}

int
main(void)
{
	assert(distinct(3, 1) == 2.0);
	assert(distinct(3, 2) == 4.0);

	return 0;
}
