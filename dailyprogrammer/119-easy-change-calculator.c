/*

Write A function that takes an amount of money, rounds it to the nearest penny and then tells you the minimum number of coins needed to equal that amount of money. For Example: "4.17" would print out:

Quarters: 16
Dimes: 1
Nickels: 1
Pennies: 2

Author: nanermaner
Formal Inputs & Outputs
Input Description

Your Function should accept a decimal number (which may or may not have an actual decimal, in which you can assume it is an integer representing dollars, not cents). Your function should round this number to the nearest hundredth.
Output Description

Print the minimum number of coins needed. The four coins used should be 25 cent, 10 cent, 5 cent and 1 cent. It should be in the following format:

Quarters: <integer>
Dimes: <integer>
Nickels: <integer>
Pennies: <integer>

Sample Inputs & Outputs
Sample Input

1.23
Sample Output

Quarters: 4
Dimes: 2
Nickels: 0
Pennies: 3

Challenge Input

10.24
0.99
5
00.06

Challenge Input Solution

Not yet posted
Note

This program may be different for international users, my examples used quarters, nickels, dimes and pennies. Feel free to use generic terms like "10 cent coins" or any other unit of currency you are more familiar with.

    Bonus: Only print coins that are used at least once in the solution.

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
change(const char *s)
{
	static const struct {
		char name[32];
		long value;
	} tab[] = {
	    {"Quarters", 25},
	    {"Dimes", 10},
	    {"Nickels", 5},
	    {"Pennies", 1},
	};

	size_t i;
	long n, v;

	n = atof(s) * 100;
	printf("%s\n", s);
	for (i = 0; i < nelem(tab); i++) {
		v = n / tab[i].value;
		n = n % tab[i].value;
		printf("%s: %ld\n", tab[i].name, v);
	}
	printf("\n");
}

int
main(void)
{
	change("4.17");
	change("1.23");
	change("10.24");
	change("0.99");
	change("5");
	change("00.06");

	return 0;
}
