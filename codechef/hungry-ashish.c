/*

It's dinner time. Ashish is very hungry and wants to eat something. He has X rupees in his pocket.
Since Ashish is very picky, he only likes to eat either PIZZA or BURGER.
In addition, he prefers eating PIZZA over eating BURGER.
The cost of a PIZZA is Y rupees while the cost of a BURGER is Z rupees.

Ashish can eat at most one thing. Find out what will Ashish eat for his dinner.

Input Format

The first line will contain T - the number of test cases. Then the test cases follow.
The first and only line of each test case contains three integers X, Y and Z - the money Ashish has, the cost of a PIZZA and the cost of a BURGER.

Output Format

For each test case, output what Ashish will eat. (PIZZA, BURGER or NOTHING).

You may print each character of the string in uppercase or lowercase. (for example, the strings Pizza, pIzZa and piZZa will all be treated as identical).

Constraints
1≤T≤100
1≤X,Y,Z≤100

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
food(int x, int y, int z)
{
	if (x >= y)
		return "PIZZA";
	if (x >= z)
		return "BURGER";
	return "NOTHING";
}

void
test(int x, int y, int z, const char *r)
{
	const char *p;

	p = food(x, y, z);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test(50, 40, 60, "PIZZA");
	test(40, 55, 39, "BURGER");
	test(30, 42, 37, "NOTHING");

	return 0;
}
