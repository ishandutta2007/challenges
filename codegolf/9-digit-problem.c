/*

Write a program to find a number consisting of 9 digits in which each of the digits from 1 to 9 appears only once. This number must also satisfy these divisibility requirements:

The number should be divisible by 9.
If the rightmost digit is removed, the remaining number should be divisible by 8.
If the rightmost digit of the new number is removed, the remaining number should be divisible by 7.
And so on, until there’s only one digit (which will necessarily be divisible by 1).
Credit Dávid Németh

*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long long uvlong;

bool
uniq(uvlong n)
{
	uvlong i, d[10];

	memset(d, 0, sizeof(d));
	for (; n; n /= 10)
		d[n % 10]++;

	for (i = 1; i < 10; i++) {
		if (d[i] != 1)
			return false;
	}
	return d[0] == 0;
}

bool
div(uvlong n)
{
	uvlong i;

	for (i = 9; i >= 1; i--) {
		if (n % i != 0)
			return false;
		n /= 10;
	}
	return true;
}

uvlong
number(void)
{
	uvlong i;

	for (i = 100000000ULL; i <= 999999999ULL; i++) {
		if (uniq(i) && div(i))
			return i;
	}
	return 0;
}

int
main(void)
{
	printf("%llu\n", number());
	return 0;
}
