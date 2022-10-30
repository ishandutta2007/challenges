/*

Initially, Chef is at coordinate 0 on X-axis. For each i=1,2,…,N in order, Chef does the following:

If Chef is at a non-negative coordinate, he moves i steps backward (i.e, his position's coordinate decreases by i), otherwise he moves i steps forward (i.e, his position's coordinate increases by i).
You are given the integer N. Find the final position of Chef on the X-axis after N operations.

Input Format
The first line of input contains an integer T, denoting the number of test cases. The T test cases then follow:
The first and only line of each test case contains an integer N.

Output Format
For each test case, output in a single line the final position of Chef on the X-axis after N operations.

Constraints
1≤T≤10^5
1≤N≤10^9

*/

#include <assert.h>

typedef long long vlong;

vlong
position(vlong n)
{
	vlong r;

	r = (n + 1) / 2;
	return (n & 1) ? -r : r;
}

int
main(void)
{
	assert(position(1) == -1);
	assert(position(2) == 1);
	assert(position(3) == -2);

	return 0;
}
