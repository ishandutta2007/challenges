/*

Rachel has a date and tells everyone she is not mad at Ross but doesn't have any feelings for him anymore either.
Seeing her date for the first time, everyone notices that he looks exactly like Ross. However, Rachel refuses to believe so.

Rachel makes a list of N characteristics and assigns a score to both Ross and Russ for each of the characteristics.
Ross' ith characteristic has a score equal to Ai and Russ' ith characteristic has a score equal to Bi.
Rachel decides that Russ looks exactly like Ross if the following condition is satisfied for at least X distinct values of j, 1≤j≤N :
|Aj−Bj|≤K.

Help Rachel in finding if both are alike.

Input Format

First line will contain T, number of testcases. Then the testcases follow.
First line for each test case contains three integers N, X and K, denoting the number of characteristics, the minimum number of characteristics and maximum possible score difference.
Second line for each test case contains N integers denoting array A.
Third line for each test case contains N integers denoting array B.

Output Format

For each test case print "YES" if they are alike, else print "NO".

You may print each character of each string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤10
1≤N≤10^3
1≤Ai,Bi≤10^3
1≤X≤n
0≤K≤10^3

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
alike(int *a, int *b, size_t n, int x, int k)
{
	size_t i;
	int c;

	c = 0;
	for (i = 0; i < n; i++)
		c += (abs(a[i] - b[i]) <= k);
	return c >= x;
}

int
main(void)
{
	int a1[] = {1, 7, 7, 5};
	int b1[] = {1, 8, 1, 2};

	int a2[] = {9, 8, 7, 2, 5};
	int b2[] = {5, 4, 1, 8, 9};

	int a3[] = {2, 3, 4};
	int b3[] = {2, 3, 4};

	assert(alike(a1, b1, nelem(a1), 2, 2) == true);
	assert(alike(a2, b2, nelem(a2), 1, 3) == false);
	assert(alike(a3, b3, nelem(a3), 3, 0) == true);

	return 0;
}
