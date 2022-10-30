/*

there is only one rule: get accept for this problem http://acm.ut.ac.ir/sc/problemset/view/1032!

to submit your code, you need to create an account(if you don't want to do so, just post your code here and I'll submit it). so far shortest code is written with C and has 85 character length.

winner will be the shortest C/C++ code submitted before 2012/02/01

note: to check shortest codes submitted you can click on "accepted runs" and then "code length"

as elssar suggested I've copied the question here :

How far can you make a stack of cards overhang a table? If you have one card, you can create a maximum overhang of half a card length. (We're assuming that the cards must be perpendicular to the table.)
With two cards you can make the top card overhang the bottom one by half a card length, and the bottom one overhang the table by a third of a card length, for a total maximum overhang of 1/2 + 1/3 = 5/6 card lengths.
In general you can make n cards overhang by 1/2 + 1/3 + 1/4 + ... + 1/(n + 1) card lengths, where the top card overhangs the second by 1/2, the second overhangs tha third by 1/3, the third overhangs the fourth by 1/4, etc.,
and the bottom card overhangs the table by 1/(n + 1). This is illustrated in the figure below.

figure http://acm.ut.ac.ir/sc/assets/problem_images/1032_50ac13c53158fd843d1884e8afa962dd.jpg

Input

The input consists of one or more test cases, followed by a line containing the number 0.00 that signals the end of the input.
Each test case is a single line containing a positive floating-point number c whose value is at least 0.01 and at most 5.20; c will contain exactly three digits.

Output

For each test case, output the minimum number of cards necessary to achieve an overhang of at least c card lengths. Use the exact output format shown in the examples.

Sample Input
1.00
3.71
0.04
5.19
0.00

Sample Output
3 card(s)
61 card(s)
1 card(s)
273 card(s)

*/

#include <assert.h>
#include <stdio.h>

int
cards(double a)
{
	int n;

	for (n = 2; a >= 0; n++)
		a -= 1.0 / n;
	return n - 2;
}

int
main(void)
{
	assert(cards(1.00) == 3);
	assert(cards(3.71) == 61);
	assert(cards(0.04) == 1);
	assert(cards(5.19) == 273);

	return 0;
}
