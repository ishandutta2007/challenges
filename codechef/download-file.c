/*

Chef has recently got a broadband internet connection. His history of internet data usage is provided as below.

During the first T1 minutes, the internet data used was D1 MBs per minute, and during the next T2 minutes, it was D2 MBs per minute, and so on till during last TN minutes it was DN MBs per minute.

The internet provider charges the Chef 1 dollar for every 1 MB data used, except for the first K minutes, when the internet data is free as part of the plan provided to Chef.

Please find out the total amount that Chef has to pay the internet provider (in dollars).

Input

First line of the input contains a single integer TC the number of test cases. Description of TC test cases follow.
First line of each test case contains two space separated integers N and K.
Next N lines of each test case contains information about the internet data usage. Specifically, in the i-th line, there will be two space separated integers: Ti and Di.

Output

For each test case output a single integer in separate line, the amount that Chef has to pay in dollars.

Constraints
1 ≤ TC ≤ 1,000
1 ≤ N ≤ 10
0 ≤ K ≤ T1 + T2 + ... + TN
1 ≤ Ti, Di ≤ 10

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
pay(int a[][2], size_t n, int k)
{
	int d, r, t;
	size_t i;

	r = 0;
	for (i = 0; i < n; i++) {
		t = a[i][0];
		d = a[i][1];
		if (t <= k)
			k -= t;
		else {
			r += (t - k) * d;
			k = 0;
		}
	}
	return r;
}

int
main(void)
{
	int a1[][2] = {
	    {2, 1},
	    {2, 3},
	};

	int a2[][2] = {
	    {1, 2},
	    {2, 3},
	};

	int a3[][2] = {
	    {1, 2},
	    {2, 4},
	    {10, 10},
	};

	assert(pay(a1, nelem(a1), 2) == 6);
	assert(pay(a2, nelem(a2), 2) == 3);
	assert(pay(a3, nelem(a3), 0) == 110);

	return 0;
}
