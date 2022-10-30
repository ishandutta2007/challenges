/*

Princess Perly has been kidnapped by the magical Hydra! The kingdom is in chaos. Now only PyPy — the bravest Knight of the country — can save the day!

Hydra is a powerful magical creature with H heads and T tails. Hydra can breathe fire from each of its heads, and can shoot poison from each of its tails.
The only way to kill Hydra is to cut off all H heads and all T tails. Please note that a Hydra with 0 heads and T>0 tails is still alive — in which case it is called a ‘Headless Hydra’.

Knight PyPy is indeed brave, but the Knight is still a novice when it comes to fighting magical creatures. Knight PyPy only know 4 moves:

    With the first move, Knight PyPy can cut off exactly one of Hydra’s heads.

    With the second move, Knight PyPy can cut off exactly one of Hydra’s tails.

    With the third move, Knight PyPy can cut off exactly two of Hydra’s heads.

    With the fourth move, Knight PyPy can cut off exactly two of Hydra’s tails.

Please remember that even though Hydra is a magical creature, the number of its heads and tails can never be negative.
Thus PyPy cannot use a move when there are not enough heads or tails; e.g. PyPy cannot use the first move on a Headless Hydra.

However, Hydra is not so easy to kill. Immediately after PyPy’s move,

    If PyPy cuts off exactly one head, a new head grows immediately.

    If PyPy cuts off exactly one tail, two new tails grow immediately.

    If PyPy cuts off exactly two tails, a new head grows immediately.

    If PyPy cuts off exactly two heads, nothing happens.

Note that if after PyPy’s move Hydra has 0 heads and 0 tails, new heads and tails can still grow, in which case the Hydra is still alive.

Knight PyPy wants to kill Hydra as soon as possible, so that he can save Princess Perly. What is the minimum number of moves that PyPy needs to use to kill Hydra?

Input

Input contains at most 50 test cases. Each test case contains exactly one line with 2 space-separated integers H and T (1≤H,T≤100).

The input is terminated by a single line containing two zeros.

Output

For each test case, print exactly one line containing a single integer S:

    If it is impossible to kill Hydra, S=−1, Otherwise, S is the minimum number of moves to kill Hydra.

Explanation of example

In this test case, Hydra has 3 heads and 3 tails initially. Following is a possible strategy for PyPy, with 9 moves:

        Use the fourth move. Hydra now has 4 heads and 1 tail.

        Use the third move. Hydra now has 2 heads and 1 tail.

        Use the third move. Hydra now has 0 heads and 1 tail.

        Use the second move. Hydra now has 0 heads and 2 tails.

        Use the second move. Hydra now has 0 heads and 3 tails.

        Use the second move. Hydra now has 0 heads and 4 tails.

        Use the fourth move. Hydra now has 1 head and 2 tails.

        Use the fourth move. Hydra now has 2 heads and 0 tails.

        Use the third move. Hydra now has 0 heads and 0 tails.

        Because PyPy cuts of exactly 2 heads, no new head nor tail grow, and Hydra is dead.

Thus PyPy can kill Hydra with 9 moves. This is also the minimum number of moves for this test case.

*/

#include <assert.h>
#include <stdio.h>

int
moves(int h, int t)
{
	int a, b, c;

	a = ((h % 2) * 2 + (t % 4) * 3) % 4;
	b = (t + ((h % 2) * 2 + (t % 4) * 3) % 4) / 2;
	c = (h + (t + ((h % 2) * 2 + (t % 4) * 3) % 4) / 2) / 2;
	return a + b + c;
}

int
main(void)
{
	assert(moves(3, 3) == 9);
	assert(moves(1, 1) == 3);
	return 0;
}
