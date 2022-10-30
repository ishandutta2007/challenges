/*

There are N cars (numbered 1 through N) on a circular track with length N. For each i (2≤i≤N), the i-th of them is at a distance i−1 clockwise from car 1, i.e. car 1 needs to travel a distance i−1 clockwise to reach car i.
Also, for each valid i, the i-th car has fi litres of gasoline in it initially.

You are driving car 1 in the clockwise direction. To move one unit of distance in this direction, you need to spend 1 litre of gasoline.
When you pass another car (even if you'd run out of gasoline exactly at that point), you steal all its gasoline.
Once you do not have any gasoline left, you stop.

What is the total clockwise distance travelled by your car?

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers f1,f2,…,fN.

Output

For each test case, print a single line containing one integer ― the total clockwise distance travelled.

Constraints
1≤T≤100
1≤N≤100
0≤fi≤100 for each valid i

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
distance(int *f, size_t n)
{
	size_t i;
	int d, g;

	if (n == 0)
		return 0;

	d = 0;
	g = f[0];
	for (i = 1; i < n && g > 0; i++) {
		d = d + 1;
		g = g - 1 + f[i];
	}
	return d + g;
}

int
main(void)
{
	int a1[] = {3, 0, 0, 0, 0};
	int a2[] = {1, 1, 1, 1, 1};
	int a3[] = {5, 4, 3, 2, 1};

	assert(distance(a1, nelem(a1)) == 3);
	assert(distance(a2, nelem(a2)) == 5);
	assert(distance(a3, nelem(a3)) == 15);

	return 0;
}
