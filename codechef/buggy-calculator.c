/*

Trans bought a calculator at creatnx's store. Unfortunately, it is fake.
It has many bugs. One of them is adding two numbers without carrying.
Example expression: 12 + 9 will have result 11 in his calculator. Given an expression in the form a + b, please output result from that calculator.

*/
#include <stdio.h>

unsigned
bugadd(unsigned int a, unsigned int b)
{
	unsigned r, p;

	p = 1;
	r = 0;
	while (a != 0 || b != 0) {
		r += ((a % 10 + b % 10) % 10) * p;
		a /= 10;
		b /= 10;
		p *= 10;
	}
	return r;
}

int
main(void)
{
	printf("%u\n", bugadd(12, 9));
	printf("%u\n", bugadd(25, 25));
	printf("%u\n", bugadd(5, 5));
	printf("%u\n", bugadd(2, 34));
	printf("%u\n", bugadd(1, 1599));
	printf("%u\n", bugadd(0, 6));
	printf("%u\n", bugadd(0, 0));
	return 0;
}
