/*

A string is called a Palpal string if it can be divided into contiguous substrings such that:

Each character of the whole string belongs to exactly one substring.
Each of these substrings is a palindrome with length greater than 1.
For example, "abbbaddzcz" is a Palpal string, since it can be divided into "abbba", "dd" and "zcz".

You are given a string s. You may rearrange the characters of this string in any way you choose. Find out if it is possible to rearrange them in such a way that you obtain a Palpal string.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single string s.

Output

For each test case, print a single line containing the string "YES" if the characters of s can be rearranged to form a Palpal string or "NO" if it is impossible (without quotes).

You may print each character of each string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤105
1≤|s|≤100
s contains only lowercase English letters
the sum of |s| over all test cases does not exceed 10^6

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
palpal(const char *s)
{
	size_t h[256];
	size_t a, b, i;

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++)
		h[s[i] & 0xff]++;

	a = b = 0;
	for (i = 0; i < nelem(h); i++) {
		if (h[i] == 1)
			a += 1;
		else if (!(h[i] & 1))
			b += h[i] / 2;
		else if (h[i] > 3 && (h[i] & 1))
			b += (h[i] - 3) / 2;
	}
	return b >= a;
}

int
main(void)
{
	assert(palpal("acbbbadzdz") == true);
	assert(palpal("abcd") == false);
	assert(palpal("xyxyxy") == true);

	return 0;
}
