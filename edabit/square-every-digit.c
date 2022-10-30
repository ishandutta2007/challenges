/*

Create a function that squares every digit of a number.
Examples

squareDigits(9119) ➞ 811181

squareDigits(2483) ➞ 416649

squareDigits(3212) ➞ 9414

Notes

The function receives an integer and must return an integer.

*/

#include <assert.h>

unsigned
squaredigits(unsigned x)
{
	unsigned p[sizeof(x) * 8], v;
	int i, n;

	for (n = 0; x; n++) {
		p[n] = x % 10;
		p[n] *= p[n];
		x /= 10;
	}

	v = 0;
	for (i = n - 1; i >= 0; i--) {
		v += p[i];
		if (i > 0)
			v *= (p[i - 1] >= 10) ? 100 : 10;
	}

	return v;
}

int
main(void)
{
	assert(squaredigits(9119) == 811181);
	assert(squaredigits(2483) == 416649);
	assert(squaredigits(3212) == 9414);
	assert(squaredigits(8726) == 6449436);
	assert(squaredigits(9763) == 8149369);
	assert(squaredigits(2230) == 4490);
	assert(squaredigits(2797) == 4498149);
	assert(squaredigits(233) == 499);
	assert(squaredigits(7437) == 4916949);
	assert(squaredigits(2483) == 416649);
	assert(squaredigits(5742) == 2549164);
	assert(squaredigits(5636) == 2536936);
	assert(squaredigits(841) == 64161);

	return 0;
}
