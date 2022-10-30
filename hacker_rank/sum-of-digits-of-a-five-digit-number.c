// In this challenge, you have to input a five digit number and print the sum of digits of the number.

#include <stdio.h>

unsigned
sum(unsigned v)
{
	int s;

	s = 0;
	while (v != 0) {
		s += (v % 10);
		v /= 10;
	}
	return s;
}

int
main(void)
{
	printf("%u\n", sum(10564));
	return 0;
}
