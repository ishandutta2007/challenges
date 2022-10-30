/*

Given a number, return an array containing the two halves of the number. If the number is odd, make the rightmost number higher.

Examples

numberSplit(4) ➞ [2, 2]

numberSplit(10) ➞ [5, 5]

numberSplit(11) ➞ [5, 6]

numberSplit(-9) ➞ [-5, -4]

Notes

    All numbers will be integers.
    You can expect negative numbers too.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
numbersplit(int n, int r[2])
{
	r[0] = r[1] = n / 2;
	if (n & 1) {
		r[0] -= (n < 0);
		r[1] = r[0] + 1;
	}
}

void
test(int n, int r[2])
{
	int p[2];

	numbersplit(n, p);
	printf("[%d %d]\n", p[0], p[1]);
	assert(!memcmp(r, p, sizeof(p)));
}

int
main(void)
{
	test(4, (int[]){2, 2});
	test(10, (int[]){5, 5});
	test(11, (int[]){5, 6});
	test(0, (int[]){0, 0});
	test(1, (int[]){0, 1});
	test(-4, (int[]){-2, -2});
	test(-5, (int[]){-3, -2});
	test(-9, (int[]){-5, -4});

	return 0;
}
