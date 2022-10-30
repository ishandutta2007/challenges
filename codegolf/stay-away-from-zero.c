/*

Task

Given a non-negative integer n, output 1 if n is 0, and output the value of n otherwise.
Input

A non-negative integer.

    If you would like to accept the string as input, the string would match the following regex: /^(0|[1-9][0-9]*)$/, i.e. it must not have any leading zeroes, except when it is 0.
    If you accept a real integer as input, you may assume that the integer is within the handling capability of the language.

Output

A positive integer, specified above. Leading zeroes are not allowed. Your output should match the regex /^[1-9][0-9]*$/.
Testcases

input output
    0      1
    1      1
    2      2
    3      3
    4      4
    5      5
    6      6
    7      7

Scoring

This is code-golf, so shortest answer in bytes wins.

Standard loopholes apply.

*/

#include <assert.h>

int
output(int n)
{
	return (n == 0) ? 1 : n;
}

int
main(void)
{
	assert(output(0) == 1);
	assert(output(1) == 1);
	assert(output(2) == 2);
	assert(output(3) == 3);
	assert(output(4) == 4);
	assert(output(5) == 5);
	assert(output(6) == 6);
	assert(output(7) == 7);

	return 0;
}
