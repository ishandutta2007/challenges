/*

This is a reverse coding challenge.

Your task is to create a function that, when fed the inputs below, produce the sample outputs shown.
Examples

3 ➞ 21

9 ➞ 2221

17 ➞ 22221

24 ➞ 22228

Notes

If you get stuck, check the Comments for help.

*/

#include <assert.h>
#include <stdio.h>

unsigned
mystery(unsigned x)
{
	unsigned p, v;

	if (x <= 2)
		return x;

	v = 0;
	for (p = 1; (p << 1) < x; p <<= 1)
		v = (v * 10) + 2;
	return (v * 10) + x - p;
}

int
main(void)
{
	assert(mystery(3) == 21);
	assert(mystery(9) == 2221);
	assert(mystery(15) == 2227);
	assert(mystery(17) == 22221);
	assert(mystery(19) == 22223);
	assert(mystery(24) == 22228);
	assert(mystery(35) == 222223);
	assert(mystery(2) == 2);
	assert(mystery(8) == 224);
	assert(mystery(16) == 2228);

	return 0;
}
