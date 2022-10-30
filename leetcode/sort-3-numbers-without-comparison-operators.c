/*

Had this problem for an interview. The goal is to sort an array of 3 integers, without any comparison operators. This includes ==, <=, >=, etc, if else statements (they implicitly use comparison operators),
and built-in functions that use comparison operators, such as min() and max(). Bit operators do not count as comparison operators (since they avoid branching, which is one of the premise for this problem).

Example:

Input = [1, 3, 2]
Output = [1, 2, 3]

Input = [-2147483646, 2147483647, 0]
Output = [-2147483646, 0, 2147483647]

To be clear, all comparison operators cannot appear anywhere in the code.

Edit:
I guess I wasn't too clear about the premise, but the goal of the interviewer is to get me to write a "branchless" solution. By branchless I mean the code I write will not cause branching in CPU. This means no if else, no loops, no comparisons.

I'll post my solution later (interviewer was happy with my solution, but didn't have much time to discuss it because out of time). Hopefully someone comes up with a better solution, I thought this problem was very interesting.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long vlong;

// https://realtimecollisiondetection.net/blog/?p=49
vlong
min(vlong a, vlong b)
{
	return (a + b - llabs(a - b)) / 2;
}

vlong
max(vlong a, vlong b)
{
	return (a + b + llabs(a - b)) / 2;
}

void
sort3(long a[3])
{
	long x, y, z;

	x = min(a[0], min(a[1], a[2]));
	z = max(a[0], max(a[1], a[2]));
	y = (a[0] + a[1] + a[2]) - (x + z);

	a[0] = x;
	a[1] = y;
	a[2] = z;
}

void
test(long a[3])
{
	sort3(a);
	printf("%ld %ld %ld\n", a[0], a[1], a[2]);
	assert(a[0] <= a[1] && a[1] <= a[2]);
}

int
main(void)
{
	long a1[] = {1, 3, 2};
	long a2[] = {-2147483646L, 2147483647L, 0};
	long a3[] = {50, 34, 22};
	long a4[] = {-2, 4, 5};
	long a5[] = {4, 10, 2};
	long a6[] = {1, 1, 1};
	long a7[] = {800, 498, 100};

	test(a1);
	test(a2);
	test(a3);
	test(a4);
	test(a5);
	test(a6);
	test(a7);

	return 0;
}
