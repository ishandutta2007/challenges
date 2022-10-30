/*

Due to budget cuts, even spies have to use commercial airlines nowadays to travel between cities in the world.
Although this mode of travel can be very convenient for a spy, it also raises a problem: the spy has to trust the pilot to make sure he is not in danger during the flight.
And even worse, sometimes there is no direct flight between some pairs of cities,
so that the spy has to take multiple flights to get to the desired location, and thus has to trust multiple pilots!

To limit the trust issues you are asked for help. Given the flight schedule,
figure out the smallest set of pilots that need to be trusted,
such that the spy can safely travel between all cities.

Input

On the first line one positive number: the number of test cases, at most 100. After that per test case:

    one line with two space-separated integers n (2≤n≤1000) and m (1≤m≤10000): the number of cities and the number of pilots, respectively.
    m lines with two space-separated integers a and b (1≤a,b≤n,a≠b): a pilot flying his plane back and forth between city a and b.

It is possible to go from any city to any other city using one or more flights. In other words: the graph is connected.

Output

Per test case:

    one line with one integer: the minimum number of pilots that need to be trusted such that it is possible to travel between each pair of cities.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
pilots(int c, int, int[][2], size_t)
{
	return c - 1;
}

int
main(void)
{
	int a1[][2] = {
	    {1, 2},
	    {2, 3},
	    {1, 3},
	};

	int a2[][2] = {
	    {2, 1},
	    {2, 3},
	    {4, 3},
	    {4, 5},
	};

	assert(pilots(3, 3, a1, nelem(a1)) == 2);
	assert(pilots(5, 4, a2, nelem(a2)) == 4);

	return 0;
}
