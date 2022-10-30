/*

Background

When I was in elementary school, we used to play a game in math class that goes as follows.

All kids sit in a big circle and take turns counting, starting from 1.

However, the following numbers must be skipped while counting:

    Numbers that are multiples of 3.
    Numbers that have a 3 in its decimal representation.

The first 15 numbers the kids should say are

1 2 4 5 7 8 10 11 14 16 17 19 20 22 25

Whenever somebody gets a number wrong – says a number that isn't in the sequence or skips a number that is – he's removed from the circle. This goes on until there's only one kid left.
Task

You're bad at this game, so you decide to cheat. Write a program or a function that, given a number of the sequence, calculates the next number of the sequence.

You don't have to handle numbers that cannot be represented using your language's native numeric type, provided that your program works correctly up to input 251 and that your algorithm works for arbitrarily large inputs.

Input and output can use any convenient base.

Since you have to conceal your code, it must be as short as possible. In fact, this is code-golf, so the shortest code in bytes wins.
Test cases

  1 ->   2
  2 ->   4
 11 ->  14
 22 ->  25
 29 ->  40
251 -> 254

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

int
threes(int n)
{
	while (n) {
		if ((n % 10) == 3)
			return 1;
		n /= 10;
	}
	return 0;
}

int
next(int n)
{
	for (;;) {
		if (n == INT_MAX)
			return -1;

		n++;
		if ((n % 3) != 0 && !threes(n))
			break;
	}
	return n;
}

int
main(void)
{
	assert(next(1) == 2);
	assert(next(2) == 4);
	assert(next(11) == 14);
	assert(next(22) == 25);
	assert(next(29) == 40);
	assert(next(251) == 254);

	return 0;
}
