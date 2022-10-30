#!/usr/bin/env python

"""

Let us see the following equation,

ax+by=c

Given three positive integers a, b and c. You have to determine whether there exists at least one solution for some integers value of x and y where x, y may be negative or non-negative integers.

For example if a=2, b=4 and c=8 then the equation will be 2x+4y=8, and hence, for x=2 and y=1, there exists a solution.

Let us see another example for a=3, b=6 and c=7, so the equation will become 3x+6y=7 and there exists no solution satisfying this equation.

Input

Input starts with an integer T (1<=T<=10^5) denoting the number of test cases. Each test case contains three integers a, b, and c. (1<=a, b, c<=10^6).

Output

For each test case of input print the case number and “Yes” if there exists at least one solution, print “No” otherwise.

"""

import math

def solvable(a, b, c):
    return (c % math.gcd(a, b)) == 0

def main():
    assert(solvable(2, 4, 8) == True)
    assert(solvable(3, 6, 7) == False)

main()
