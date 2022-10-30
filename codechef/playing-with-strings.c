/*

Chef usually likes to play cricket, but now, he is bored of playing it too much, so he is trying new games with strings.
Chef's friend Dustin gave him binary strings S and R, each with length N, and told him to make them identical.
However, unlike Dustin, Chef does not have any superpower and Dustin lets Chef perform only operations of one type: choose any pair of integers (i,j) such that 1≤i,j≤N and swap the i-th and j-th character of S.
He may perform any number of operations (including zero).

For Chef, this is much harder than cricket and he is asking for your help. Tell him whether it is possible to change the string S to the target string R only using operations of the given type.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains a binary string S.
The third line contains a binary string R.

Output

For each test case, print a single line containing the string "YES" if it is possible to change S to R or "NO" if it is impossible (without quotes).

Constraints
1≤T≤400
1≤N≤100
|S|=|R|=N
S and R will consist of only '1' and '0'

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

void
count(const char *s, size_t *a, size_t *b)
{
	size_t i;

	*a = *b = 0;
	for (i = 0; s[i]; i++) {
		*a += (s[i] == '0');
		*b += (s[i] == '1');
	}
}

bool
possible(const char *s, const char *r)
{
	size_t s0, s1;
	size_t r0, r1;

	count(s, &s0, &s1);
	count(r, &r0, &r1);
	return s0 == r0 && s1 == r1;
}

int
main(void)
{
	assert(possible("11000", "01001") == true);
	assert(possible("110", "001") == false);

	return 0;
}
