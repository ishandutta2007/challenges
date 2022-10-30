/*

Your task is to find the sum of all integer numbers lying between 1 and N inclusive.

Input

The input consists of a single integer N that is not greater than 10000 by it's absolute value.

Output

Write a single integer number that is the sum of all integer numbers lying between 1 and N inclusive.

*/

#include <assert.h>

int
triangular(int n)
{
	return n * (n + 1) / 2;
}

int
sum(int n)
{
	if (n > 0)
		return triangular(n);
	return -triangular(-n) + 1;
}

int
main(void)
{
	assert(sum(-3) == -5);
	assert(sum(-10) == -54);
	assert(sum(0) == 1);
	assert(sum(10) == 55);

	return 0;
}
