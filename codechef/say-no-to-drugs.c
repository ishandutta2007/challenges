/*

There are N people participating in a race. The Nth participant is your friend, so you want him to win.
You are not a man of ethics, so you decided to inject some units of a Performance Enhancement Drug (don't ask where that came from) in your friend's body.

From the charts, you came to know the speed of every player. Formally, for a player i, his speed is denoted by Si.
The change in speed with one unit of the drug is K units. Note that K can be negative, which means the drug has more side effects than benefits.
Of course, there will be a drug test before the race, so your friend will be caught if the number of units of the drug in his blood is greater than or equal to L.
You need to determine whether you can help your friend to win the race (with or without drugs), without getting caught.

Note: A player wins the race if he has the maximum speed among all the participants. If there are more than one people with a maximal speed, they tie at first place, and no one wins!

Input Format

First line will contain a single integer T, the number of test cases. Description of the test cases follows.
First line of each test case will contain three space-separated integers, N - the number of participants, K - the change in speed with one unit of the drug, and L - minimum units of the drug that can be detected in the drug test.
Second line of each test case will contain N space-separated integers Si, the speeds of the participants.

Output Format

For each test case print "Yes" if you can help your friend to win the race, otherwise "No" in a single line.

Constraints
1≤T≤200
1≤N,L≤1000
−1000≤K≤1000
1≤Si≤1000

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

bool
win(int *a, size_t n, int k, int l)
{
	size_t i;
	int m;

	if (n == 0)
		return true;

	m = INT_MIN;
	for (i = 0; i < n - 1; i++)
		m = max(m, a[i]);

	if (k < 0)
		return a[n - 1] > m;
	return a[n - 1] + (l - 1) * k > m;
}

int
main(void)
{
	int a1[] = {2, 1, 3, 2};
	int a2[] = {2, 1, 4, 2};
	int a3[] = {12, 11, 9};

	assert(win(a1, nelem(a1), 2, 2) == true);
	assert(win(a2, nelem(a2), 2, 2) == false);
	assert(win(a3, nelem(a3), -10, 100) == false);

	return 0;
}
