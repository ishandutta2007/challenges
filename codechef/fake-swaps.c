/*

You are given two binary strings S and P. You need to convert S into P using the following operation any number of times (possibly zero):

Pick three binary values X, Y, and Z, such that at least one of them is equal to 1 and at least one of them is equal to 0. Then, pick three distinct indices i, j, and k, and assign Si=X, Sj=Y, and Sk=Z.
Determine whether it's possible to convert S into P.

Input Format

The first line contains an integer T denoting the number of test cases. The T test cases then follow.
The first line of each test case contains N denoting the length of S and P.
The second line of each test case contains S.
The third line of each test case contains P.

Output Format

For each test case, output on one line YES if it is possible to convert S to P, or NO if it is not possible to do so. Output is case insensitive.

Constraints
1≤T≤1000
3≤N≤1000
|S|=|P|=N

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

size_t
count(const char *s, int c)
{
	size_t i, r;

	r = 0;
	for (i = 0; s[i]; i++)
		r += (s[i] == c);
	return r;
}

bool
convertable(const char *s, const char *p)
{
	size_t c, n, m;

	n = strlen(s);
	m = strlen(p);
	if (n != m)
		return false;

	c = count(p, '1');
	if (c == 0 || c == n)
		return !strcmp(s, p);

	return true;
}

int
main(void)
{
	assert(convertable("1001", "0101") == true);
	assert(convertable("111", "000") == false);

	return 0;
}
