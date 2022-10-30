/*

Given list of integers {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4}. For those who interested these numbers are used in weekday calculation.

Weekday = (m[n] + d + y + y>>2 + y/400 - y/100) % 7;, where m[n] - expression I'm searching, d - day of month, y - year - (month <= 2).

Construct expression consisting of arithmetic, logic and bitwise operators, which will output for positive integer n integer m so that m % 7 equals n-th number in the list.

Branches, ternary operators, table lookups and pointers are not allowed.

Score:
1 - for | & ^ ~ >> << operators
1.1 - for + - < > <= >= == != ! && || operators
1.2 - for * operator
1.4 - for / % operators

Answer with lowest score wins.

Personally I have found:

    (41*n)>>4+((n+61)>>4)<<2 with score 6.4. I thought this will be hard to find so provided own expression to start with.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
f(unsigned n)
{
	static const int tab[] = {
	    0,
	    3,
	    2,
	    5,
	    0,
	    3,
	    5,
	    1,
	    4,
	    6,
	    2,
	    4,
	};
	return tab[n % nelem(tab)];
}

int
main(void)
{
	int i;

	for (i = 0; i < 100; i++)
		printf("%d\n", f(i));

	return 0;
}
