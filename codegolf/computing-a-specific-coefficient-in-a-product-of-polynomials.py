#!/usr/bin/env python

"""

Generator functions
This gives the context for why this challenge came to life. Feel free to ignore.

Generator functions are a nice way of encoding the solution to a problem of combinatorics. You just write some polynomials, multiply them and then your solution is the coefficient of one of the terms.

For example, how many bouquets of 10 flowers can you make if you want to use 3 or more dandelions, really want to use an even number of lilies and cannot afford more than 5 roses? Easy, just find the coefficient of x^10 in

(x^3+x^4+x^5+x^6+x^7+x^8+x^9+x^10)×(1+x^2+x^4+x^6+x^8+x^10)×(1+x+x^2+x^3+x^4+x^5)

Task
Compute a specific coefficient from a product of polynomials.

Example
If k = 3 and the product given is "(1 + 3x + 5x^2)(5 + 3x + 2x^2)" then we have

(1+3x+5x^2)(5+3x+2x^2)=(5+3x+2x^2)+(15x+9x^2+6x^3)+(25x^2+15x^3+10x^4)=5+18x+36x^2+21x^3+10x^4

And because k = 3 we get 21.

Input
You receive an integer k and several polynomials. k is always a non-negative integer, and so are the coefficients and the exponents in the input polynomials.

k may be larger than the combined degree of all the input polynomials.

The input polynomials can be in any sensible format. A few suggestions come to mind:

A string, like "(1 + 3x + 5x^2)(5 + 3x + 2x^2)"
A list of strings, like ["1 + 3x + 5x^2", "5 + 3x + 2x^2"]
A list of lists of coefficients where index encodes exponent, like [[1, 3, 5], [5, 3, 2]]
A list of lists of (coefficient, exponent) pairs, like [[(1, 0), (3, 1), (5, 2)], [(5, 0), (3, 1), (2, 2)]]
An input format must be sensible AND completely unambiguous over the input space.

Test cases
0, "(1 + 3x + 5x^2)(5 + 3x + 2x^2)" -> 5
1, "(1 + 3x + 5x^2)(5 + 3x + 2x^2)" -> 18
2, "(1 + 3x + 5x^2)(5 + 3x + 2x^2)" -> 36
3, "(1 + 3x + 5x^2)(5 + 3x + 2x^2)" -> 21
4, "(1 + 3x + 5x^2)(5 + 3x + 2x^2)" -> 10
5, "(1 + 3x + 5x^2)(5 + 3x + 2x^2)" -> 0
6, "(1 + 2x^2 + 4x^4)(2x^2 + 4x^4 + 8x^8)(4x^4 + 8x^8 + 16x^16)" -> 8
7, "(1 + 2x^2 + 4x^4)(2x^2 + 4x^4 + 8x^8)(4x^4 + 8x^8 + 16x^16)" -> 0
8, "(1 + 2x^2 + 4x^4)(2x^2 + 4x^4 + 8x^8)(4x^4 + 8x^8 + 16x^16)" -> 32
9, "(1 + 2x^2 + 4x^4)(2x^2 + 4x^4 + 8x^8)(4x^4 + 8x^8 + 16x^16)" -> 0
17, "(1 + 2x^2 + 4x^4)(2x^2 + 4x^4 + 8x^8)(4x^4 + 8x^8 + 16x^16)" -> 0
18, "(1 + 2x^2 + 4x^4)(2x^2 + 4x^4 + 8x^8)(4x^4 + 8x^8 + 16x^16)" -> 160
19, "(1 + 2x^2 + 4x^4)(2x^2 + 4x^4 + 8x^8)(4x^4 + 8x^8 + 16x^16)" -> 0
20, "(1 + 2x^2 + 4x^4)(2x^2 + 4x^4 + 8x^8)(4x^4 + 8x^8 + 16x^16)" -> 384

"""

from sympy import *
from sympy.parsing.sympy_parser import *
from sympy.abc import *

def coeff(term, equation):
    equation = equation.replace("^", "**")
    transformations = (standard_transformations + (implicit_multiplication_application,))
    expr = parse_expr(equation, transformations=transformations)
    expr = Poly(expand(expr))
    coeffs = expr.all_coeffs()
    if term < 0 or term >= len(coeffs):
        return 0
    return coeffs[len(coeffs)-term-1]

def main():
    assert(coeff(0, "(1 + 3x + 5x^2)(5 + 3x + 2x^2)") == 5)
    assert(coeff(1, "(1 + 3x + 5x^2)(5 + 3x + 2x^2)") == 18)
    assert(coeff(2, "(1 + 3x + 5x^2)(5 + 3x + 2x^2)") == 36)
    assert(coeff(3, "(1 + 3x + 5x^2)(5 + 3x + 2x^2)") == 21)
    assert(coeff(4, "(1 + 3x + 5x^2)(5 + 3x + 2x^2)") == 10)
    assert(coeff(5, "(1 + 3x + 5x^2)(5 + 3x + 2x^2)") == 0)
    assert(coeff(6, "(1 + 2x^2 + 4x^4)(2x^2 + 4x^4 + 8x^8)(4x^4 + 8x^8 + 16x^16)") == 8)
    assert(coeff(7, "(1 + 2x^2 + 4x^4)(2x^2 + 4x^4 + 8x^8)(4x^4 + 8x^8 + 16x^16)") == 0)
    assert(coeff(8, "(1 + 2x^2 + 4x^4)(2x^2 + 4x^4 + 8x^8)(4x^4 + 8x^8 + 16x^16)") == 32)
    assert(coeff(9, "(1 + 2x^2 + 4x^4)(2x^2 + 4x^4 + 8x^8)(4x^4 + 8x^8 + 16x^16)") == 0)
    assert(coeff(17, "(1 + 2x^2 + 4x^4)(2x^2 + 4x^4 + 8x^8)(4x^4 + 8x^8 + 16x^16)") == 0)
    assert(coeff(18, "(1 + 2x^2 + 4x^4)(2x^2 + 4x^4 + 8x^8)(4x^4 + 8x^8 + 16x^16)") == 160)
    assert(coeff(19, "(1 + 2x^2 + 4x^4)(2x^2 + 4x^4 + 8x^8)(4x^4 + 8x^8 + 16x^16)") == 0)
    assert(coeff(20, "(1 + 2x^2 + 4x^4)(2x^2 + 4x^4 + 8x^8)(4x^4 + 8x^8 + 16x^16)") == 384)

main()
