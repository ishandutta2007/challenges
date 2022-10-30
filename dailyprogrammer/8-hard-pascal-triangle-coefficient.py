#!/usr/bin/env python

"""

Write a program that will take coordinates, and tell you the corresponding number in pascals triangle. For example:

Input: 1, 1

output:1

input: 4, 2

output: 3

input: 1, 19

output: error/nonexistent/whatever

the format should be "line number, integer number"

for extra credit, add a function to simply print the triangle, for the extra credit to count, it must print at least 15 lines.

"""

from sympy import *

def coeff(n, m):
    return binomial(n-1, m-1)

def main():
    assert(coeff(1, 1) == 1)
    assert(coeff(4, 2) == 3)
    assert(coeff(1, 19) == 0)

    for i in range(1, 20):
        for j in range(1, i+1):
            print(coeff(i, j), end=' ')
        print()

main()
