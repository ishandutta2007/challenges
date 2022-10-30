/*

You're a professional hacker and your boss has just ordered you to help a candidate win an upcoming election. Your task is to alter the voting machines data to boost the candidate's results.

Voting machines store voting results as two integers : the number of votes for your candidate (v1) and the number of votes for their opponent (v2).

After weeks of research, you have found a security hole in the system and you can increase the value of v1 by an integer x, and decrease the value of v2 by the same x. But there is a constraint, you have to keep the security hash code constant:

security hash code : (v1 + v2*2) modulo 7
Also, the value for x must be minimal so your changes can go unnoticed.

Your program should accept as input v1 and v2 ; it should output the optimal value for x so v1>v2.

There are some cases for which you cannot hack the results; you don't have to handle them (this might lead to problems with your boss, but that's another story).

Test cases

100,123 --> 14
47,23 --> 0
40,80 --> 21
62,62 --> 7
1134,2145 --> 511

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

int
hash(int a, int b)
{
	return (a + (b * 2)) % 7;
}

int
find(int a, int b)
{
	int h, x;
	int u, v;

	if (a < 0 || b < 0)
		return -1;
	if (a > b)
		return 0;

	h = hash(a, b);
	for (x = 1;; x++) {
		if (INT_MAX - a < x || x > b)
			return -1;

		u = a + x;
		v = b - x;
		if (u > v && h == hash(u, v))
			break;
	}
	return x;
}

int
main(void)
{
	assert(find(100, 123) == 14);
	assert(find(47, 23) == 0);
	assert(find(40, 80) == 21);
	assert(find(62, 62) == 7);
	assert(find(1134, 2145) == 511);

	return 0;
}
