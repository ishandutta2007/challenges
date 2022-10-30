/*

In this thread we use 32-bit signed integers (assuming the usual two's complement).
For simplicity I shall call this type Int32. The range is from -2147483648 through 2147483647.
Any two values can be successfully multiplied (the result is an Int32 as well) since we use multiplication without overflow checking (we only keep the 32 least significant bits of the product).

For example, we have:

2147483647 * 2 == -2

and so on.

If your language does not have native support for 32-bit signed integers (with two's complement), you must emulate it.

Your task is to solve the equation:

a * x == b

where a and b are given as input, and it is assumed that a is an odd number (i.e. least significant bit is 1). You output an Int32 value.

    The input to your program shall be two Int32 values a and b, and a will be odd
    The output must be one Int32 value such that (if we call the output x) a*x == b
    You do not have to handle invalid input; in particular, if the argument a is an even number, it does not matter what your code does
    Code golf

Test cases:

Input                  Output

1,42                   42
3,126                  42
5,5                    1

-3,126                 -42
3,-126                 -42
-3,-126                42

2147483647,-2          2
2147483647,2           -2
2147483647,666         -666

3,0                    0
3,1                    -1431655765
3,2                    1431655766

-387907419,1342899768  1641848792
348444091,1076207126   -1334551070
10,14                  irrelevant (illegal input)

In the last case [a,b]==[10,14], even if there is a solution x = -1717986917 (not unique, x = 429496731 also works), you do not have to handle that case (10 is not odd).

*/

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>

int32_t
solve(int32_t a, int32_t b)
{
	int64_t p, x;
	int32_t r;

	p = a;
	for (x = INT32_MIN; x <= INT32_MAX; x++) {
		r = p * x;
		if (r == b)
			return x;
	}
	return 0;
}

void
test(int32_t a, int32_t b, int32_t r)
{
	int32_t x;

	x = solve(a, b);
	printf("%" PRId32 "\n", x);
	assert(x == r);
}

int
main(void)
{
	test(1, 42, 42);
	test(3, 126, 42);
	test(5, 5, 1);
	test(-3, 126, -42);
	test(3, -126, -42);
	test(-3, -126, 42);
	test(INT32_C(2147483647), -2, 2);
	test(INT32_C(2147483647), 2, -2);
	test(INT32_C(2147483647), 666, -666);
	test(3, 0, 0);
	test(3, 1, INT32_C(-1431655765));
	test(3, 2, INT32_C(1431655766));
	test(INT32_C(-387907419), INT32_C(1342899768), INT32_C(1641848792));
	test(INT32_C(348444091), INT32_C(1076207126), INT32_C(-1334551070));
	test(10, 14, INT32_C(-1717986917));

	return 0;
}
