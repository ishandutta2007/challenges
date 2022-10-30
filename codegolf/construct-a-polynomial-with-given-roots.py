#!/usr/bin/env python

"""

The challenge is to write the shortest function/program to find a polynomial given the roots. The function or program should take valid input; that is, a list of integers representing the roots of the polynomial, and return valid output.

Output should return a sequence of numbers representing the polynomial. For example:

2, 3 represents 2x^1 - 3x^0 = 0

1, 6, 1, 8, 0, 3, 3 represents 1x^6 + 6x^5 + 1x^4 + 8x^3 + 0x^2 + 3x^1 + 3x^0 = 0

-1 0 5, -3 represents -1x^3 + 0x^2 + 5x^1 + -3x^0 = 0

I hope you get the idea.

Example Usage

For an input of 1, 2, the output should be 1, -3, 2, which represents the equation 1x^2 + -3x^1 + 2x^0 = 0, or x^2 - 3x + 2 = 0.

For an input of 1, -1, 0, the output should be 1, 0, -1, 0.

For the input, duplicate values should be removed and order does not matter. For example, the result with input 3, 3, 6 should be the same as the result with input 6, 3.

Float arguments are optional.

As this is code golf, the shortest entry in characters wins. Good luck!

"""

from sympy import *
from sympy.abc import *

def polynomial(l):
    l = list(set(l))
    if len(l) == 0:
        return []
    p = 1
    for r in l:
        p *= (x-r)
    return Poly(p, x).all_coeffs()

def main():
    assert(polynomial([1, 2]) == [1, -3, 2])
    assert(polynomial([1, -1, 0]) == [1, 0, -1, 0])
    assert(polynomial([3, 3, 6]) == polynomial([6, 3]))

main()
