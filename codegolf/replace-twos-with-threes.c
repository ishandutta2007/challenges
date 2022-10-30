/*

Given a positive integer n write some code to take its prime factorization and replace all of its factors of 2 with 3.

For example

12 = 2 * 2 * 3 -> 3 * 3 * 3 = 27

This is code-golf so the goal is to minimize the byte count of your answer.
Test cases

1 -> 1
2 -> 3
3 -> 3
4 -> 9
5 -> 5
6 -> 9
7 -> 7
8 -> 27
9 -> 9
10 -> 15
11 -> 11
12 -> 27
13 -> 13
14 -> 21
15 -> 15
16 -> 81
17 -> 17
18 -> 27
19 -> 19
20 -> 45
21 -> 21
22 -> 33
23 -> 23
24 -> 81
25 -> 25
26 -> 39
27 -> 27
28 -> 63
29 -> 29

*/

#include <assert.h>

unsigned
replace(unsigned n)
{
	while (!(n & 1))
		n = (n >> 1) * 3;
	return n;
}

int
main(void)
{
	assert(replace(1) == 1);
	assert(replace(2) == 3);
	assert(replace(3) == 3);
	assert(replace(4) == 9);
	assert(replace(5) == 5);
	assert(replace(6) == 9);
	assert(replace(7) == 7);
	assert(replace(8) == 27);
	assert(replace(9) == 9);
	assert(replace(10) == 15);
	assert(replace(11) == 11);
	assert(replace(12) == 27);
	assert(replace(13) == 13);
	assert(replace(14) == 21);
	assert(replace(15) == 15);
	assert(replace(16) == 81);
	assert(replace(17) == 17);
	assert(replace(18) == 27);
	assert(replace(19) == 19);
	assert(replace(20) == 45);
	assert(replace(21) == 21);
	assert(replace(22) == 33);
	assert(replace(23) == 23);
	assert(replace(24) == 81);
	assert(replace(25) == 25);
	assert(replace(26) == 39);
	assert(replace(27) == 27);
	assert(replace(28) == 63);
	assert(replace(29) == 29);

	return 0;
}
