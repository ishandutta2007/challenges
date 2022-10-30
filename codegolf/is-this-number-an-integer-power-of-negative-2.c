/*

There are clever ways of determining whether a number is a power of 2. That's no longer an interesting problem, so let's determine whether a given integer is an integer power of -2. For example:

-2 => yes: (-2)¹
-1 => no
0 => no
1 => yes: (-2)⁰
2 => no
3 => no
4 => yes: (-2)²

Rules

    You may write a program or a function and use any of the standard methods of receiving input and providing output.

    Your input is a single integer, and output must be a truthy value if the integer is an integer power of -2, and a falsy value otherwise. No other output (e.g. warning messages) is permitted.

    The usual integer overflow rules apply: your solution must be able to work for arbitrarily large integers in a hypothetical (or perhaps real) version of your language in which all integers are unbounded by default, but if your program fails in practice due to the implementation not supporting integers that large, that doesn't invalidate the solution.

    You may use any programming language, but note that these loopholes are forbidden by default.

Winning condition

This is a code-golf contest: the answer which has the fewest bytes (in your chosen encoding) is the winner.

*/

#include <stdio.h>

int
isnpow2(long n)
{
	if (n == 0)
		return 0;

	while (!(n & 1))
		n /= -2;
	return n == 1;
}

int
main(void)
{
	long i;

	for (i = -(1l << 20); i <= 1l << 20; i++) {
		if (isnpow2(i))
			printf("%ld\n", i);
	}
	return 0;
}
