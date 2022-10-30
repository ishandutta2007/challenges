/*

Only x hours are left for the March Long Challenge and Chef is only left with the last problem unsolved.
However, he is sure that he cannot solve the problem in the remaining time. From experience, he figures out that he needs exactly H hours to solve the problem.

Now Chef finally decides to use his special power which he has gained through years of intense yoga.
He can travel back in time when he concentrates. Specifically, his power allows him to travel to N different time zones, which are T1,T2,…,TN hours respectively behind his current time.

Find out whether Chef can use one of the available time zones to solve the problem and submit it before the contest ends.

Input

The first line of the input contains three space-separated integers N, H and x.
The second line contains N space-separated integers T1,T2,…,TN.

Output

Print a single line containing the string "YES" if Chef can solve the problem on time or "NO" if he cannot.

You may print each character of each string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤N≤100
1≤x<H≤100
1≤Ti≤100 for each valid i

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
solvable(int *a, size_t n, int h, int x)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (a[i] + x >= h)
			return true;
	}
	return false;
}

int
main(void)
{
	int a1[] = {1, 2};

	assert(solvable(a1, nelem(a1), 5, 3) == true);
	assert(solvable(a1, nelem(a1), 6, 3) == false);

	return 0;
}
