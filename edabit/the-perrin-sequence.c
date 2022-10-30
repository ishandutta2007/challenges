/*

Each number in the Perrin sequence is created by summing the numbers two positions and three positions before it.
The first three numbers are (3, 0, 2), and the sequence is extended as follows:

P(0) P(1) P(2) P(3) P(4) P(5) P(6) P(7) ... P(n)
3, 0, 2, 3, 2, 5, 5, 7, ...

Given a value for n, return the Perrin number P(n).
Examples

perrin(1) ➞ 0

perrin(8) ➞ 10

perrin(26) ➞ 1497

Notes

Check the Resources tab for a further explanation of the Perrin sequence.

*/

#include <assert.h>

unsigned
perrin(unsigned n)
{
	unsigned a, b, c, d, i;

	a = 3;
	b = 0;
	c = 2;
	d = 3;
	for (i = 0; i < n; i++) {
		a = b;
		b = c;
		c = d;
		d = a + b;
	}
	return a;
}

int
main(void)
{
	assert(perrin(0) == 3);
	assert(perrin(38) == 43721);
	assert(perrin(58) == 12110402);
	assert(perrin(52) == 2240877);
	assert(perrin(36) == 24914);
	assert(perrin(44) == 236282);
	assert(perrin(50) == 1276942);
	assert(perrin(42) == 134643);
	assert(perrin(27) == 1983);
	assert(perrin(17) == 119);
	assert(perrin(45) == 313007);
	assert(perrin(46) == 414646);
	assert(perrin(28) == 2627);
	assert(perrin(37) == 33004);
	assert(perrin(43) == 178364);
	assert(perrin(22) == 486);
	assert(perrin(25) == 1130);
	assert(perrin(51) == 1691588);
	assert(perrin(34) == 14197);
	assert(perrin(15) == 68);
	assert(perrin(41) == 101639);

	return 0;
}
