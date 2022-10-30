/*

    This challenge was inspired by a programming blog I frequent. Please see the original post here: A Programming Puzzle

Challenge

Define a function f:Q→Q
such that f(f(n))=−n for all non-zero integers n, and where Q

is the set of rational numbers.
Details

In whatever language you prefer, please define one function or program f
that accepts as parameter one number n and returns or outputs one number f(n).

Input may be provided through whichever mechanism is most natural for your language: function argument, read from STDIN, command-line argument, stack position, voice input, gang signs, etc.

Output should be a return value from a function/program or printed to STDOUT.

I would like to restrict answers to functions that do not take advantage of program state or global memory/data that is visible from outside of the function f.
For example, keeping a counter outside of f that counts how many times f was called and just doing a negation based on this count isn't very challenging or interesting for anyone.
The decisions f makes should rely only on data within f's lexical scope.

However, this restriction is probably inappropriate for some stack-oriented languages or other types of languages that do not distinguish these types of data or scopes.
Please use your best judgement to keep with the spirit of this challenge.
Scoring

Standard code golf rules apply - your score is the number of bytes in your source code.

The minimal answer requires the domain and codomain of f to be a subset of the rationals Q.
If you restrict your domain and codomain of f to the integers Z, then your score is the ceiling of 90% of the number of bytes in your source code.

Tiebreak

In the event of a tie, the following will be used in order:

    Fewest number of printable non-whitespace symbols in your source code
    Earliest date and time of answer submission

You are not required to support arbitrarily sized numbers. Please interpret the sets Z
and Q

as datatypes in your chosen language (typically integer and floating point, respectively).

If your solution relies entirely on the underlying structure or bit pattern of a data type, please describe its limitations and how it is being used.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
sign(int x)
{
	if (x < 0)
		return -1;
	if (x == 0)
		return 0;
	return 1;
}

// https://stackoverflow.com/questions/731832/designing-function-ffn-n
int
f(int x)
{
	return sign(x) - pow(-1, x) * x;
}

int
main(void)
{
	assert(f(f(0)) == 0);
	assert(f(f(1)) == -1);
	assert(f(f(2)) == -2);
	assert(f(f(3)) == -3);
	assert(f(f(4)) == -4);
	assert(f(f(5)) == -5);
	assert(f(f(-1)) == 1);
	assert(f(f(-2)) == 2);
	assert(f(f(-3)) == 3);
	assert(f(f(-4)) == 4);
	assert(f(f(-5)) == 5);

	return 0;
}
