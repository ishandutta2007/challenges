/*

Turn each character in a string str into its ASCII character code and join them together to create a number.

For example, for string "abc", the number is 979899. We will call this number "num1".

"abc" ➞ "a" = 97, "b" = 98, "c" = 99 ➞ 979899

Then replace any incidence of the number 7 with the number 1, and call this number "num2":

num1 = 979899

num2 = 919899

Return the difference between the sum of the digits in num1 and num2:

  (9 + 7 + 9 + 8 + 9 + 9)
- (9 + 1 + 9 + 8 + 9 + 9)
-------------------------
         ➞  6

Examples

calc("ABCDabcd") ➞ 12

calc("cdefgh") ➞ 0

calc("ifkhchlhfde") ➞ 6)

Notes

Lowercase and uppercase characters have different ASCII character codes.

*/

#include <assert.h>
#include <stdio.h>

int
calc(const char *s)
{
	int u, v, x, y;
	size_t i;

	x = y = 0;
	for (i = 0; s[i]; i++) {
		for (v = s[i] & 0xff; v; v /= 10) {
			u = v % 10;
			x += u;
			y += (u != 7) ? u : 1;
		}
	}
	return x - y;
}

int
main(void)
{
	assert(calc("abc") == 6);
	assert(calc("ABCDabcd") == 12);
	assert(calc("cdefgh") == 0);
	assert(calc("ifkhchlhfde") == 6);
	assert(calc("aaaaaddddrijkl") == 36);
	assert(calc("abcdefghijklmnopqrstuvwxyz") == 18);
	assert(calc("AABBCC") == 12);
	assert(calc("ABCDEFGH") == 24);
	assert(calc("anmatmudtr") == 18);
	assert(calc("suwvete") == 6);
	assert(calc("edabit") == 6);
	assert(calc("EDABIT") == 6);
	assert(calc("SLOWLLLY") == 36);
	assert(calc("COMEnananan") == 42);
	assert(calc("coupdetat") == 12);
	assert(calc("arsenal") == 12);
	assert(calc("byoaaasglrrsA") == 18);
	assert(calc("byoglrrsA") == 0);
	assert(calc("eyyyhenDDDUEN") == 6);
	assert(calc("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 78);
	assert(calc("zyxwvutsrqpon") == 6);
	assert(calc("ZYXWVUTSR") == 6);

	return 0;
}
