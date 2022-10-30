/*

Jem is famous for his laziness at school. He always leaves things to last minute.
Now Jem has N problems in the assignment of "Advanced topics in algorithm" class to solved.
The assignment is due tomorrow and as you may guess he hasn't touch any of the problems.
Fortunately he got a plan as always.

The first step will be buying a pack of Red Bull and then to work as hard as he can.
Here is how he is going to spend the remaining time:

Jem will not take a break until he finishes at least half of the remaining problems.
Formally, if N is even then he will take he first break after finishing N / 2 problems.
If N is odd then the break will be after he done (N + 1) / 2 problems.
Each of his break will last for B minutes.
Initially, he takes M minutes in solving a problem, after each break he will take twice more time in solving a problem, i.e. 2 * M minutes per problem after the first break.

Jem will start working soon and ask you to help him calculate how much time it will take until he finish the last problem!

Input

The first line contains a single integer T represents the number of test cases in the input.

Each line in the next T line contains three integers N, B and M represents a test case.

Output

For each test case output a single line containing an integer represent how much time Jem will need (in minutes).

Constraints
1 ≤ T ≤ 100
1 ≤ N, B, M ≤ 10^8

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

vlong
seq(vlong n, vlong b, vlong m)
{
	if (n < 1)
		return 0;
	if (n == 1)
		return m;
	if (!(n & 1))
		return (n / 2) * m + b + seq(n / 2, b, 2 * m);
	return ((n + 1) / 2) * m + b + seq(n - ((n + 1) / 2), b, 2 * m);
}

int
main(void)
{
	assert(seq(9, 1, 2) == 45);
	assert(seq(123456LL, 123456LL, 123456LL) == 131351258112LL);

	return 0;
}
