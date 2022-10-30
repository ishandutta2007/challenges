#!/usr/bin/env python

"""

A divisor of a number n is any number that evenly divides n, including 1 and n itself. The number of divisors d(n) is how many divisors a number has. Here's d(n) for the first couple n:

n    divisors    d(n)
1    1           1
2    1, 2        2
3    1, 3        2
4    1, 2, 4     3
5    1, 5        2
6    1, 2, 3, 6  4
We can repeatedly subtract the number of divisors from a number. For example:

16                  = 16
16 - d(16) = 16 - 5 = 11
11 - d(11) = 11 - 2 = 9
 9 - d( 9) =  9 - 3 = 6
 6 - d( 6) =  6 - 4 = 2
 2 - d( 2) =  2 - 2 = 0
In this case it took 5 steps to get to 0.

Write a program or function that given a nonnegative number n returns the number of steps it takes to reduce it to 0 by repeated subtraction of the number of divisors.

Examples:

0, 0
1, 1
6, 2
16, 5
100, 19
100000, 7534

"""

from sympy import *

def divisor_steps(n):
    c = 0
    while n > 0:
        n -= len(divisors(n))
        c += 1
    return c

def main():
    assert(divisor_steps(0) == 0)
    assert(divisor_steps(1) == 1)
    assert(divisor_steps(6) == 2)
    assert(divisor_steps(16) == 5)
    assert(divisor_steps(100) == 19)
    assert(divisor_steps(100000) == 7534)

main()
