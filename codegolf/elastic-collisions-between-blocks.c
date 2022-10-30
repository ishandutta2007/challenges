/*

The 3Blue1Brown Youtube channel released a video a year ago called "Why do colliding blocks compute pi?" which describes a model where a block A of mass a slides into a block B of mass b, which then pushes block B into a wall,
causing it to bounce off the wall and then collide again with block A.

The miracle of this process is that if a/b=10^2(n−2) the number of total collisions (both between A and B and between B with the wall) is given by the first n digits of π.
Example output

+-------+---+--------+
| a     | b | output |
+-------+---+--------+
| 1     | 1 | 3      |
| 2     | 1 | 5      |
| 3     | 1 | 5      |
| 4     | 1 | 6      |
| 5     | 1 | 7      |
| 10    | 3 | 6      |
| 7     | 2 | 6      |
| 9     | 2 | 7      |
| 1     | 2 | 3      |
| 1     | 5 | 2      |
| 100   | 1 | 31     |
| 10000 | 1 | 314    |
+-------+---+--------+

(These values were calculated using this web applet from Reddit user KyleCow1. Please let me know if I've made any mistakes.)
Challenge

Your challenge is to take two positive integers a,b∈N>0, and output the number of collisions in this scenario. Your program should be able to handle all a,b≤10000.
This is a code-golf challenge, so the shortest program wins.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
elastic(int a, int b)
{
	if (a <= 0 || b <= 0)
		return 0;
	return ceil(M_PI / atan(sqrt(b * 1.0 / a)) - 1);
}

int
main(void)
{
	static const int tab[][3] = {
	    {1, 1, 3},
	    {2, 1, 5},
	    {3, 1, 5},
	    {4, 1, 6},
	    {5, 1, 7},
	    {10, 3, 6},
	    {7, 2, 6},
	    {9, 2, 7},
	    {1, 2, 3},
	    {1, 5, 2},
	    {100, 1, 31},
	    {10000, 1, 314},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(elastic(tab[i][0], tab[i][1]) == tab[i][2]);

	return 0;
}
