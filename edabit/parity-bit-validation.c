/*

Parity bits are used as very simple checksum to ensure that binary data isn't corrupted during transit. Here's how they work:

    If a binary string has an odd number of 1's, the parity bit is a 1.
    If a binary string has an even number of 1's, the parity bit is a 0.
    The parity bit is appended to the end of the binary string.

Create a function that validates whether a binary string is valid, using parity bits.
Worked Example

validateBinary("10110010") ➞ true

// The last digit is the parity bit.
// 0 is the last digit.
// 0 means that there should be an even number of 1's.
// There are four 1's.
// Return true.

Examples

validateBinary("00101101") ➞ true

validateBinary("11000000") ➞ true

validateBinary("11000001") ➞ false

Notes

    All inputs will be a byte long (8 characters).
    You can find another parity bit involved challenge via this link.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
validate(const char *s)
{
	size_t i;
	int b;

	b = 0;
	for (i = 0; s[i]; i++)
		b ^= (s[i] == '1') ? 1 : 0;
	return b == 0;
}

int
main(void)
{
	static const char *stab[] = {
	    "00101101",
	    "11000000",
	    "11000001",
	    "10010010",
	    "10101101",
	    "11000100",
	    "11000101",
	    "10010110",
	    "10101101",
	    "11001000",
	    "11001001",
	    "10011010",
	};
	static const bool btab[] = {
	    true,
	    true,
	    false,
	    false,
	    false,
	    false,
	    true,
	    true,
	    false,
	    false,
	    true,
	    true,
	};

	size_t i;

	for (i = 0; i < nelem(stab); i++)
		assert(validate(stab[i]) == btab[i]);

	return 0;
}
