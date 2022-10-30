/*

Create a function that determines whether a number is Oddish or Evenish.
A number is Oddish if the sum of all of its digits is odd, and a number is Evenish if the sum of all of its digits is even.
If a number is Oddish, return "Oddish". Otherwise, return "Evenish".

For example, oddishOrEvenish(121) should return "Evenish", since 1 + 2 + 1 = 4. oddishOrEvenish(41) should return "Oddish", since 4 + 1 = 5.

Examples

oddishOrEvenish(43) ➞ "Oddish"
// 4 + 3 = 7
// 7 % 2 = 1

oddishOrEvenish(373) ➞ "Oddish"
// 3 + 7 + 3 = 13
// 13 % 2 = 1

oddishOrEvenish(4433) ➞ "Evenish"
// 4 + 4 + 3 + 3 = 14
// 14 % 2 = 0

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
oddeven(unsigned long n)
{
	unsigned long v;

	for (v = 0; n; n /= 10)
		v += n % 10;
	return (v & 1) ? "Oddish" : "Evenish";
}

void
test(unsigned long n, const char *r)
{
	assert(!strcmp(oddeven(n), r));
}

int
main(void)
{
	test(43, "Oddish");
	test(373, "Oddish");
	test(55551ul, "Oddish");
	test(694, "Oddish");
	test(4433, "Evenish");
	test(11, "Evenish");
	test(211112ul, "Evenish");

	return 0;
}
