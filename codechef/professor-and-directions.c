/*

The Professor is facing the North. Tokyo is in trouble, and she is facing the South. Professor being her guardian angel wants to help her.

So, The Professor will follow some instructions, given as a string S of length N, and will turn either left or right according to these instructions.
He can save Tokyo only if after following a substring of instructions he will face in the same direction that Tokyo is facing.

Will the Professor be able to save Tokyo?

Input Format

The first line contains an integer T denoting the number of test cases. The T test cases then follow.
The first line of each test case contains N.
The second line contains a string that contains only 'L' and 'R', where 'L' represents left and 'R' represents right.

Output Format

For each test case, output "YES" if the Professor will be able to save Tokyo and "NO" otherwise.

Output is case insensitive, which means that "yes", "Yes", "YEs", "no", "nO" - all such strings will be acceptable.

Constraints
1≤T≤100
2≤N≤10^5
The string S consists of uppercase characters 'L' and 'R' only.
The sum of N over all test cases does not exceed 10^6.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
save(const char *s)
{
	size_t i;

	for (i = 0; s[i] && s[i + 1]; i++) {
		if (s[i] == 'R' && s[i + 1] == 'R')
			return true;
		if (s[i] == 'L' && s[i + 1] == 'L')
			return true;
	}
	return false;
}

int
main(void)
{
	assert(save("LRLRRRLRLLLL") == true);
	assert(save("LR") == false);
	assert(save("LRRL") == true);

	return 0;
}
