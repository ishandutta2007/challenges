/*

Write a function that takes an array of 10 integers (between 0 and 9) and returns a string in form of a phone number.
Examples

createPhoneNumber([1, 2, 3, 4, 5, 6, 7, 8, 9, 0]) ➞ "(123) 456-7890"

createPhoneNumber([1, 1, 1, 1, 1, 1, 1, 1, 1, 1]) ➞ "(111) 111-1111"

createPhoneNumber([8, 7, 4, 1, 2, 5, 6, 5, 8, 2]) ➞ "(874) 125-6582"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
phonenum(unsigned p[10], char *b, size_t n)
{
	snprintf(b, n, "(%u%u%u) %u%u%u-%u%u%u%u",
	         p[0], p[1], p[2], p[3], p[4],
	         p[5], p[6], p[7], p[8], p[9]);
	return b;
}

int
main(void)
{
	unsigned p1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	unsigned p2[] = { 1, 4, 7, 6, 1, 2, 5, 7, 9, 5 };
	unsigned p3[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	unsigned p4[] = { 8, 7, 4, 1, 2, 5, 6, 5, 8, 2 };

	char b[80];

	assert(!strcmp(phonenum(p1, b, sizeof(b)), "(123) 456-7890"));
	assert(!strcmp(phonenum(p2, b, sizeof(b)), "(147) 612-5795"));
	assert(!strcmp(phonenum(p3, b, sizeof(b)), "(111) 111-1111"));
	assert(!strcmp(phonenum(p4, b, sizeof(b)), "(874) 125-6582"));

	return 0;
}
