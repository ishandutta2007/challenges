/*

Most problems on CodeChef highlight chef's love for food and cooking but little is known about his love for racing sports.
He is an avid Formula 1 fan. He went to watch this year's Indian Grand Prix at New Delhi. He noticed that one segment of the circuit was a long straight road.
It was impossible for a car to overtake other cars on this segment. Therefore, a car had to lower down its speed if there was a slower car in front of it.
While watching the race, Chef started to wonder how many cars were moving at their maximum speed.

Formally, you're given the maximum speed of N cars in the order they entered the long straight segment of the circuit.
Each car prefers to move at its maximum speed. If that's not possible because of the front car being slow, it might have to lower its speed.
It still moves at the fastest possible speed while avoiding any collisions. For the purpose of this problem, you can assume that the straight segment is infinitely long.

Count the number of cars which were moving at their maximum speed on the straight segment.

Input

The first line of the input contains a single integer T denoting the number of test cases to follow.
Description of each test case contains 2 lines. The first of these lines contain a single integer N, the number of cars.
The second line contains N space separated integers, denoting the maximum speed of the cars in the order they entered the long straight segment.

Output

For each test case, output a single line containing the number of cars which were moving at their maximum speed on the segment.

Constraints
1 ≤ T ≤ 100
1 ≤ N ≤ 10,000
All speeds are distinct positive integers that fit in a 32 bit signed integer.
Each input file will not be larger than 4 MB (4,000,000,000 bytes) in size.

WARNING! The input files are very large. Use faster I/O.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

size_t
cars(int *a, size_t n)
{
	size_t c, i;
	int m;

	c = 1;
	if (n == 0)
		return c;

	m = a[0];
	for (i = 1; i < n; i++) {
		c += (a[i] <= m);
		m = min(m, a[i]);
	}
	return c;
}

int
main(void)
{
	int a1[] = {10};
	int a2[] = {8, 3, 6};
	int a3[] = {4, 5, 1, 2, 3};

	assert(cars(a1, nelem(a1)) == 1);
	assert(cars(a2, nelem(a2)) == 2);
	assert(cars(a3, nelem(a3)) == 2);

	return 0;
}
