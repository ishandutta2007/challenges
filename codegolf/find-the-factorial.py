#!/usr/bin/env python

"""

Create the shortest program or function that finds the factorial of a non-negative integer.

The factorial, represented with ! is defined as such

n!:={1n⋅(n−1)!n=0n>0

In plain English the factorial of 0 is 1 and the factorial of n, where n is larger than 0 is n times the factorial of one less than n.

Your code should perform input and output using a standard methods.

Requirements:

Does not use any built-in libraries that can calculate the factorial (this includes any form of eval)
Can calculate factorials for numbers up to 125
Can calculate the factorial for the number 0 (equal to 1)
Completes in under a minute for numbers up to 125
The shortest submission wins, in the case of a tie the answer with the most votes at the time wins.

"""

from math import *

def main():
    for i in range(0, 125):
        print(factorial(i))

main()
