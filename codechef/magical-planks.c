/*

Ryan is a boy from a small town, who has been given a task by his father. He has N wooden planks, numbered from 1 to N, which are colored either black or white.

His task is to color all planks the same color! But there is some magic in the winds of his small town. Whenever he colors the ith ( plank which has the color Si ) to a color P then following events happen:

if 2≤i≤N and Si=Si−1, then color of (i−1)th plank changes to P.
if 1≤i≤N−1 and Si=Si+1, then color of (i+1)th plank changes to P.
Now this process continues for the newly colored planks also. If none of the neighbors have same color, then nothing happens to the neighbors.

Suppose Ryan has planks which have their coloring : BBWWWB If Ryan colors the fourth plank( whose color is W ) to color B, then the finally the planks would be colored as following:

BBBBBB

Ryan can choose any one of the N planks and change its color as many times as he wants. Determine the minimum number of times Ryan has to paint a plank such that all planks get the same color at the end.

Input Format

First line will contain T, number of testcases. Then the testcases follow.
The first line of each test case consists of an integer N the number of planks
Second line of each test case consists of a string S of size N,where the i th character denotes the color of plank i

Output Format

For each testcase, output a single integer denoting the minimum number of times Ryan has to paint a single plank such that all planks get the same color at the end.

Constraints
1≤T≤10^5
1≤N≤10^5
S consists only of characters B and W
The sum of N over all cases doesn't exceed 10^5.

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

size_t
planktime(const char *s)
{
	size_t b, w;
	size_t i;
	char c;

	b = w = 0;
	c = s[0];
	for (i = 0; s[i]; i++) {
		if (s[i] == c)
			continue;

		b += (c == 'B');
		w += (c == 'W');
		c = s[i];
	}
	b += (c == 'B');
	w += (c == 'W');

	return min(b, w);
}

int
main(void)
{
	assert(planktime("BBWWWB") == 1);
	assert(planktime("WWBWB") == 2);
	assert(planktime("BB") == 0);
	assert(planktime("WWBBBBBWW") == 1);

	return 0;
}
