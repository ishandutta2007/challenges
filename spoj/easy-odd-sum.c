/*

Hablu likes odd numbers a lot. So he wants the sum of all odd numbers in range [a, b]. That is, find the sum of all odd numbers i such that (a ≤ i ≤ b). Seems easy right? Because it is.

Input
The first and only line will contain 2 integers a, b where (0 ≤ a ≤ 10^8) and (0 ≤ b ≤ 10^8).

Output
In one line, output the value of the sum

*/

#include <assert.h>

int
odds(int a, int b)
{
	int p, q;

	p = (a / 2) + (a % 2);
	q = (b / 2) + (b % 2);
	return (q * q) - (p * p);
}

int
main(void)
{
	assert(odds(0, 9) == 25);

	return 0;
}
