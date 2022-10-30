/*

Lapindrome is defined as a string which when split in the middle, gives two halves having the same characters and same frequency of each character.
If there are odd number of characters in the string, we ignore the middle character and check for lapindrome. For example gaga is a lapindrome, since the two halves ga and ga have the same characters with same frequency.
Also, abccab, rotor and xyzxy are a few examples of lapindromes. Note that abbaab is NOT a lapindrome. The two halves contain the same characters but their frequencies do not match.
Your task is simple. Given a string, you need to tell if it is a lapindrome.

Input:

First line of input contains a single integer T, the number of test cases.
Each test is a single line containing a string S composed of only lowercase English alphabet.

Output:

For each test case, output on a separate line: "YES" if the string is a lapindrome and "NO" if it is not.

Constraints:
1 ≤ T ≤ 100
2 ≤ |S| ≤ 1000, where |S| denotes the length of S

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool
lapindrome(const char *s)
{
	size_t h[2][256];
	size_t i, j, n;
	int l, r;

	n = strlen(s);
	if (n == 0)
		return true;

	memset(h, 0, sizeof(h));
	i = 0;
	j = n - 1;
	while (i < j) {
		l = s[i] & 0xff;
		r = s[j] & 0xff;

		h[0][l]++;
		h[1][r]++;

		i++;
		j--;
	}

	return !memcmp(h[0], h[1], sizeof(h[1]));
}

int
main(void)
{
	assert(lapindrome("gaga") == true);
	assert(lapindrome("abcde") == false);
	assert(lapindrome("rotor") == true);
	assert(lapindrome("xyzxy") == true);
	assert(lapindrome("abbaab") == false);
	assert(lapindrome("ababc") == false);

	return 0;
}
