/*

The harmonic series is the "infinite sum" of all the fractions of the form 1/n for n positive integer. I.e. the harmonic series is

1/1+1/2+1/3+1/4+⋯

It is well-known that this sum diverges, which means that if you define

Hn=1/1+1/2+⋯+1/n

Then the value of Hn goes to infinity. This can also be stated in a different way: for any positive value x you pick,
there is some value N such that, to the right of N, the H values are bigger than x:

∀ x ∃ N:n>N⟹Hn>x

Your task

Write a program/function that takes as input a positive number x (not necessarily an integer) and outputs the first integer n for which

Hn≥x

In theory your program must work for arbitrary x, even if in practice you are limited by the memory and/or precision of your programming language/computer.
Test cases

1.5 -> 2
2 -> 4
3 -> 11
3.1415 -> 13
4 -> 31
5 -> 83
7.5 -> 1015
10 -> 12367

This is code-golf so shortest solution wins! Standard loopholes are forbidden by default. Happy golfing.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef unsigned long long uvlong;

// https://en.wikipedia.org/wiki/Harmonic_series_(mathematics)
// H(k) = sum[1, k] 1/n ~ ln(k) + γ
uvlong
diverge(double x)
{
	uvlong i;
	double r;

	r = 0.0;
	for (i = 1;; i++) {
		r += 1.0 / i;
		if (r >= x)
			break;
	}
	return i;
}

int
main(void)
{
	assert(diverge(1.5) == 2);
	assert(diverge(2) == 4);
	assert(diverge(3) == 11);
	assert(diverge(3.1415) == 13);
	assert(diverge(4) == 31);
	assert(diverge(5) == 83);
	assert(diverge(7.5) == 1015);
	assert(diverge(10) == 12367);

	return 0;
}
