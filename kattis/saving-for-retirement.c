/*

Alice is saving for her retirement. She hasn’t really decided how much she wants to save, but when she retires, she wants to have strictly more money than Bob will have when he retires.

Bob is B years old. He plans to retire when he becomes Br years old. He saves Bs every year from now until then.

Alice is A years old. She wants to save As every year. When is the earliest time she can retire?

Input

The input is a single line consisting of 5
space separated integers; B, Br, Bs, A, As.

Output

Output the age at which Alice can retire so that she has more money than Bob will have at age Br.

Limits

    20≤B≤Br≤100
    20≤A≤100
    1≤As,Bs≤100

Explanation of first example

At the age of 25 Bob has saved 5 every year for 5 years. This means he has 25 saved up.
At the age of 23 Alice has saved 10 every year for 3 years. This means she has 30 saved up, which is strictly more than 25.

*/

#include <assert.h>
#include <math.h>

unsigned
retirement(unsigned B, unsigned Br, unsigned Bs, unsigned A, unsigned As)
{
	unsigned Ar, X, Y;

	X = (Br - B) * Bs;
	Ar = ceil(X * 1.0 / As + A);
	Y = (Ar - A) * As;
	Ar += (Y == X);
	return Ar;
}

int
main(void)
{
	assert(retirement(20, 25, 5, 20, 10) == 23);
	assert(retirement(20, 28, 5, 30, 9) == 35);
	return 0;
}
