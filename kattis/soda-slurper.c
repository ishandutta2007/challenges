/*

Tim is an absolutely obsessive soda drinker, he simply cannot get enough.
Most annoyingly though, he almost never has any money, so his only obvious legal way to obtain more soda is to take the money he gets when he recycles empty soda bottles to buy new ones.
In addition to the empty bottles resulting from his own consumption he sometimes find empty bottles in the street. One day he was extra thirsty, so he actually drank sodas until he couldn’t afford a new one.

Input

Three non-negative integers e,f,c, where e<1000 equals the number of empty soda bottles in Tim’s possession at the start of the day, f<1000 the number of empty soda bottles found during the day, and 2≤c<2000

the number of empty bottles required to buy a new soda.
Output

How many sodas did Tim drink on his extra thirsty day?

*/

#include <assert.h>
#include <stdio.h>

int
sodas(int e, int f, int c)
{
	int x, y, r;

	r = 0;
	for (x = e + f; x >= c; x += y) {
		y = x % c;
		x /= c;
		r += x;
	}
	return r;
}

int
main(void)
{
	assert(sodas(9, 0, 3) == 4);
	assert(sodas(5, 5, 2) == 9);
	return 0;
}
