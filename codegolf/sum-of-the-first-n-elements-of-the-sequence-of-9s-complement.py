#!/usr/bin/env python

"""

Let's consider the following sequence:

9,8,7,6,5,4,3,2,1,0,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71...
This is the sequence of 9's complement of a number: that is, a(x)=10^d−1−x where d is the number of digits in x. (A061601 in the OEIS).
Your task is to add the first n elements.

Input

A number n∈[0,10000].

Output

The sum of the first n elements of the sequence.

Test cases
0 -> 0
1 -> 9
10 -> 45
100 -> 4050
1000 -> 408600
10000 -> 40904100

"""

def comp9(x):
    return 10**len(str(x)) - 1 - x

def seq(x):
    r = 0
    for i in range(0, x):
        r += comp9(i)
    return r

def main():
    assert(seq(0) == 0)
    assert(seq(1) == 9)
    assert(seq(10) == 45)
    assert(seq(100) == 4050)
    assert(seq(1000) == 408600)
    assert(seq(10000) == 40904100)

main()
