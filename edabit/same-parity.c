/*

Create a function that takes a number as input and returns true if the sum of its digits has the same parity as the entire number. Otherwise, return false.

Notes

    Parity is whether a number is even or odd. If the sum of the digits is even and the number itself is even, return true. The same goes if the number is odd and so is the sum of its digits.
    Single digits will obviously have the same parities (see example #3).

*/

#include <stdio.h>

int
sameparity(unsigned n)
{
	unsigned p, v;

	p = 0;
	for (v = n; v; v /= 10)
		p += v % 10;
	return (n & 1) == (p & 1);
}

int
main(void)
{
	printf("%d\n", sameparity(243));
	printf("%d\n", sameparity(12));
	printf("%d\n", sameparity(3));
	printf("%d\n", sameparity(5));
	printf("%d\n", sameparity(4));
	printf("%d\n", sameparity(3453));
	printf("%d\n", sameparity(0));
	printf("%d\n", sameparity(123456789));
	printf("%d\n", sameparity(987654321));
	printf("%d\n", sameparity(13));
	printf("%d\n", sameparity(37));
	printf("%d\n", sameparity(182));
	printf("%d\n", sameparity(133331));
	return 0;
}
