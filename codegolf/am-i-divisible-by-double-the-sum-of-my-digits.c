/*

Given a positive integer as input, your task is to output a truthy value if the number is divisible by the double of the sum of its digits, and a falsy value otherwise (OEIS A134516). In other words:

(sum_of_digits)*2 | number
Instead of truthy / falsy values for the true and false cases, you may instead specify any finite set of values for the true/false case, and their complement the other values.
For a simple example, you may use 0 for the true case and all other numbers for the false case (or vice versa, if you like).

Standard input and output rules apply. Default Loopholes also apply.

You can take input as an integer or as the string representation of that integer.

This is code-golf, hence the shortest code in bytes wins!

I am new to PPCG, so I would like you to post an explanation if it's possible.

Test Cases
Input - Output - (Reason)

80  - Truthy - (16 divides 80)
100 - Truthy - (2 divides 100)
60  - Truthy - (12 divides 60)
18 - Truthy - (18 divides 18)
12 - Truthy - (6 divides 12)

4 - Falsy - (8 does not divide 4)
8 - Falsy - (16 does not divide 8)
16  - Falsy  - (14 does not divide 16)
21 - Falsy - (6 does not divide 21)
78  - Falsy  - (30 does not divide 78)
110 - Falsy - (4 does not dide 110)
111 - Falsy - (6 does not divide 111)
390 - Falsy  - (24 does not divide 390)

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
digitsum(uvlong n)
{
	uvlong r;

	for (r = 0; n; n /= 10)
		r += n % 10;
	return r;
}

bool
divisible(uvlong n)
{
	uvlong m;

	m = digitsum(n) * 2;
	return (m) ? (n % m) == 0 : false;
}

int
main(void)
{
	assert(divisible(80) == true);
	assert(divisible(100) == true);
	assert(divisible(60) == true);
	assert(divisible(18) == true);
	assert(divisible(12) == true);

	assert(divisible(4) == false);
	assert(divisible(8) == false);
	assert(divisible(16) == false);
	assert(divisible(21) == false);
	assert(divisible(78) == false);
	assert(divisible(110) == false);
	assert(divisible(111) == false);
	assert(divisible(390) == false);

	return 0;
}
