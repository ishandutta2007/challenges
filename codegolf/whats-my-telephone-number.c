/*

Introduction

The telephone numbers or involution numbers are a sequence of integers that count the ways n telephone lines can be connected to each other, where each line can be connected to at most one other line.
These were first studied by Heinrich August Rothe in 1800, when he gave a recurrence equation where they may be calculated. It is sequence A000085 in the OEIS.

Some help

    The first terms of the sequence are 1,1,2,4,10,26,76,232,764,2620,9496

It can be described by the recurrence relation T(n)=T(n−1)+(n−1)T(n−2)
(starting from n=0
)
It can be expressed exactly by the summation T(n)=∑k=0⌊n/2⌋(n2k)(2k−1)!!=∑k=0⌊n/2⌋n!2k(n−2k)!k!
(starting from n=0

    )
    There are other ways to get the telephone numbers which can be found on the Wikipedia and OEIS pages

Challenge

Write a program or function which returns the nth

telephone number.
I/O examples

(0 based indexing)
input --> output

0  -->            1
10 -->         9496
16 -->     46206736
22 --> 618884638912

Rules

    Input will be the index of the sequence
    The index origin can be anything
    As the numbers can get very large, you only need to support numbers as large as your language can handle
    Standard I/O rules apply
    No standard loopholes
    This is code-golf so shortest code in bytes wins


*/

#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
T(uvlong n)
{
	if (n < 2)
		return 1;
	return T(n - 1) + (n - 1) * T(n - 2);
}

int
main(void)
{
	uvlong i;

	for (i = 0; i <= 32; i++)
		printf("%llu %llu\n", i, T(i));

	return 0;
}
