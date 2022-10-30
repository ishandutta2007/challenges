/*

Chef's son Chefu found some matches in the kitchen and he immediately starting playing with them.

The first thing Chefu wanted to do was to calculate the result of his homework — the sum of A and B, and write it using matches. Help Chefu and tell him the number of matches needed to write the result.

Digits are formed using matches in the following way:

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers A and B.

Output

For each test case, print a single line containing one integer — the number of matches needed to write the result (A+B).

Constraints
1≤T≤1,000
1≤A,B≤10^6

*/

#include <assert.h>

int
matches(int a, int b)
{
	static const int tab[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

	int r, v;

	r = 0;
	for (v = a + b; v > 0; v /= 10)
		r += tab[v % 10];
	return r;
}

int
main(void)
{
	assert(matches(123, 234) == 13);
	assert(matches(10101, 1010) == 10);
	assert(matches(4, 4) == 7);

	return 0;
}
