/*

21, 21, 23, 20, 5, 25, 31, 24, ?

Inspired by this Puzzle, given an integer n>0, print out the following sequence until you reach a non-Integer (spoilered, in case you want to solve the puzzle yourself first)

a0=n
a4k+1=a4k⋅(4k+1)
a4k+2=a4k+1+(4k+2)
a4k+3=a4k+2−(4k+3)
a4k+4=a4k+3/(4k+4)


    or more intuitively: *1, +2, -3, /4, *5, +6, -7, /8, ...

TestCases:

    1: 1, 1, 3, 0, 0, 0, 6, -1
    2: 2, 2, 4, 1
    3: 3, 3, 5, 2
    4: 4, 4, 6, 3
    5: 5, 5, 7, 4, 1, 5, 11, 4
    6: 6, 6, 8, 5
    9: 9, 9, 11, 8, 2, 10, 16, 9
    21: 21, 21, 23, 20, 5, 25, 31, 24, 3, 27, 37, 26

Input and Output may be taken in any reasonable format, standard loopholes are as forbidden as usual.

In the spirit of code-golf, the shortest answer in byte wins!

Sandbox: https://codegolf.meta.stackexchange.com/a/18142/59642

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

void
seq(long x, size_t n, long *r)
{
	size_t i;

	r[0] = x;
	for (i = 0; i < n; i += 4) {
		r[i + 1] = r[i] * (i + 1);
		r[i + 2] = r[i + 1] + (i + 2);
		r[i + 3] = r[i + 2] - (i + 3);
		r[i + 4] = r[i + 3] / (i + 4);
	}
}

void
test(long x, long n, long *r)
{
	long p[128];

	seq(x, n, p);
	assert(!memcmp(p, r, sizeof(*r) * n));
}

int
main(void)
{
	test(1, 8, (long[]){1, 1, 3, 0, 0, 0, 6, -1});
	test(2, 4, (long[]){2, 2, 4, 1});
	test(3, 4, (long[]){3, 3, 5, 2});
	test(4, 4, (long[]){4, 4, 6, 3});
	test(5, 8, (long[]){5, 5, 7, 4, 1, 5, 11, 4});
	test(6, 4, (long[]){6, 6, 8, 5});
	test(9, 8, (long[]){9, 9, 11, 8, 2, 10, 16, 9});
	test(21, 12, (long[]){21, 21, 23, 20, 5, 25, 31, 24, 3, 27, 37, 26});

	return 0;
}
