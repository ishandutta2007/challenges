/*

Create a function that takes a number as an argument and returns true if the number is a valid credit card number, false otherwise.

Credit card numbers must be between 14-19 digits in length, and pass the Luhn test, described below:

    Remove the last digit (this is the "check digit").
    Reverse the number.
    Double the value of each digit in odd-numbered positions. If the doubled value has more than 1 digit, add the digits together (e.g. 8 x 2 = 16 ➞ 1 + 6 = 7).
    Add all digits.
    Subtract the last digit of the sum (from step 4) from 10. The result should be equal to the check digit from step 1.

Examples

validateCard(1234567890123456) ➞ false

// Step 1: check digit = 6, num = 123456789012345
// Step 2: num reversed = 543210987654321
// Step 3: digit array after selective doubling: [1, 4, 6, 2, 2, 0, 9, 8, 5, 6, 1, 4, 6, 2, 2]
// Step 4: sum = 58
// Step 5: 10 - 8 = 2 (not equal to 6) ➞ false

validateCard(1234567890123452) ➞ true

// Same as above, but check digit checks out.

*/

#include <assert.h>
#include <stdio.h>
#include <inttypes.h>

int
validcard(uintmax_t x)
{
	char b[80];
	int s, i, n;

	n = snprintf(b, sizeof(b), "%ju", x);
	if (!(14 <= n && n <= 19))
		return 0;

	for (i = 0; i < n; i++)
		b[i] -= '0';

	for (i = n & 1; i < n - 1; i += 2) {
		b[i] <<= 1;
		while (b[i] >= 10)
			b[i] = (b[i] / 10) + (b[i] % 10);
	}

	s = 0;
	for (i = 0; i < n - 1; i++)
		s += b[i];
	s = 10 - (s % 10);

	return s == b[n - 1];
}

int
main(void)
{
	assert(validcard(UINTMAX_C(1234567890123456)) == 0);
	assert(validcard(UINTMAX_C(1234567890123452)) == 1);
	assert(validcard(UINTMAX_C(79927398714)) == 0);
	assert(validcard(UINTMAX_C(79927398713)) == 0);
	assert(validcard(UINTMAX_C(709092739800713)) == 1);
	assert(validcard(UINTMAX_C(1234567890123456)) == 0);
	assert(validcard(UINTMAX_C(12345678901237)) == 1);
	assert(validcard(UINTMAX_C(5496683867445267)) == 1);
	assert(validcard(UINTMAX_C(4508793361140566)) == 0);
	assert(validcard(UINTMAX_C(376785877526048)) == 1);
	assert(validcard(UINTMAX_C(36717601781975)) == 0);

	return 0;
}
