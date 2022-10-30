/*

Briefing

The difficulty of a Code Golf question can be calculated as such:

clamp(⌈(va÷700)×10⌉,0,10)

Where v

is the number of views a question has

and a

is the number of answers a question has

and ⌈x⌉

is the ceiling operator.

Also:

clamp(x,min,max)=⎧⎩⎨minxmaxx<minmin≤x≤maxmax<x

This question's current difficulty: ***
Task

Write a program that will take two integers (v and a) and output the difficulty in asterisks (*).

The input can be in the form of an array, a separated string or as separate function arguments
Test Data

Views   Answers Difficulty  Program Output
163     2       2           **
548     22      1           *
1452    24      1           *
1713    37      1           *
4162    32      2           **
3067    15      3           ***
22421   19      10          **********

Example with pseudocode

v: 1713    
a: 37
out = clamp(ceil(((v/a)/700)*10), 0, 10); // evaluates to 1
//program will output '*'

The shortest code in bytes wins! Trailing/ leading spaces are allowed.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
clamp(int x, int a, int b)
{
	if (x < a)
		x = a;
	if (x > b)
		x = b;
	return x;
}

int
difficulty(int v, int a)
{
	if (a == 0)
		return 0;
	return clamp(ceil(((v * 1.0 / a) / 700) * 10), 0, 10);
}

void
stars(int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("*");
	printf("\n");
}

void
test(int v, int a, int r)
{
	int p;

	p = difficulty(v, a);
	stars(p);
	assert(p == r);
}

int
main(void)
{
	test(163, 2, 2);
	test(548, 22, 1);
	test(1452, 24, 1);
	test(1713, 37, 1);
	test(4162, 32, 2);
	test(3067, 15, 3);
	test(22421, 19, 10);

	return 0;
}
