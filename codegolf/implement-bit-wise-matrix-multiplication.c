/*

The MMIX architecture is a fairly simple big-endian RISC design. It has a couple of interesting features, one of them is the MXOR instruction, which is what you should implement.

The MXOR instruction interprets its arguments (two 64-bit registers) as two 8×8 matrices of bits and performs a matrix multiplication where exclusive-or is used for addition and logical and is used for multiplication.

An argument in binary representation where the leftmost digit is most significant

    a0 a1 a2 … a63

is interpreted as a matrix like this:

    a0 a1 … a7
    a8 a9 … a15
    …
    a56 a57 … a63

Your task is to write a function, subroutine or similar in a language of choice which can be evoked from a single-letter name (i.e. f(x,y)) that implements this function.
The two arguments of the function shall be of equal implementation-defined unsigned 64 bit integer type, the function shall return a value of the same type.

The winner of this competition is the shortest submission (measured in bytes or characters if the language you use uses a meaningful character encoding).
You are encouraged to post a readable commented version of your code in addition to the golfed solution so other's can understand how it works.

*/

#include <assert.h>
#include <stdint.h>
#include <stdio.h>

/*

@Peter Taylor

It's pure bit-bashing.

If we consider a as a series of matrix elements we get

a_00 a_01 a_02 a_03 a_04 a_05 a_06 a_07 a_10 a_11 ...

Similarly b. Now, c_ij = a_i0 & b_0j ^ a_i1 & b1j ^ ... ^ a_i7 & b7j. So by grouping over the common index we get

c =   (a_00 a_00 ... a_00 a_00 a_10 a_10 ...) & (b_00 b_01 b_02 ... b_07 b_00 b_01 ...)
    ^ (a_01 a_01 ... a_01 a_01 a_11 a_11 ...) & (b_10 b_11 b_12 ... b_17 b_10 b_11 ...)
    ^ ...
  =   (((a >> 7) & 0x0101010101010101) * 0xff) & (((b >> 56) & 0xff) * 0x0101010101010101)
    ^ (((a >> 6) & 0x0101010101010101) * 0xff) & (((b >> 48) & 0xff) * 0x0101010101010101)
    ^ ...

*/

uint64_t
mxor(uint64_t a, uint64_t b)
{
	return ((((a >> 7) & UINT64_C(0x0101010101010101)) * 0xff) & (((b >> 56) & 0xff) * UINT64_C(0x0101010101010101))) ^
	       ((((a >> 6) & UINT64_C(0x0101010101010101)) * 0xff) & (((b >> 48) & 0xff) * UINT64_C(0x0101010101010101))) ^
	       ((((a >> 5) & UINT64_C(0x0101010101010101)) * 0xff) & (((b >> 40) & 0xff) * UINT64_C(0x0101010101010101))) ^
	       ((((a >> 4) & UINT64_C(0x0101010101010101)) * 0xff) & (((b >> 32) & 0xff) * UINT64_C(0x0101010101010101))) ^
	       ((((a >> 3) & UINT64_C(0x0101010101010101)) * 0xff) & (((b >> 24) & 0xff) * UINT64_C(0x0101010101010101))) ^
	       ((((a >> 2) & UINT64_C(0x0101010101010101)) * 0xff) & (((b >> 16) & 0xff) * UINT64_C(0x0101010101010101))) ^
	       ((((a >> 1) & UINT64_C(0x0101010101010101)) * 0xff) & (((b >> 8) & 0xff) * UINT64_C(0x0101010101010101))) ^
	       ((((a >> 0) & UINT64_C(0x0101010101010101)) * 0xff) & (((b >> 0) & 0xff) * UINT64_C(0x0101010101010101)));
}

uint64_t
bmat(uint8_t m[8][8])
{
	uint64_t b, v;
	int i, j;

	v = 0;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (m[i][j]) {
				b = 63 - (8 * i + j);
				v |= UINT64_C(1) << b;
			}
		}
	}
	return v;
}

uint64_t
beye(void)
{
	uint8_t m[8][8] = {
	    {1, 0, 0, 0, 0, 0, 0, 0},
	    {0, 1, 0, 0, 0, 0, 0, 0},
	    {0, 0, 1, 0, 0, 0, 0, 0},
	    {0, 0, 0, 1, 0, 0, 0, 0},
	    {0, 0, 0, 0, 1, 0, 0, 0},
	    {0, 0, 0, 0, 0, 1, 0, 0},
	    {0, 0, 0, 0, 0, 0, 1, 0},
	    {0, 0, 0, 0, 0, 0, 0, 1},
	};
	return bmat(m);
}

int
main(void)
{
	uint64_t i;

	assert(mxor(UINT64_C(12345678), UINT64_C(87654321)) == UINT64_C(3977539));
	assert(mxor(beye(), beye()) == beye());

	for (i = 0; i < UINT64_C(1000000); i++) {
		assert(mxor(i, beye()) == i);
		assert(mxor(beye(), i) == i);

		assert(mxor(i, 0) == 0);
		assert(mxor(0, i) == 0);
	}

	return 0;
}
