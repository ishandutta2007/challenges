#!/usr/bin/env python

"""

A Sphenic Number is a number that is the product of exactly three distinct primes. The first few Sphenic numbers are 30, 42, 66, 70, 78, 102, 105, 110, 114. This is sequence A007304 in the OEIS.

Your Task:
Write a program or function to determine whether an inputted integer is a Sphenic number.

Input:
An integer between 0 and 10^9, which may or may not be a Sphenic Number.

Output:
A truthy/falsy value indicating whether the input is a Sphenic Number.

Examples:
30  -> true
121 -> false
231 -> true
154 -> true
4   -> false
402 -> true
79  -> false
0   -> false
60  -> false
64  -> false
8   -> false
210 -> false

Scoring:
This is code-golf, shortest code in bytes wins.

"""

from sympy import *

# https://oeis.org/A007304
def sphenic(n):
    p = primefactors(n)
    return len(p) == 3 and prod(p) == n

def main():
    tab = [30, 42, 66, 70, 78, 102, 105, 110, 114, 130, 138, 154, 165, 170, 174, 182, 186, 190, 195, 222, 230, 231, 238, 246, 255, 258, 266, 273, 282, 285, 286, 290, 310, 318, 322, 345, 354, 357, 366, 370, 374, 385, 399, 402, 406, 410, 418, 426, 429, 430, 434, 435, 438]
    for i in range(max(tab)):
        if i in tab:
            assert(sphenic(i) == True)
        else:
            assert(sphenic(i) == False)

main()
