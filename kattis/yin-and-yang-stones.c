/*

A mysterious circular arrangement of black stones and white stones has appeared. Ming has been tasked with balancing the stones so that only one black and one white stone remain.

Ming has two operations for balancing the stones:

    Take some consecutive sequence of stones where there is exactly one more black stone than a white stone and replace the stones with a single black stone

    Take some consecutive sequence of stones where there is exactly one more white stone than black stone and replace the stones with a single white stone

Given a circular arrangement, determine if it is possible for Ming to balance the stones.

Input

Each input will consist of a single test case. Note that your program may be run multiple times on different inputs.
The input will consist of a single string s (1≤|s|≤105), with only the characters capital ‘B’ and ‘W’.
The stones are arranged in a circle, so the first stone and the last stone are adjacent.

Output

Output 1 if it is possible for Ming to balance the stones with his rules. Otherwise, output 0.

*/

#include <assert.h>
#include <stdio.h>

int
balanced(const char *s)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++)
		j += s[i] == 'W';
	return (i - j) == j;
}

int
main(void)
{
	assert(balanced("WWBWBB") == 1);
	assert(balanced("WWWWBBW") == 0);
	assert(balanced("WBBBBBWWBW") == 0);
	assert(balanced("WBWBWBWBWBWBWB") == 1);

	return 0;
}
