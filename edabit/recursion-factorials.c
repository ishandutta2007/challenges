/*

Write a function that calculates the factorial of a number recursively.
Examples

factorial(5) ➞ 120

factorial(3) ➞ 6

factorial(1) ➞ 1

factorial(0) ➞ 1

*/

#include <assert.h>

int
fact(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return n * fact(n - 1);
}

int
main(void)
{
	assert(fact(5) == 120);
	assert(fact(3) == 6);
	assert(fact(1) == 1);
	assert(fact(0) == 0);

	return 0;
}
