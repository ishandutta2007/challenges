/*

Manipulating numbers is at the core of a programmer's job. To test how well you know their properties, you are asked to solve the following problem.

You are given n non-negative integers a1, a2, ..., an.
You want to know whether it's possible to construct a new integer using all the digits of these numbers such that it would be divisible by 3.
You can reorder the digits as you want. The resulting number can contain leading zeros.

For example, consider the numbers from which you have to construct a new integer as described above.
Numerous arrangements of digits are possible; but we have illustrated one below. 

Complete the function canConstruct which takes an integer array as input and return "Yes" or "No"
based on whether or not the required integer can be formed.

*/
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://en.wikipedia.org/wiki/Divisibility_rule#Divisibility_by_3_or_9
// a number is divisible by 3 if the sum of all the digits are divisble by 3
const char *
construct(int *a, size_t n)
{
	long s;
	size_t i;

	s = 0;
	for (i = 0; i < n; i++)
		s += a[i];
	return (s % 3 == 0) ? "Yes" : "No";
}

int
main(void)
{
	int a[] = {40, 50, 90};
	printf("%s\n", construct(a, nelem(a)));

	int b[] = {9};
	printf("%s\n", construct(b, nelem(b)));

	int c[] = {1, 4};
	printf("%s\n", construct(c, nelem(c)));

	int d[] = {3, 36};
	printf("%s\n", construct(d, nelem(d)));

	int e[] = {4, 9, 2};
	printf("%s\n", construct(e, nelem(e)));

	return 0;
}
