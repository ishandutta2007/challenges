/*

Johnny Applesack has grown his seeds into trees and harvested all the apples.
He has a huge pile of N apples next to him, a sack that can hold K apples at a time, and an infinitely long, straight road in front of him.
At each kilometer mark of the road there is a toll booth.
If he passes the toll booth in the direction that brings him further away from where he started, he has to pay one apple.
Otherwise he will not be allowed to pass. If he passes the other way, he does not have to pay.
Johnny is allowed to leave piles of apples wherever he wants and pick them up later.
Help Johnny figure out how many kilometers he can travel.

Input

The input consists of a single line with two space-separated integers N and K.

Output

Output the number of kilometers he can travel down the road.

Limits

        0≤N≤1000000
        1≤K≤1000000

Example explanation

One way of solving the first example input would be to pick up 4 apples, go to right before the 3 kilometer mark,
dump the remaining two apples (having paid one at each of the toll booths at kilometer mark 1 and 2).
Then go back to the pile and pick up the rest of the apples, and do the same again.
This leaves him at 3 kilometers with 4 apples. He can then go an additional 4 kilometers, paying at the 3, 4, 5, and 6 kilometer marks.
He will be stopped at the 7 kilometer mark because he has no apples left.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
kilometers(int n, int k)
{
	int r;

	for (r = 1; n > k; r++)
		n -= ceil(n * 1.0 / k);
	return r + n;
}

int
main(void)
{
	assert(kilometers(8, 4) == 7);

	return 0;
}
