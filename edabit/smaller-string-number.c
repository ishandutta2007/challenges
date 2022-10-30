/*

Number

Create a function that returns the smaller number.
Examples

smallerNum("21", "44") ➞ "21"

smallerNum("1500", "1") ➞ "1"

smallerNum("5", "5") ➞ "5"

Notes

    Numbers will be represented as strings, and your output should also be a string.
    If both numbers tie, return either number.
    Numbers will be positive.
    Bonus: See if you can do this without converting to integers.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *
smallernum(const char *a, const char *b)
{
	return (atoi(a) <= atoi(b)) ? a : b;
}

void
test(const char *a, const char *b, const char *r)
{
	assert(!strcmp(smallernum(a, b), r));
}

int
main(void)
{
	test("21", "44", "21");
	test("1500", "1", "1");
	test("5", "5", "5");
	test("153", "367", "153");
	test("1500", "16", "16");
	test("100", "23", "23");
	test("1500", "1", "1");
	test("5", "5", "5");

	return 0;
}
