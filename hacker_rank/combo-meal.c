/*

A fast-food chain menu is selling a burger, a can of soda, and a
combo meal containing a burger and a can of soda, at prices known to you.

They have chosen the selling price for each item by first
determining the total cost of making the individual items
and then adding a fixed value to it, representing their profit.
Assume that the cost of making a regular burger is fixed and the cost of making a regular soda is fixed.

For example, if the cost of making a regular burger is 206, 
the cost of making a regular soda is 145 and the fixed profit is 69,
then the fast-food chain will set selling prices as:

B     P
206 + 69 = 275

S
145 + 69 = 214

B+S
351 + 69 = 420

Given the price of a burger, a can of soda and a combo meal on the menu, your task is to compute the fixed profit.

Complete the function named profit which takes in three integers denoting selling price of a burger,
a can of soda and a combo meal respectively, and returns an integer denoting the fixed profit.

*/
#include <stdio.h>

int
profit(int b, int s, int c)
{
	// B + x = b
	// S + x = s
	// B + S + x = c
	// x = c - B - S
	// x = c - (b-x) - (s-x)
	// x = -c + b + s
	return -c + b + s;
}

int
main(void)
{
	printf("%d\n", profit(275, 214, 420));
	printf("%d\n", profit(6, 9, 11));
	printf("%d\n", profit(199, 199, 255));
	return 0;
}
