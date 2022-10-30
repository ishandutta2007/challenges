/*

Two sisters, A and B, play the piano every day. During the day, they can play in any order.
That is, A might play first and then B, or it could be B first and then A.
But each one of them plays the piano exactly once per day.
They maintain a common log, in which they write their name whenever they play.

You are given the entries of the log, but you're not sure if it has been tampered with or not. Your task is to figure out whether these entries could be valid or not.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of the test cases follows.
The first line of each test case contains a string s denoting the entries of the log.

Output

For each test case, output yes or no according to the answer to the problem.

Constraints
1≤T≤500
2≤|s|≤100
|s| is even
Each character of s is either 'A' or 'B'

*/

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

bool
legit(const char *s)
{
	size_t i;

	for (i = 0; s[i] && s[i + 1]; i += 2) {
		if (s[i] == s[i + 1])
			return false;
	}
	return !(i & 1);
}

int
main(void)
{
	assert(legit("AB") == true);
	assert(legit("ABBA") == true);
	assert(legit("ABAABB") == false);
	assert(legit("AA") == false);

	return 0;
}
