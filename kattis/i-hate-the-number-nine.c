/*

How many positive d digit numbers exist that do not contain a nine?

Input

The first line of the input consists of a single integer, T, the number of test cases.
Each of the following T cases consists of a single integer d, the number of digits.

    1≤T≤20
    1≤d≤10^18

Output

For each test case, output the number of positive numbers with d digits that do not contain a nine.
Since this number can be very large, output it modulo 1000000007.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef unsigned long long uvlong;

// https://oeis.org/A055275
uvlong
neins(uvlong n)
{
	static const uvlong m = 1000000007ull;
	uvlong i, p;

	if (n == 0)
		return 1;

	p = 8;
	for (i = 1; i < n; i++)
		p = ((p % m) * 9) % m;
	return p;
}

int
main(void)
{
	assert(neins(1) == 8);
	assert(neins(2) == 72);
	assert(neins(100) == 343393926ull);

	return 0;
}
