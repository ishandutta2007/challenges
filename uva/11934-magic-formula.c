/*

You are given a quadratic function, f(x) = ax^2 + bx + c
You are also given a divisor d and a limit L.
How many of the function values f(0), f(1), . . . , f(L) are divisible by d?

Input

Input consists of a number of test cases. Each test
case consists of a single line containing the numbers
a b c d L (−1000 ≤ a, b, c ≤ 1000, 1 < d < 1000000, 0 ≤ L < 1000).
Input is terminated by a line containing ‘0 0 0 0 0’ which should not be processed.

Output

Print the answer for each test case (the number of function values f(0), f(1), . . . , f(L) divisible by d)
on a separate line.

Sample Input

0 0 10 5 100
0 0 10 6 100
1 2 3 4 5
1 2 3 3 5
0 0 0 0 0

Sample Output

101
0
0
4

*/

#include <assert.h>

int
values(int a, int b, int c, int d, int l)
{
	int i, r, v;

	r = 0;
	for (i = 0; i <= l; i++) {
		v = (a * i * i) + (b * i) + c;
		if (v % d == 0)
			r++;
	}
	return r;
}

int
main(void)
{
	assert(values(0, 0, 10, 5, 100) == 101);
	assert(values(0, 0, 10, 6, 100) == 0);
	assert(values(1, 2, 3, 4, 5) == 0);
	assert(values(1, 2, 3, 3, 5) == 4);

	return 0;
}
