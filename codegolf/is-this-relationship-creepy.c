/*

According to this XKCD comic, there is a formula to determine whether or not the age gap in a relationship is "creepy". This formula is defined as:

(Age/2) + 7
being the minimum age of people you can date.

Therefore a relationship is creepy if either of the people in said relationship are younger than the minimum age of the other.

Given the age of two people, can you output whether or not that relationship is creepy?

Rules
Your program should take two integers as input, the age of both people in the relationship. These can be taken in any reasonable format.

Your program must then output a truthy or falsy value describiing whether or not the relationship is "creepy" (Truthy = Creepy).

Standard loopholes are not allowed.
This puzzle is Code Golf, so the answer with the shortest source code in bytes wins
Test Cases
40, 40    - Not Creepy
18, 21    - Not Creepy
80, 32    - Creepy
15, 50    - Creepy
47, 10000 - Creepy
37, 38    - Not Creepy
22, 18    - Not Creepy

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

bool
creepy(int a, int b)
{
	return ((max(a, b) * 0.5) + 7) > min(a, b);
}

int
main(void)
{
	assert(creepy(40, 40) == false);
	assert(creepy(18, 21) == false);
	assert(creepy(80, 32) == true);
	assert(creepy(15, 50) == true);
	assert(creepy(47, 10000) == true);
	assert(creepy(37, 38) == false);
	assert(creepy(22, 18) == false);
	assert(creepy(18, 22) == false);
	assert(creepy(30, 22) == false);
	assert(creepy(30, 44) == false);
	assert(creepy(30, 46) == false);
	assert(creepy(30, 47) == true);

	return 0;
}
