/*

After solving programming problems for years, Chef has become lazy and decided to get a better physique by doing some weight lifting exercises.

On any regular day, Chef does N exercises at times A1,A2,…,AN (in minutes, all distinct) and each exercise provides a tension of B1,B2,…,BN units. In the period between two consecutive exercises, his muscles relax R units of tension per minute.

More formally, Chef's tension is described by a number x. Before any workouts, x=0. When he does a workout at time Ai, the tension x instantly increases by Bi. Between workouts, the number x decreases by R units per minute, maximized with 0.

Considering the time of exercise and hence tension to be negligible, find the maximum tension he will be feeling in his muscles during the entire period of his workout.

Input:

First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains 3 lines of input.
The first line will contain 2 space-separated integers N,R, number of timestamps at which Chef performs his exercise, and units of tension relaxed per minute.
The second line contains N space-separated integers A1,A2,…,AN.
The third line contains N space-separated integers B1,B2,…,BN.

Output:

For each testcase, output in a single line the maximum amount of tension Chef will have in his muscles.

Constraints
1≤T≤10
1≤N≤5⋅10^4
1≤R,Bi≤10^5
1≤Ai≤10^9
Ai−1<Ai, for all 2≤i≤N

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
tension(int *a, int *b, size_t n, int r)
{
	size_t i;
	int x, y;

	x = y = 0;
	for (i = 0; i < n; i++) {
		x += b[i];
		y = max(y, x);
		if (i + 1 < n)
			x -= r * (a[i + 1] - a[i]);
		x = max(x, 0);
	}
	return y;
}

int
main(void)
{
	int a1[] = {10};
	int b1[] = {10};

	int a2[] = {10, 11};
	int b2[] = {10, 10};

	int a3[] = {1, 2, 3};
	int b3[] = {1, 2, 3};

	assert(tension(a1, b1, nelem(a1), 2) == 10);
	assert(tension(a2, b2, nelem(a2), 2) == 18);
	assert(tension(a3, b3, nelem(a3), 1) == 4);

	return 0;
}
