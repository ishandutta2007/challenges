/*

Chefland has all the cities on a straight line. There are N cities in Chefland numbered 1 to N. City i is located at coordinate xi on the x-axis. Guru wants to travel from city A to city B. He starts at time t=0. He has following choices to travel.

He can walk 1 metre in P secs.
There is a train that travels from city C to city D which travels 1 metre in Q secs which starts at time t=Y secs. Guru can take the train only at city C and leave the train only at city D.
Can you help Guru find the minimum time he will need to travel from city A to B. Note that you cannot board the train after time t =Y.

Input:

First line will contain T, number of testcases. Then the testcases follow.
First line of each testcase contains eight space separated integers N,A,B,C,D,P,Q,Y.
Second line of each testcase contains N space-separated integers with the i-th integer representing xi.

Output:

For each testcase, output in a single line containing the minimum travel time.

Constraints

1≤T≤300
2≤N≤300
−1000≤xi≤1000
0≤Y≤100000
1≤A,B,C,D≤n
A≠B
C≠D
1≤P,Q≤100
xi<xj if i<j

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
mintime(int *l, size_t n, size_t a, size_t b, size_t c, size_t d, int p, int q, int y)
{
	int w, t;

	if (a == 0 || b == 0 || c == 0 || d == 0)
		return -1;

	if (--a >= n || --b >= n || --c >= n || --d >= n)
		return -1;

	w = abs(l[b] - l[a]) * p;
	t = INT_MAX;
	if (abs(l[c] - l[a]) * p < y)
		t = y + abs(l[d] - l[c]) * q + abs(l[d] - l[b]) * p;
	return min(w, t);
}

int
main(void)
{
	int l1[] = {1, 2, 3, 4};

	assert(mintime(l1, nelem(l1), 1, 3, 2, 4, 3, 2, 4) == 6);

	return 0;
}
