/*

This exercise is inspired by a Numberphile video (no need to watch past 2:00).
Description

A number of sailors (let's call it N) are stranded on an island with a huge pile of coconuts and a monkey. During the night, each sailor (in turn) does the following without the others knowing:

    He takes one N'th (e.g. if N=5, one fifth) of the coconuts in the pile and hides them

    The division leaves one coconut left over, which is given to the monkey.

In the morning, they split the remaining coconuts between them. This time the split is even. There's nothing left over for the monkey.

Your task: Given the number of sailors (N), how many coconuts were in the pile to begin with (lowest possible number)?
Formal inputs/outputs
Input

The input is a single number: N, the number of sailors. This number is a whole number that is greater than or equal to 2.
Output

The output is a single number: the number of coconuts in the original pile.
Sample input/output

Input:

5

Output:

3121

Sample solution for 5 sailors: https://jsfiddle.net/722gjnze/8/
Credit

This challenge was originally suggested on r/dailyprogrammer_ideas by /u/TinyLebowski (prior to some changes by me). Have a cool challenge idea? Hop on over to r/dailyprogrammer_ideas to tell everyone about it!

*/

#include <stdio.h>
#include <math.h>

typedef unsigned long long uvlong;

/*

@fibonacci_:

Every time a pile is hidden, there is (n - 1) / n of (the original pile - 1 to the monkey) left.
In 5 turns, there is the original pile * ((n - 1) / n)^n left if the monkey doesn't get one But the monkey does get 1 coconut every turn and you need to make sure the pile is fully divisible by n every turn.
For the first turn, for (n^n - X - 1) / ((n - 1) / n) to be fully divisible, X = n - 1. Therefore, n^n - (n - 1) = n^n - n + 1

*/

uvlong
coconuts(uvlong n)
{
	if (n == 2)
		return 11;
	if (n & 1)
		return pow(n, n) - n + 1;
	return (n - 1) * pow(n, n) - 1;
}

int
main(void)
{
	uvlong i;

	for (i = 0; i < 10; i++)
		printf("%llu %llu\n", i, coconuts(i));

	return 0;
}
