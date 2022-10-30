/*

A very basic challenge:

In this challenge, the

input is are : 3 numbers as arguments

output: the sum of the squares of the two larger numbers.

Your task is to write the indicated challenge.

*/

#include <assert.h>
#include <stdio.h>

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

int
sum2l(int a, int b, int c)
{
	if (a > c)
		swap(&a, &c);
	if (a > b)
		swap(&a, &b);
	return (b * b) + (c * c);
}

int
main(void)
{
	assert(sum2l(1, 2, 3) == 13);
	assert(sum2l(16, 10, 5) == 356);

	return 0;
}
