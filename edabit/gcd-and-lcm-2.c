/*

Create a function that takes two numbers as arguments and return the LCM of the two numbers.

Notes

    Don't forget to return the result.
    You may want to use the GCD function to make this a little easier.
    LCM stands for least common multiple, the smallest multiple of both integers.

*/

#include <stdio.h>
#include <stdlib.h>

int
gcd(int a, int b)
{
	int t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int
lcm(int a, int b)
{
	return abs(a * b) / gcd(a, b);
}

int
main(void)
{
	printf("%d\n", lcm(6, 10));
	printf("%d\n", lcm(30, 60));
	printf("%d\n", lcm(10000, 333));
	printf("%d\n", lcm(75, 135));
	printf("%d\n", lcm(102, 2));
	return 0;
}
