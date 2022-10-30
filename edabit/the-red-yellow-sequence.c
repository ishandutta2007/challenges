/*

Write a function that takes a number n and a string s as arguments and returns the nth term of the Red/Yellow sequence.
s will ask the function what to return, all, red or yellow.

https://edabit-challenges.s3.amazonaws.com/red_yellow_sequence.png

Examples

rySeq(2, "all") ➞ 5

rySeq(3, "yellow") ➞ 8

rySeq(28, "red") ➞ 55

rySeq(1, "blue") ➞ -1

Notes

    If s is not "all", "yellow" or "red", return -1.
    If n is 0, return 0.
    n is always a positive integer.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

long
ryseq(unsigned n, const char *s)
{
	long r, y;

	if (n == 0)
		return 0;

	r = 2 * n - 1;
	y = 2 * (n - 1) * (n - 1);
	if (!strcmp(s, "red"))
		return r;
	else if (!strcmp(s, "yellow"))
		return y;
	else if (!strcmp(s, "all"))
		return r + y;
	return -1;
}

int
main(void)
{
	assert(ryseq(2, "all") == 5);
	assert(ryseq(1, "yellow") == 0);
	assert(ryseq(1, "blue") == -1);
	assert(ryseq(28, "red") == 55);
	assert(ryseq(6, "all") == 61);
	assert(ryseq(0, "all") == 0);
	assert(ryseq(2, "all") == 5);
	assert(ryseq(22, "all") == 925);
	assert(ryseq(28, "yellow") == 1458);
	assert(ryseq(23, "red") == 45);
	assert(ryseq(150, "all") == 44701);
	assert(ryseq(30, "yellow") == 1682);
	assert(ryseq(1000, "red") == 1999);
	assert(ryseq(28, "green") == -1);

	return 0;
}
