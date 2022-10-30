/*

Chef has X coins worth 1 rupee each and Y coins worth 2 rupees each.
He wants to distribute all of these X+Y coins to his two sons so that the total value of coins received by each of them is the same.
Find out whether Chef will be able to do so.

Input Format

The first line of input contains a single integer T, denoting the number of testcases. The description of T test cases follows.
Each test case consists of a single line of input containing two space-separated integers X and Y.

Output Format

For each test case, print "YES" (without quotes) if Chef can distribute all the coins equally and "NO" otherwise.
You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤10^3
0≤X,Y≤10^8
X+Y>0

*/

#include <assert.h>
#include <stdbool.h>

bool
handout(int x, int y)
{
	if (x > 0 && (x + 2 * y) % 2 == 0)
		return true;
	if ((x + 2 * y) % 4 == 0)
		return true;
	return false;
}

int
main(void)
{
	assert(handout(2, 2) == true);
	assert(handout(1, 3) == false);
	assert(handout(4, 0) == true);
	assert(handout(1, 10) == false);

	return 0;
}
