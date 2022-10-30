/*

You are a poor person in ChocoLand. Here, people eat chocolates daily instead of normal food.
There is only one shop near your home; this shop is closed on Sunday, but open on all other days of the week.
You may buy at most one box of N chocolates from this shop on each day when it is open.

Currently, it's Monday, and you need to survive for the next S days (including the current day).
You have to eat K chocolates everyday (including the current day) to survive.
Do note that you are allowed to buy the a chocolate box and eat from it on the same day.

Compute the minimum number of days on which you need to buy from the shop so that you can survive the next S days, or determine that it isn't possible to survive.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains 3 integers N, K and S denoting the number of chocolates in a box, the number of chocolates you have to eat everyday to survive and the number of days you need to survive.

Output

For each test case, print a single line containing one integer — the minimum number of days on which you need to buy from the shop to survive, or -1 if you will not be able to survive S days.

Constraints
1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ K ≤ 100
1 ≤ S ≤ 1000

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
survive(int n, int k, int s)
{
	int b, w;

	w = s - (s / 7);
	b = ceil(s * k * 1.0 / n);
	if (n < k || b > w)
		return -1;
	if (s >= 7 && (n - k) * 6 < k)
		return -1;
	return b;
}

int
main(void)
{
	assert(survive(16, 2, 10) == 2);
	assert(survive(50, 48, 7) == -1);

	return 0;
}
